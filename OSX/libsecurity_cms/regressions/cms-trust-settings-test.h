/*
 * Copyright (c) 2016 Apple Inc. All Rights Reserved.
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

#ifndef cms_trust_settings_test_h
#define cms_trust_settings_test_h

#include <stdio.h>

int cms_trust_settings_test(int argc, char *const *argv);

unsigned char _cert[] = {
    0x30,0x82,0x03,0xE1,0x30,0x82,0x02,0xC9,0xA0,0x03,0x02,0x01,0x02,0x02,0x04,0x74,
    0x3F,0x1D,0x98,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,
    0x05,0x00,0x30,0x81,0xA7,0x31,0x1A,0x30,0x18,0x06,0x03,0x55,0x04,0x03,0x0C,0x11,
    0x43,0x4D,0x53,0x20,0x52,0x53,0x41,0x20,0x54,0x65,0x73,0x74,0x20,0x43,0x65,0x72,
    0x74,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x14,
    0x30,0x12,0x06,0x03,0x55,0x04,0x0A,0x0C,0x0B,0x41,0x70,0x70,0x6C,0x65,0x2C,0x20,
    0x49,0x6E,0x63,0x2E,0x31,0x2E,0x30,0x2C,0x06,0x03,0x55,0x04,0x0B,0x0C,0x25,0x53,
    0x65,0x63,0x75,0x72,0x69,0x74,0x79,0x20,0x45,0x6E,0x67,0x69,0x6E,0x65,0x65,0x72,
    0x69,0x6E,0x67,0x20,0x61,0x6E,0x64,0x20,0x41,0x72,0x63,0x68,0x69,0x74,0x65,0x63,
    0x74,0x75,0x72,0x65,0x31,0x13,0x30,0x11,0x06,0x03,0x55,0x04,0x08,0x0C,0x0A,0x43,
    0x61,0x6C,0x69,0x66,0x6F,0x72,0x6E,0x69,0x61,0x31,0x21,0x30,0x1F,0x06,0x09,0x2A,
    0x86,0x48,0x86,0xF7,0x0D,0x01,0x09,0x01,0x16,0x12,0x75,0x73,0x65,0x72,0x6E,0x61,
    0x6D,0x65,0x40,0x61,0x70,0x70,0x6C,0x65,0x2E,0x63,0x6F,0x6D,0x30,0x1E,0x17,0x0D,
    0x31,0x36,0x30,0x33,0x31,0x34,0x30,0x30,0x31,0x38,0x32,0x39,0x5A,0x17,0x0D,0x31,
    0x36,0x30,0x34,0x31,0x33,0x30,0x30,0x31,0x38,0x32,0x39,0x5A,0x30,0x81,0xA7,0x31,
    0x1A,0x30,0x18,0x06,0x03,0x55,0x04,0x03,0x0C,0x11,0x43,0x4D,0x53,0x20,0x52,0x53,
    0x41,0x20,0x54,0x65,0x73,0x74,0x20,0x43,0x65,0x72,0x74,0x31,0x0B,0x30,0x09,0x06,
    0x03,0x55,0x04,0x06,0x13,0x02,0x55,0x53,0x31,0x14,0x30,0x12,0x06,0x03,0x55,0x04,
    0x0A,0x0C,0x0B,0x41,0x70,0x70,0x6C,0x65,0x2C,0x20,0x49,0x6E,0x63,0x2E,0x31,0x2E,
    0x30,0x2C,0x06,0x03,0x55,0x04,0x0B,0x0C,0x25,0x53,0x65,0x63,0x75,0x72,0x69,0x74,
    0x79,0x20,0x45,0x6E,0x67,0x69,0x6E,0x65,0x65,0x72,0x69,0x6E,0x67,0x20,0x61,0x6E,
    0x64,0x20,0x41,0x72,0x63,0x68,0x69,0x74,0x65,0x63,0x74,0x75,0x72,0x65,0x31,0x13,
    0x30,0x11,0x06,0x03,0x55,0x04,0x08,0x0C,0x0A,0x43,0x61,0x6C,0x69,0x66,0x6F,0x72,
    0x6E,0x69,0x61,0x31,0x21,0x30,0x1F,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,
    0x09,0x01,0x16,0x12,0x75,0x73,0x65,0x72,0x6E,0x61,0x6D,0x65,0x40,0x61,0x70,0x70,
    0x6C,0x65,0x2E,0x63,0x6F,0x6D,0x30,0x82,0x01,0x22,0x30,0x0D,0x06,0x09,0x2A,0x86,
    0x48,0x86,0xF7,0x0D,0x01,0x01,0x01,0x05,0x00,0x03,0x82,0x01,0x0F,0x00,0x30,0x82,
    0x01,0x0A,0x02,0x82,0x01,0x01,0x00,0xE2,0x9B,0xCB,0x6C,0x77,0xB7,0xD1,0x05,0xA0,
    0xAE,0x86,0x20,0x45,0xD3,0xF4,0x24,0x8D,0x25,0x34,0x31,0xA9,0xE2,0x10,0x36,0xF5,
    0x0A,0x0B,0x90,0x4A,0xA5,0x6B,0x5C,0x16,0xCD,0xB0,0x72,0xE9,0xA9,0x80,0x5F,0x6D,
    0xB2,0x4D,0xD9,0x58,0x16,0x9F,0x68,0x81,0x9A,0x6B,0xEB,0xD5,0x4B,0xF7,0x7D,0x59,
    0xE9,0x46,0x2B,0x5B,0x8F,0xE4,0xEC,0xAB,0x5C,0x07,0x74,0xA2,0x0E,0x59,0xBB,0xFC,
    0xD3,0xCF,0xF7,0x21,0x88,0x6C,0x88,0xD9,0x6B,0xA3,0xA3,0x4E,0x5B,0xD1,0x1C,0xFB,
    0x04,0xF5,0xB2,0x12,0x0E,0x54,0x59,0x4D,0xCE,0x0A,0xE0,0x26,0x24,0x06,0xEB,0xC8,
    0xA2,0xC6,0x41,0x28,0xF9,0x79,0xE4,0xB1,0x4E,0x00,0x6F,0x6E,0xF8,0x96,0x9E,0x45,
    0x28,0x70,0xEC,0xC7,0xDC,0xA2,0xDD,0x92,0xAB,0xDD,0x6F,0xD8,0x57,0xBA,0xCC,0x29,
    0xBE,0xB7,0x00,0x1E,0x8D,0x13,0x3F,0x47,0x34,0x3C,0xD0,0xC6,0xC8,0x17,0xDF,0x74,
    0x8A,0xB1,0xC3,0x68,0xD5,0xBA,0x76,0x60,0x55,0x5F,0x8D,0xFA,0xBD,0xE7,0x11,0x9E,
    0x59,0x96,0xE5,0x93,0x70,0xAD,0x41,0xFB,0x61,0x46,0x70,0xC4,0x05,0x12,0x23,0x23,
    0xC0,0x9D,0xC8,0xC5,0xF5,0x96,0xE5,0x48,0x10,0x86,0x8A,0x1E,0x3B,0x83,0xD1,0x47,
    0x3A,0x27,0x00,0x71,0x10,0xA3,0x52,0xBA,0xAE,0x01,0x43,0x87,0x9C,0x6A,0x1B,0xEA,
    0x1A,0x44,0x4F,0x4A,0xAC,0xD4,0x82,0x55,0xEE,0x1F,0x25,0x9C,0x55,0xCA,0xD2,0xD0,
    0x3A,0x0B,0x70,0x90,0x60,0x49,0x47,0x02,0xFD,0x89,0x2C,0x9A,0x26,0x36,0x34,0x8F,
    0x24,0x39,0x8C,0xE9,0xA2,0x52,0x8F,0x02,0x03,0x01,0x00,0x01,0xA3,0x13,0x30,0x11,
    0x30,0x0F,0x06,0x03,0x55,0x1D,0x13,0x01,0x01,0xFF,0x04,0x05,0x30,0x03,0x01,0x01,
    0xFF,0x30,0x0D,0x06,0x09,0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B,0x05,0x00,
    0x03,0x82,0x01,0x01,0x00,0x4C,0xED,0x5B,0xAF,0x13,0x16,0x5D,0xE2,0xDD,0x5C,0x48,
    0x1C,0xD5,0x6E,0x8B,0x04,0x51,0xD6,0x38,0x80,0xFD,0x52,0x4A,0x34,0xDC,0x13,0x35,
    0x6E,0x64,0x39,0x39,0x39,0x09,0xA7,0x6C,0x2D,0x39,0xF2,0x04,0x21,0xE3,0xEA,0x8F,
    0xF8,0xBE,0x46,0x0E,0x20,0x82,0xD0,0xC5,0x60,0xBF,0x57,0x6F,0xD8,0x29,0xB4,0x66,
    0xDB,0xBF,0x92,0xC9,0xDC,0x90,0x97,0x0F,0x2F,0x59,0xA0,0x13,0xF3,0xA4,0xCA,0xDE,
    0x3F,0x80,0x2A,0x99,0xB4,0xEE,0x71,0xC3,0x56,0x71,0x51,0x37,0x55,0xA1,0x60,0x89,
    0xAB,0x94,0x0E,0xB9,0x70,0xA5,0x55,0xF3,0x1A,0x87,0xA4,0x41,0x4C,0x45,0xBA,0xB6,
    0x56,0xD6,0x45,0x56,0x12,0x60,0xE5,0x91,0xEC,0xF7,0xBE,0x39,0xA4,0x80,0x08,0x9F,
    0xEA,0x17,0x12,0x0E,0xA6,0xE6,0xEF,0x09,0xF7,0x61,0x51,0x57,0x73,0xE3,0x57,0x88,
    0xD7,0xF8,0x5F,0xAF,0x5D,0xAF,0x88,0x32,0xB4,0x09,0x3E,0x7C,0x25,0x77,0x35,0xE9,
    0x3E,0x6E,0x0A,0xB9,0xB4,0xA3,0x06,0x07,0x0F,0x7E,0x93,0x26,0x16,0x38,0x1E,0x4E,
    0x72,0xAF,0x06,0x44,0x1E,0x8D,0x96,0xA6,0x15,0x9C,0x82,0x6D,0x71,0x99,0x84,0x8D,
    0x12,0x46,0xF2,0xBB,0xA7,0x63,0x7A,0x32,0xDA,0xA9,0xDE,0xB6,0x34,0x14,0xFB,0x07,
    0x0C,0xAB,0x3B,0x0A,0xA1,0x8B,0xDA,0x15,0xB3,0x63,0xF3,0x5C,0x45,0x2F,0x0B,0x6E,
    0xC7,0x27,0x72,0xC1,0x37,0x56,0x30,0xE3,0x26,0xBB,0x19,0x4F,0x91,0xA1,0xD0,0x30,
    0x29,0x5B,0x79,0x79,0x5C,0xE6,0x4F,0xED,0xCF,0x81,0xB2,0x50,0x35,0x96,0x23,0xB2,
    0x9F,0xCA,0x3F,0xB5,0x54,
};

unsigned char _signed_message[] = {
    0x30, 0x80, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x80, 0x30, 0x80, 0x02, 0x01, 0x01,
    0x31, 0x0f, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x30, 0x80, 0x06,
    0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0xa0, 0x80, 0x24, 0x80, 0x04, 0x29, 0x54, 0x68, 0x69, 0x73,
    0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x69, 0x73, 0x20, 0x73, 0x69, 0x67, 0x6e, 0x65, 0x64, 0x2e, 0x20,
    0x41, 0x69, 0x6e, 0x27, 0x74, 0x20, 0x69, 0x74, 0x20, 0x70, 0x72, 0x65, 0x74, 0x74, 0x79, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xa0, 0x82, 0x03, 0xe5, 0x30, 0x82, 0x03, 0xe1, 0x30, 0x82, 0x02, 0xc9, 0xa0, 0x03, 0x02, 0x01, 0x02,
    0x02, 0x04, 0x74, 0x3f, 0x1d, 0x98, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05,
    0x00, 0x30, 0x81, 0xa7, 0x31, 0x1a, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x11, 0x43, 0x4d, 0x53, 0x20, 0x52,
    0x53, 0x41, 0x20, 0x54, 0x65, 0x73, 0x74, 0x20, 0x43, 0x65, 0x72, 0x74, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
    0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0b, 0x41, 0x70, 0x70, 0x6c,
    0x65, 0x2c, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x2e, 0x30, 0x2c, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x25, 0x53, 0x65,
    0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 0x45, 0x6e, 0x67, 0x69, 0x6e, 0x65, 0x65, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x61,
    0x6e, 0x64, 0x20, 0x41, 0x72, 0x63, 0x68, 0x69, 0x74, 0x65, 0x63, 0x74, 0x75, 0x72, 0x65, 0x31, 0x13, 0x30, 0x11, 0x06,
    0x03, 0x55, 0x04, 0x08, 0x0c, 0x0a, 0x43, 0x61, 0x6c, 0x69, 0x66, 0x6f, 0x72, 0x6e, 0x69, 0x61, 0x31, 0x21, 0x30, 0x1f,
    0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x12, 0x75, 0x73, 0x65, 0x72, 0x6e, 0x61, 0x6d,
    0x65, 0x40, 0x61, 0x70, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x36, 0x30, 0x33, 0x31,
    0x34, 0x30, 0x30, 0x31, 0x38, 0x32, 0x39, 0x5a, 0x17, 0x0d, 0x31, 0x36, 0x30, 0x34, 0x31, 0x33, 0x30, 0x30, 0x31, 0x38,
    0x32, 0x39, 0x5a, 0x30, 0x81, 0xa7, 0x31, 0x1a, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x11, 0x43, 0x4d, 0x53,
    0x20, 0x52, 0x53, 0x41, 0x20, 0x54, 0x65, 0x73, 0x74, 0x20, 0x43, 0x65, 0x72, 0x74, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03,
    0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0b, 0x41, 0x70,
    0x70, 0x6c, 0x65, 0x2c, 0x20, 0x49, 0x6e, 0x63, 0x2e, 0x31, 0x2e, 0x30, 0x2c, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x25,
    0x53, 0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 0x45, 0x6e, 0x67, 0x69, 0x6e, 0x65, 0x65, 0x72, 0x69, 0x6e, 0x67,
    0x20, 0x61, 0x6e, 0x64, 0x20, 0x41, 0x72, 0x63, 0x68, 0x69, 0x74, 0x65, 0x63, 0x74, 0x75, 0x72, 0x65, 0x31, 0x13, 0x30,
    0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c, 0x0a, 0x43, 0x61, 0x6c, 0x69, 0x66, 0x6f, 0x72, 0x6e, 0x69, 0x61, 0x31, 0x21,
    0x30, 0x1f, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x12, 0x75, 0x73, 0x65, 0x72, 0x6e,
    0x61, 0x6d, 0x65, 0x40, 0x61, 0x70, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x30, 0x82, 0x01, 0x22, 0x30, 0x0d, 0x06,
    0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01,
    0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xe2, 0x9b, 0xcb, 0x6c, 0x77, 0xb7, 0xd1, 0x05, 0xa0, 0xae, 0x86, 0x20, 0x45, 0xd3,
    0xf4, 0x24, 0x8d, 0x25, 0x34, 0x31, 0xa9, 0xe2, 0x10, 0x36, 0xf5, 0x0a, 0x0b, 0x90, 0x4a, 0xa5, 0x6b, 0x5c, 0x16, 0xcd,
    0xb0, 0x72, 0xe9, 0xa9, 0x80, 0x5f, 0x6d, 0xb2, 0x4d, 0xd9, 0x58, 0x16, 0x9f, 0x68, 0x81, 0x9a, 0x6b, 0xeb, 0xd5, 0x4b,
    0xf7, 0x7d, 0x59, 0xe9, 0x46, 0x2b, 0x5b, 0x8f, 0xe4, 0xec, 0xab, 0x5c, 0x07, 0x74, 0xa2, 0x0e, 0x59, 0xbb, 0xfc, 0xd3,
    0xcf, 0xf7, 0x21, 0x88, 0x6c, 0x88, 0xd9, 0x6b, 0xa3, 0xa3, 0x4e, 0x5b, 0xd1, 0x1c, 0xfb, 0x04, 0xf5, 0xb2, 0x12, 0x0e,
    0x54, 0x59, 0x4d, 0xce, 0x0a, 0xe0, 0x26, 0x24, 0x06, 0xeb, 0xc8, 0xa2, 0xc6, 0x41, 0x28, 0xf9, 0x79, 0xe4, 0xb1, 0x4e,
    0x00, 0x6f, 0x6e, 0xf8, 0x96, 0x9e, 0x45, 0x28, 0x70, 0xec, 0xc7, 0xdc, 0xa2, 0xdd, 0x92, 0xab, 0xdd, 0x6f, 0xd8, 0x57,
    0xba, 0xcc, 0x29, 0xbe, 0xb7, 0x00, 0x1e, 0x8d, 0x13, 0x3f, 0x47, 0x34, 0x3c, 0xd0, 0xc6, 0xc8, 0x17, 0xdf, 0x74, 0x8a,
    0xb1, 0xc3, 0x68, 0xd5, 0xba, 0x76, 0x60, 0x55, 0x5f, 0x8d, 0xfa, 0xbd, 0xe7, 0x11, 0x9e, 0x59, 0x96, 0xe5, 0x93, 0x70,
    0xad, 0x41, 0xfb, 0x61, 0x46, 0x70, 0xc4, 0x05, 0x12, 0x23, 0x23, 0xc0, 0x9d, 0xc8, 0xc5, 0xf5, 0x96, 0xe5, 0x48, 0x10,
    0x86, 0x8a, 0x1e, 0x3b, 0x83, 0xd1, 0x47, 0x3a, 0x27, 0x00, 0x71, 0x10, 0xa3, 0x52, 0xba, 0xae, 0x01, 0x43, 0x87, 0x9c,
    0x6a, 0x1b, 0xea, 0x1a, 0x44, 0x4f, 0x4a, 0xac, 0xd4, 0x82, 0x55, 0xee, 0x1f, 0x25, 0x9c, 0x55, 0xca, 0xd2, 0xd0, 0x3a,
    0x0b, 0x70, 0x90, 0x60, 0x49, 0x47, 0x02, 0xfd, 0x89, 0x2c, 0x9a, 0x26, 0x36, 0x34, 0x8f, 0x24, 0x39, 0x8c, 0xe9, 0xa2,
    0x52, 0x8f, 0x02, 0x03, 0x01, 0x00, 0x01, 0xa3, 0x13, 0x30, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01,
    0xff, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
    0x0b, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x4c, 0xed, 0x5b, 0xaf, 0x13, 0x16, 0x5d, 0xe2, 0xdd, 0x5c, 0x48, 0x1c,
    0xd5, 0x6e, 0x8b, 0x04, 0x51, 0xd6, 0x38, 0x80, 0xfd, 0x52, 0x4a, 0x34, 0xdc, 0x13, 0x35, 0x6e, 0x64, 0x39, 0x39, 0x39,
    0x09, 0xa7, 0x6c, 0x2d, 0x39, 0xf2, 0x04, 0x21, 0xe3, 0xea, 0x8f, 0xf8, 0xbe, 0x46, 0x0e, 0x20, 0x82, 0xd0, 0xc5, 0x60,
    0xbf, 0x57, 0x6f, 0xd8, 0x29, 0xb4, 0x66, 0xdb, 0xbf, 0x92, 0xc9, 0xdc, 0x90, 0x97, 0x0f, 0x2f, 0x59, 0xa0, 0x13, 0xf3,
    0xa4, 0xca, 0xde, 0x3f, 0x80, 0x2a, 0x99, 0xb4, 0xee, 0x71, 0xc3, 0x56, 0x71, 0x51, 0x37, 0x55, 0xa1, 0x60, 0x89, 0xab,
    0x94, 0x0e, 0xb9, 0x70, 0xa5, 0x55, 0xf3, 0x1a, 0x87, 0xa4, 0x41, 0x4c, 0x45, 0xba, 0xb6, 0x56, 0xd6, 0x45, 0x56, 0x12,
    0x60, 0xe5, 0x91, 0xec, 0xf7, 0xbe, 0x39, 0xa4, 0x80, 0x08, 0x9f, 0xea, 0x17, 0x12, 0x0e, 0xa6, 0xe6, 0xef, 0x09, 0xf7,
    0x61, 0x51, 0x57, 0x73, 0xe3, 0x57, 0x88, 0xd7, 0xf8, 0x5f, 0xaf, 0x5d, 0xaf, 0x88, 0x32, 0xb4, 0x09, 0x3e, 0x7c, 0x25,
    0x77, 0x35, 0xe9, 0x3e, 0x6e, 0x0a, 0xb9, 0xb4, 0xa3, 0x06, 0x07, 0x0f, 0x7e, 0x93, 0x26, 0x16, 0x38, 0x1e, 0x4e, 0x72,
    0xaf, 0x06, 0x44, 0x1e, 0x8d, 0x96, 0xa6, 0x15, 0x9c, 0x82, 0x6d, 0x71, 0x99, 0x84, 0x8d, 0x12, 0x46, 0xf2, 0xbb, 0xa7,
    0x63, 0x7a, 0x32, 0xda, 0xa9, 0xde, 0xb6, 0x34, 0x14, 0xfb, 0x07, 0x0c, 0xab, 0x3b, 0x0a, 0xa1, 0x8b, 0xda, 0x15, 0xb3,
    0x63, 0xf3, 0x5c, 0x45, 0x2f, 0x0b, 0x6e, 0xc7, 0x27, 0x72, 0xc1, 0x37, 0x56, 0x30, 0xe3, 0x26, 0xbb, 0x19, 0x4f, 0x91,
    0xa1, 0xd0, 0x30, 0x29, 0x5b, 0x79, 0x79, 0x5c, 0xe6, 0x4f, 0xed, 0xcf, 0x81, 0xb2, 0x50, 0x35, 0x96, 0x23, 0xb2, 0x9f,
    0xca, 0x3f, 0xb5, 0x54, 0x31, 0x82, 0x01, 0xdc, 0x30, 0x82, 0x01, 0xd8, 0x02, 0x01, 0x01, 0x30, 0x81, 0xb0, 0x30, 0x81,
    0xa7, 0x31, 0x1a, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x11, 0x43, 0x4d, 0x53, 0x20, 0x52, 0x53, 0x41, 0x20,
    0x54, 0x65, 0x73, 0x74, 0x20, 0x43, 0x65, 0x72, 0x74, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
    0x55, 0x53, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x0b, 0x41, 0x70, 0x70, 0x6c, 0x65, 0x2c, 0x20,
    0x49, 0x6e, 0x63, 0x2e, 0x31, 0x2e, 0x30, 0x2c, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x25, 0x53, 0x65, 0x63, 0x75, 0x72,
    0x69, 0x74, 0x79, 0x20, 0x45, 0x6e, 0x67, 0x69, 0x6e, 0x65, 0x65, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x61, 0x6e, 0x64, 0x20,
    0x41, 0x72, 0x63, 0x68, 0x69, 0x74, 0x65, 0x63, 0x74, 0x75, 0x72, 0x65, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04,
    0x08, 0x0c, 0x0a, 0x43, 0x61, 0x6c, 0x69, 0x66, 0x6f, 0x72, 0x6e, 0x69, 0x61, 0x31, 0x21, 0x30, 0x1f, 0x06, 0x09, 0x2a,
    0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x12, 0x75, 0x73, 0x65, 0x72, 0x6e, 0x61, 0x6d, 0x65, 0x40, 0x61,
    0x70, 0x70, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x02, 0x04, 0x74, 0x3f, 0x1d, 0x98, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86,
    0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
    0x01, 0x01, 0x05, 0x00, 0x04, 0x82, 0x01, 0x00, 0xc9, 0x25, 0xbe, 0xb8, 0xf2, 0x2c, 0x7f, 0xc8, 0x3a, 0xc3, 0xc2, 0x4b,
    0xac, 0x54, 0xcf, 0xa6, 0x75, 0xaa, 0xeb, 0x40, 0x68, 0xee, 0xe2, 0xb1, 0xa8, 0x70, 0x9e, 0xe9, 0x8b, 0xf1, 0x0a, 0x85,
    0x88, 0x40, 0xef, 0xb8, 0xa5, 0x04, 0x87, 0x63, 0x03, 0xf5, 0x41, 0x81, 0x29, 0x42, 0x7f, 0x31, 0x8f, 0x5b, 0xde, 0xe8,
    0x15, 0xc1, 0xa3, 0x45, 0xf1, 0xbc, 0xff, 0x81, 0x58, 0xbd, 0xac, 0x4c, 0xa5, 0xb3, 0x30, 0x9a, 0xb8, 0x9e, 0x69, 0x10,
    0xad, 0x44, 0x7b, 0x93, 0x28, 0xba, 0xca, 0x6f, 0x2e, 0xf8, 0x1b, 0x03, 0xc2, 0x0a, 0x4a, 0x06, 0x32, 0x4d, 0x30, 0x50,
    0xb7, 0x9c, 0x57, 0x4d, 0x4b, 0x6c, 0x34, 0x53, 0xd8, 0xf5, 0xca, 0x91, 0xa5, 0xdf, 0xa6, 0x67, 0x0a, 0x2e, 0x02, 0x47,
    0x1c, 0x1c, 0xd6, 0x2b, 0xe2, 0x85, 0xc1, 0xda, 0x79, 0xa2, 0xe2, 0x1e, 0xf8, 0x5e, 0xf9, 0x76, 0x55, 0xaf, 0x61, 0xaf,
    0xde, 0x0a, 0x7b, 0xeb, 0xa1, 0xa8, 0xc6, 0xef, 0x76, 0x2f, 0x50, 0xd1, 0x0a, 0xce, 0xdb, 0x14, 0xc3, 0x13, 0x72, 0xe5,
    0x26, 0x67, 0x90, 0x19, 0x15, 0x7b, 0x79, 0x05, 0xeb, 0x20, 0xb3, 0x5a, 0x4e, 0x78, 0xae, 0x2d, 0x9c, 0xd1, 0x31, 0xfd,
    0x2e, 0xcb, 0x84, 0xb9, 0x67, 0xea, 0xaf, 0xb3, 0xc2, 0x5f, 0xf5, 0xcd, 0x7b, 0x66, 0x3f, 0xdf, 0xf7, 0xe7, 0x76, 0x46,
    0x57, 0xd9, 0xee, 0x4b, 0xb2, 0xc8, 0x7b, 0xf9, 0x88, 0xab, 0x8e, 0xca, 0xfc, 0x39, 0xd1, 0x8e, 0x1c, 0xba, 0x3e, 0x63,
    0xb7, 0xe8, 0x0e, 0x2f, 0xde, 0x6b, 0x76, 0x81, 0xbf, 0x78, 0x26, 0x0c, 0xa0, 0x2c, 0x35, 0x21, 0xde, 0xb4, 0x45, 0x0a,
    0x84, 0xea, 0x68, 0xa5, 0x37, 0xe8, 0x4a, 0xbc, 0xa6, 0xcf, 0x24, 0x85, 0x46, 0x33, 0x9e, 0xd9, 0xba, 0x58, 0x75, 0xd7,
    0x45, 0xc2, 0x99, 0xe5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif /* cms_trust_settings_test_h */
