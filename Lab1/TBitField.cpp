#include "TBitField.h"

TBitField::TBitField()
{
	BitLen = 0;
	MemLen = 0;
	pMem = NULL;
}

TBitField::TBitField(const int _BitLen)
{
	BitLen = _BitLen;
	MemLen = (BitLen + 31) >> 5;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++) {
		pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField & bf)
{
	BitLen = bf.GetBitLen();
	MemLen = bf.GetMemLen();
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++) {
		pMem[i] = bf.pMem[i];
	}
}

int TBitField::GetMemIndex(const int n) const
{
	if (n < 0) return -1;

	int index = n >> 5;
	return index;
}

TELEM TBitField::GetMemMask(const int n) const
{
	TELEM Mask;
	//int m =  n - ((n >> 5) * 32);
	Mask = 1 << (n & 31);
	return Mask;
}

TELEM TBitField::operator[](int n)
{
	return pMem[n];
}

int TBitField::GetBitLen() const
{
	return BitLen;
}

int TBitField::GetMemLen() const
{
	return MemLen;
}

void TBitField::SetBit(const int n) 
{
	// 0 < n < BitLen !!!
	int bit = GetBit(n);
	if ((bit == 1) || (n < 0) || (n > BitLen)) return;
	int index = GetMemIndex(n);
	int mask = GetMemMask(n);
	pMem[index] = pMem[index] | mask;
}

void TBitField::ClearBit(const int n)
{
	// 0 < n < BitLen !!!
	int bit = GetBit(n); 
	if ((bit == 0) || (n < 0) || (n > BitLen)) return;
	int index = GetMemIndex(n);
	int mask = GetMemMask(n);
	pMem[index] = pMem[index] & ~mask;
	
}

int TBitField::GetBit(const int n) const
{
	int index = GetMemIndex(n);
	int mask = GetMemMask(n);
	if (!(pMem[index] & mask))
		return 0;
	else
		return 1;
}

int TBitField::operator==(const TBitField & bf)
{
	if ((BitLen != bf.GetBitLen()) || (MemLen != bf.GetMemLen())) return 0;
	for (int i = 0; i < MemLen; i++) {
		if (pMem[i] != bf.pMem[i]) return 0;
	}
	return 1;
}

TBitField & TBitField::operator=(const TBitField & bf)
{
	if (this != &bf) {
		BitLen = bf.GetBitLen();
		MemLen = bf.GetMemLen();
		pMem = new TELEM[MemLen];
		for (int i = 0; i < MemLen; i++) {
			pMem[i] = bf.pMem[i];
		}
	}
	return *this;
}

TBitField TBitField::operator|(const TBitField & bf)
{
	int len = BitLen;
	if (BitLen < bf.BitLen)
		len = bf.BitLen;
	TBitField tmp(len);
	for (int i = 0; i < MemLen; i++)
	{
		tmp.pMem[i] = pMem[i];
	}
	for (int i = 0; i < bf.MemLen; i++) {
		tmp.pMem[i] |= bf.pMem[i];
	}
	return tmp;
}

TBitField TBitField::operator&(const TBitField & bf)
{
	int len = BitLen;
	if (BitLen < bf.BitLen)
		len = bf.BitLen;
	TBitField tmp(len);
	for (int i = 0; i < MemLen; i++)
	{
		tmp.pMem[i] = pMem[i];
	}
	for (int i = 0; i < bf.MemLen; i++) {
		tmp.pMem[i] &= bf.pMem[i];
	}
	return tmp;
}
TBitField TBitField::operator~()
{
	for (int i = 0; i < MemLen; i++) {
		pMem[i] = ~pMem[i];
	}
	return *this;
}

TBitField::~TBitField()
{
	delete[] pMem;
}

istream & operator>>(istream & istr, TBitField & bf)
{
	char buf[256];
	istr >> buf;

	TBitField field = TBitField(strlen(buf));
	for (int i = 0; buf[i] != 0; i++) {
		if (buf[i] != '0')
			field.SetBit(i);
		else
			field.ClearBit(i);
	}
	bf = field;
	return istr;
}

ostream & operator<<(ostream & ostr, const TBitField & bf)
{
	int len = bf.GetBitLen();
	for (int i = 0; i < len; i++) {
		if (bf.GetBit(i)) 
			ostr << '1';
		else 
			ostr << '0';
	}
	return ostr;
}
