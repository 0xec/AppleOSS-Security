//   NOTE: this is a machine generated file--editing not recommended
//
// appleoids.h - class definitions for ASN.1 module APPLE-OIDS
//
//   This file was generated by snacc on Wed Jun 27 16:40:55 2001
//   UBC snacc by Mike Sample
//   A couple of enhancements made by IBM European Networking Center

#ifndef _appleoids_h_
#define _appleoids_h_


//------------------------------------------------------------------------------
// class declarations:

class FEEPrimeType;
class FEECurveType;
class DSABsafeParams;
class FEECurveParameters;
class DSAAlgorithmId;
class FEEElGamalSignature;
class FEEECDSASignature;
class FEEPublicKey;
class FEEPrivateKey;
class DSAPrivateKey;
class DSAPublicKey;
class DSAPrivateKeyOcts;
class DSASignature;
class DSAAlgParams;

//------------------------------------------------------------------------------
// class definitions:

/* INTEGER { pt_mersenne (0), pt_fee (1), pt_general (2) }  */
class FEEPrimeType: public AsnInt
{
public:
			FEEPrimeType(): AsnInt() {}
			FEEPrimeType (int i): AsnInt (i) {}
  enum
  {
    pt_mersenne = 0,
    pt_fee = 1,
    pt_general = 2
  };
};


/* INTEGER { ct_montgomery (0), ct_weierstrass (1), ct_general (2) }  */
class FEECurveType: public AsnInt
{
public:
			FEECurveType(): AsnInt() {}
			FEECurveType (int i): AsnInt (i) {}
  enum
  {
    ct_montgomery = 0,
    ct_weierstrass = 1,
    ct_general = 2
  };
};


class DSABsafeParams: public AsnType
{
public:
  AsnInt		keySizeInBits;
  BigIntegerStr		p;
  BigIntegerStr		q;
  BigIntegerStr		g;

			DSABsafeParams();
			DSABsafeParams (const DSABsafeParams &);
  virtual		~DSABsafeParams();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSABsafeParams		&operator = (const DSABsafeParams &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class FEECurveParameters: public AsnType
{
public:
  FEEPrimeType		primeType;
  FEECurveType		curveType;
  AsnInt		q;
  AsnInt		k;
  AsnInt		m;
  BigIntegerStr		a;
  BigIntegerStr		bb;
  BigIntegerStr		c;
  BigIntegerStr		x1Plus;
  BigIntegerStr		x1Minus;
  BigIntegerStr		cOrderPlus;
  BigIntegerStr		cOrderMinus;
  BigIntegerStr		x1OrderPlus;
  BigIntegerStr		x1OrderMinus;
  BigIntegerStr		*basePrime;

			FEECurveParameters();
			FEECurveParameters (const FEECurveParameters &);
  virtual		~FEECurveParameters();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  FEECurveParameters		&operator = (const FEECurveParameters &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class DSAAlgorithmId: public AsnType
{
public:
  AsnOid		algorithm;
  DSABsafeParams		*params;

			DSAAlgorithmId();
			DSAAlgorithmId (const DSAAlgorithmId &);
  virtual		~DSAAlgorithmId();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSAAlgorithmId		&operator = (const DSAAlgorithmId &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class FEEElGamalSignature: public AsnType
{
public:
  BigIntegerStr		u;
  BigIntegerStr		pmX;

			FEEElGamalSignature();
			FEEElGamalSignature (const FEEElGamalSignature &);
  virtual		~FEEElGamalSignature();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  FEEElGamalSignature		&operator = (const FEEElGamalSignature &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class FEEECDSASignature: public AsnType
{
public:
  BigIntegerStr		c;
  BigIntegerStr		d;

			FEEECDSASignature();
			FEEECDSASignature (const FEEECDSASignature &);
  virtual		~FEEECDSASignature();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  FEEECDSASignature		&operator = (const FEEECDSASignature &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class FEEPublicKey: public AsnType
{
public:
  AsnInt		version;
  FEECurveParameters		*curveParams;
  BigIntegerStr		plusX;
  BigIntegerStr		minusX;
  BigIntegerStr		*plusY;

			FEEPublicKey();
			FEEPublicKey (const FEEPublicKey &);
  virtual		~FEEPublicKey();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  FEEPublicKey		&operator = (const FEEPublicKey &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class FEEPrivateKey: public AsnType
{
public:
  AsnInt		version;
  FEECurveParameters		*curveParams;
  BigIntegerStr		privData;

			FEEPrivateKey();
			FEEPrivateKey (const FEEPrivateKey &);
  virtual		~FEEPrivateKey();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  FEEPrivateKey		&operator = (const FEEPrivateKey &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class DSAPrivateKey: public AsnType
{
public:
  AsnInt		version;
  DSAAlgorithmId		*dsaAlg;
  AsnOcts		privateKey;

			DSAPrivateKey();
			DSAPrivateKey (const DSAPrivateKey &);
  virtual		~DSAPrivateKey();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSAPrivateKey		&operator = (const DSAPrivateKey &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class DSAPublicKey: public AsnType
{
public:
  DSAAlgorithmId		*dsaAlg;
  AsnBits		publicKey;

			DSAPublicKey();
			DSAPublicKey (const DSAPublicKey &);
  virtual		~DSAPublicKey();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSAPublicKey		&operator = (const DSAPublicKey &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class DSAPrivateKeyOcts: public AsnType
{
public:
  BigIntegerStr		privateKey;

			DSAPrivateKeyOcts();
			DSAPrivateKeyOcts (const DSAPrivateKeyOcts &);
  virtual		~DSAPrivateKeyOcts();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSAPrivateKeyOcts		&operator = (const DSAPrivateKeyOcts &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class DSASignature: public AsnType
{
public:
  BigIntegerStr		r;
  BigIntegerStr		s;

			DSASignature();
			DSASignature (const DSASignature &);
  virtual		~DSASignature();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSASignature		&operator = (const DSASignature &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


class DSAAlgParams: public AsnType
{
public:
  BigIntegerStr		p;
  BigIntegerStr		q;
  BigIntegerStr		g;

			DSAAlgParams();
			DSAAlgParams (const DSAAlgParams &);
  virtual		~DSAAlgParams();
  virtual AsnType	*Clone() const;

  virtual AsnType	*Copy() const;

  DSAAlgParams		&operator = (const DSAAlgParams &);
  AsnLen		BEncContent (BUF_TYPE b);
  void			BDecContent (BUF_TYPE b, AsnTag tag, AsnLen elmtLen, AsnLen &bytesDecoded, ENV_TYPE env);

  AsnLen		BEnc (BUF_TYPE b);
  void			BDec (BUF_TYPE b, AsnLen &bytesDecoded, ENV_TYPE env);
  int			BEncPdu (BUF_TYPE b, AsnLen &bytesEncoded);
  int			BDecPdu (BUF_TYPE b, AsnLen &bytesDecoded);

  void		Print (ostream &os) const;
};


//------------------------------------------------------------------------------
// externs for value defs

#define appleBaseOid_arc 1, 2, 840, 113635
#define appleBaseOid     AsnOid(appleBaseOid_arc)
#define appleDataSecurity_arc 1, 2, 840, 113635, 100
#define appleDataSecurity     AsnOid(appleDataSecurity_arc)
#define appleTrustPolicy_arc 1, 2, 840, 113635, 100, 1
#define appleTrustPolicy     AsnOid(appleTrustPolicy_arc)
#define appleSecurityAlgorithm_arc 1, 2, 840, 113635, 100, 2
#define appleSecurityAlgorithm     AsnOid(appleSecurityAlgorithm_arc)
#define appleISignTP_arc 1, 2, 840, 113635, 100, 1, 1
#define appleISignTP     AsnOid(appleISignTP_arc)
#define appleX509Basic_arc 1, 2, 840, 113635, 100, 1, 2
#define appleX509Basic     AsnOid(appleX509Basic_arc)
#define appleSSLPolicy_arc 1, 2, 840, 113635, 100, 1, 3
#define appleSSLPolicy     AsnOid(appleSSLPolicy_arc)
#define appleFee_arc 1, 2, 840, 113635, 100, 2, 1
#define appleFee     AsnOid(appleFee_arc)
#define appleAsc_arc 1, 2, 840, 113635, 100, 2, 2
#define appleAsc     AsnOid(appleAsc_arc)
#define appleFeeMD5_arc 1, 2, 840, 113635, 100, 2, 3
#define appleFeeMD5     AsnOid(appleFeeMD5_arc)
#define appleFeeSHA1_arc 1, 2, 840, 113635, 100, 2, 4
#define appleFeeSHA1     AsnOid(appleFeeSHA1_arc)
#define appleFeed_arc 1, 2, 840, 113635, 100, 2, 5
#define appleFeed     AsnOid(appleFeed_arc)
#define appleFeedExp_arc 1, 2, 840, 113635, 100, 2, 6
#define appleFeedExp     AsnOid(appleFeedExp_arc)
#define appleECDSA_arc 1, 2, 840, 113635, 100, 2, 7
#define appleECDSA     AsnOid(appleECDSA_arc)
//------------------------------------------------------------------------------

#endif /* conditional include of appleoids.h */
