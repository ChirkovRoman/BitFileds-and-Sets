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

TSet & TSet::operator=(const TSet & s)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}
