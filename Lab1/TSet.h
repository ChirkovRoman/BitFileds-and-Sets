#pragma once
#include "TBitField.h"
class TSet
{
private: 
	int MaxPower; // ������������ �������� ��������� 
	TBitField BitField; // ������� ���� ��� �������� ���-�� ������� 
public: 
	TSet();
	~TSet();
	TSet(int mp);
	TSet(const TSet &s); // ����������� �����������
	TSet(const TBitField &bf); // ����������� �������������� ����
	operator TBitField(); // �������������� ���� � �������� ����

	// ������ � �����
	int GetMaxPower(void) const; // ������������ �������� ���������
	int GetPower(void) const; // �������� ���������
	void InsElem(const int n); // �������� ������� � ���������
	void DelElem(const int n); // ������� ������� �� ���������
	int IsMember(const int n) const; // ��������� ������� �������� � ���������

	// ���������-������������� ��������
	int operator== (const TSet &s); // ���������
	TSet& operator=(const TSet &s); // ������������
	TSet operator+ (const int n); // ��������� �������� � ���������
	TSet operator- (const int n); // �������� �������� �� ���������
	TSet operator+ (const TSet &s); // �����������
	TSet operator* (const TSet &s); // �����������
	TSet operator~ (void); // ����������

	friend istream &operator>>(istream &istr, TSet &set);
	friend ostream &operator<<(ostream &ostr, const TSet &set);

};

