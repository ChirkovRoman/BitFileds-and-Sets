#include "TSet.h"



TSet::TSet()
{
	MaxPower = 0;
	BitField = NULL;
}


TSet::~TSet()
{
}

TSet::TSet(int mp)
{
	MaxPower = mp;
	BitField = TBitField(MaxPower);
}

TSet::TSet(const TSet & s)
{
	*this = s;
}

TSet::TSet(const TBitField & bf)
{
	MaxPower = bf.GetBitLen();
	BitField = bf;
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const
{
	return MaxPower;
}

void TSet::InsElem(const int n)
{
	BitField.SetBit(n);
}

void TSet::DelElem(const int n)
{
	BitField.ClearBit(n);
}

int TSet::IsMember(const int n) const
{
	BitField.GetBit(n);
}

int TSet::operator==(const TSet & s)
{
	if (BitField == s.BitField)
		return 1;
	else return 0;
}

TSet & TSet::operator=(const TSet & s)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}

TSet TSet::operator+(const int n)
{
	TSet tmp = *this;
	tmp.InsElem(n);
	return tmp;
}

TSet TSet::operator-(const int n)
{
	TSet tmp = *this;
	tmp.DelElem(n);
	return tmp;
}

TSet TSet::operator+(const TSet & s)
{
	TSet tmp = *this;
	tmp.BitField = tmp.BitField | s.BitField;
	return tmp;
}

TSet TSet::operator*(const TSet & s)
{
	TSet tmp = *this;
	tmp.BitField = tmp.BitField & s.BitField;
	return tmp;
}

TSet TSet::operator~(void)
{
	BitField = ~BitField;
}
