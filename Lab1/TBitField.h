#pragma once
#include <string>
#include <iostream>
using namespace std;
typedef unsigned int TELEM;

class TBitField
{
private:
	int BitLen;
	int MemLen;
	TELEM *pMem;
public:
	TBitField();
	TBitField(const int _BitLen);
	TBitField(const TBitField &bf);
	//Методы реализации
	int GetMemIndex(const int n) const;
	TELEM GetMemMask(const int n) const;

	//Доступ к битам
	TELEM operator[](int n);
	int GetBitLen() const;
	int GetMemLen() const;
	void SetBit(const int n);
	void ClearBit(const int n);
	int GetBit(const int n) const;

	//Битовые операции
	int operator==(const TBitField &bf);
	TBitField& operator=(const TBitField &bf);
	TBitField operator|(const TBitField &bf);
	TBitField operator&(const TBitField &bf);
	TBitField operator~();
	friend istream &operator>>(istream &istr, TBitField &bf);
	friend ostream &operator<<(ostream &ostr, const TBitField &bf);
	~TBitField();
};


