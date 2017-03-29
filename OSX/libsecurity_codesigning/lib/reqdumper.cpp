/*
 * Copyright (c) 2006-2007,2011-2013 Apple Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

//
// reqdumper - Requirement un-parsing (disassembly)
//
#include "reqdumper.h"
#include <security_cdsa_utilities/cssmdata.h>	// OID encoder
#include <cstdarg>

namespace Security {
namespace CodeSigning {

using namespace UnixPlusPlus;


//
// Table of reserved words (keywords), generated by ANTLR
//
static const char * const keywords[] = {
#include "RequirementKeywords.h"
	"",
	NULL
};


//
// Printf to established output channel
//
void Dumper::print(const char *format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);
	mOutput += buffer;
}


//
// Dump the underlying Requirement program
//
void Dumper::dump()
{
	this->expr();
	
	// remove any initial space
	if (mOutput[0] == ' ')
		mOutput = mOutput.substr(1);
}


//
// Dump an entire Requirements set, using temporary Dumper objects.
//
// This detects single Requirement inputs and dumps them successfully (using
// single-requirement syntax). No indication of error is returned in this case.
//
string Dumper::dump(const Requirements *reqs, bool debug /* = false */)
{
	if (!reqs) {
		return "# no requirement(s)";
	} else if (reqs->magic() == Requirement::typeMagic) {	// single requirement
		return dump((const Requirement *)reqs) + "\n";
	} else {
		string result;
		for (unsigned n = 0; n < reqs->count(); n++) {
			char prefix[200];
			if (reqs->type(n) < kSecRequirementTypeCount)
				snprintf(prefix, sizeof(prefix),
					"%s => ", Requirement::typeNames[reqs->type(n)]);
			else
				snprintf(prefix, sizeof(prefix), "/*unknown type*/ %d => ", reqs->type(n));
			Dumper dumper(reqs->blob<Requirement>(n), debug);
			dumper.expr();
			result += prefix + dumper.value() + "\n";
		}
		return result;
	}
}

string Dumper::dump(const Requirement *req, bool debug /* = false */)
{
	Dumper dumper(req, debug);
	try {
		dumper.dump();
		return dumper;
	} catch (const CommonError &err) {
		if (debug) {
			char errstr[80];
			snprintf(errstr, sizeof(errstr), " !! error %ld !!", (unsigned long)err.osStatus());
			return dumper.value() + errstr;
		}
		throw;
	}
}

string Dumper::dump(const BlobCore *req, bool debug /* = false */)
{
	switch (req->magic()) {
	case Requirement::typeMagic:
		return dump(static_cast<const Requirement *>(req), debug);
	case Requirements::typeMagic:
		return dump(static_cast<const Requirements *>(req), debug);
	default:
		return "invalid data type";
	}
}


//
// Element dumpers. Output accumulates in internal buffer.
//
void Dumper::expr(SyntaxLevel level)
{
	if (mDebug)
		print("/*@0x%x*/", pc());
	ExprOp op = ExprOp(get<uint32_t>());
	switch (op & ~opFlagMask) {
	case opFalse:
		print("never");
		break;
	case opTrue:
		print("always");
		break;
	case opIdent:
		print("identifier ");
		data();
		break;
	case opAppleAnchor:
		print("anchor apple");
		break;
	case opAppleGenericAnchor:
		print("anchor apple generic");
		break;
	case opAnchorHash:
		print("certificate"); certSlot(); print(" = "); hashData();
		break;
	case opInfoKeyValue:
		if (mDebug)
			print("/*legacy*/");
		print("info["); dotString(); print("] = "); data();
		break;
	case opAnd:
		if (level < slAnd)
			print("(");
		expr(slAnd);
		print(" and ");
		expr(slAnd);
		if (level < slAnd)
			print(")");
		break;
	case opOr:
		if (level < slOr)
			print("(");
		expr(slOr);
		print(" or ");
		expr(slOr);
		if (level < slOr)
			print(")");
		break;
	case opNot:
		print("! ");
		expr(slPrimary);
		break;
	case opCDHash:
		print("cdhash ");
		hashData();
		break;
	case opInfoKeyField:
		print("info["); dotString(); print("]"); match();
		break;
	case opEntitlementField:
		print("entitlement["); dotString(); print("]"); match();
		break;
	case opCertField:
		print("certificate"); certSlot(); print("["); dotString(); print("]"); match();
		break;
	case opCertGeneric:
		print("certificate"); certSlot(); print("[");
		{
			const unsigned char *data; size_t length;
			getData(data, length);
			print("field.%s", CssmOid((unsigned char *)data, length).toOid().c_str());
		}
		print("]"); match();
		break;
	case opCertPolicy:
		print("certificate"); certSlot(); print("[");
		{
			const unsigned char *data; size_t length;
			getData(data, length);
			print("policy.%s", CssmOid((unsigned char *)data, length).toOid().c_str());
		}
		print("]"); match();
		break;
	case opTrustedCert:
		print("certificate"); certSlot(); print("trusted");
		break;
	case opTrustedCerts:
		print("anchor trusted");
		break;
	case opNamedAnchor:
		print("anchor apple "); data();
		break;
	case opNamedCode:
		print("("); data(); print(")");
		break;
	case opPlatform:
		print("platform = %d", get<int32_t>());
		break;
	default:
		if (op & opGenericFalse) {
			print(" false /* opcode %d */", op & ~opFlagMask);
			break;
		} else if (op & opGenericSkip) {
			print(" /* opcode %d */", op & ~opFlagMask);
			break;
		} else {
			print("OPCODE %d NOT UNDERSTOOD (ending print)", op);
			return;
		}
	}
}

void Dumper::certSlot()
{
	switch (int32_t slot = get<int32_t>()) {
	case Requirement::anchorCert:
		print(" root");
		break;
	case Requirement::leafCert:
		print(" leaf");
		break;
	default:
		print(" %d", slot);
		break; 
	}
}

void Dumper::match()
{
	switch (MatchOperation op = MatchOperation(get<uint32_t>())) {
	case matchExists:
		print(" /* exists */");
		break;
	case matchEqual:
		print(" = "); data();
		break;
	case matchContains:
		print(" ~ "); data();
		break;
	case matchBeginsWith:
		print(" = "); data(); print("*");
		break;
	case matchEndsWith:
		print(" = *"); data();
		break;
	case matchLessThan:
		print(" < "); data();
		break;
	case matchGreaterEqual:
		print(" >= "); data();
		break;
	case matchLessEqual:
		print(" <= "); data();
		break;
	case matchGreaterThan:
		print(" > "); data();
		break;
	default:
		print("MATCH OPCODE %d NOT UNDERSTOOD", op);
		break;
	}
}

void Dumper::hashData()
{
	print("H\"");
	const unsigned char *data; size_t length;
	getData(data, length);
	printBytes(data, length);
	print("\"");
}

void Dumper::data(PrintMode bestMode /* = isSimple */, bool dotOkay /* = false */)
{
	const unsigned char *data; size_t length;
	getData(data, length);
	for (unsigned n = 0; n < length; n++)
		if ((isalnum(data[n]) || (data[n] == '.' && dotOkay))) {	// simple
			if (n == 0 && isdigit(data[n]))	// unquoted idents can't start with a digit
				bestMode = isPrintable;
		} else if (isgraph(data[n]) || isspace(data[n])) {
			if (bestMode == isSimple)
				bestMode = isPrintable;
		} else {
			bestMode = isBinary;
			break;		// pessimal
		}
	
	if (bestMode == isSimple) {
		string s((const char *)data, length);
		for (const char * const * k = keywords; *k; k++)
			if (s == *k) {
				bestMode = isPrintable;		// reserved word; need quotes
				break;
			}
	}
		
	switch (bestMode) {
	case isSimple:
		print("%.*s", length, data);
		break;
	case isPrintable:
		print("\"");
		for (unsigned n = 0; n < length; n++)
			switch (data[n]) {
			case '\\':
			case '"':
				print("\\%c", data[n]);
				break;
			default:
				print("%c", data[n]);
				break;
			}
		print("\"");
		break;
	default:
		print("0x");
		printBytes(data, length);
		break;
	}
}

void Dumper::printBytes(const Byte *data, size_t length)
{
	for (unsigned n = 0; n < length; n++)
		print("%02.2x", data[n]);
}


}	// CodeSigning
}	// Security
