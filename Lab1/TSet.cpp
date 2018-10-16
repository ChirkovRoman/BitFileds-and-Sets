#include "TSet.h"



TSet::TSet()
{
	MaxPower = 0;
	TBitField BitField = TBitField();
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

int TSet::GetPower(void) const
{
	int count = 0;
	for (int i = 0; i < MaxPower; i++) {
		if (IsMember(i))
			count++;
	}
	return count;
}

void TSet::InsElem(const int n)
{
	if (n > MaxPower)
		BitField = TBitField(MaxPower) | BitField;
	BitField.SetBit(n);
}

void TSet::DelElem(const int n)
{
	BitField.ClearBit(n);
}

int TSet::IsMember(const int n) const
{
	return BitField.GetBit(n);
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
	return *this;
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
	TSet tmp;
	tmp.BitField = BitField | s.BitField;
	tmp.MaxPower = tmp.BitField.GetBitLen();

	return tmp;
}

TSet TSet::operator*(const TSet & s)
{
	TSet tmp;
	tmp.BitField = BitField & s.BitField;
	tmp.MaxPower = tmp.BitField.GetBitLen();

	return tmp;
}

TSet TSet::operator~(void)
{
	TSet tmp = *this;
	tmp.BitField = ~BitField;

	return tmp;
}

istream & operator>>(istream & istr, TSet & set)
{
	cout << "¬ведите -1, чтобы прекратить ввод" << endl;
	int buf;
	do  {
		scanf("%d", &buf);
		if (buf == -1)  break;
		if (buf > set.MaxPower) 
			cout << "Ёлемент не входит в множество" << endl;
		set = set + buf;
	} while (buf != -1);
	return istr;
}

ostream & operator<<(ostream & ostr, const TSet & set)
{
	for (int i = 0; i < set.BitField.GetBitLen(); i++) {
		if (set.IsMember(i))
			ostr << i << " ";
	}
	return ostr;
}
