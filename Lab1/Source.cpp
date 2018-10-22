#include "TBitField.h"
#include <locale.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int input;
	cout << "������� ����� ����" << endl;
	cin >> input;
	TBitField F = TBitField(input);

	cout << "������� ����� ���� ��� ���������" << endl;
	cin >> input;
	F.SetBit(input);
	cout << F << endl;

	cout << "������� ����� ���� ��� ���������" << endl;
	cin >> input;
	F.SetBit(input);
	cout << F << endl;

	cout << "������� ����� ���� ��� �������" << endl;
	cin >> input;
	F.ClearBit(input);
	cout << F << endl;

	TBitField D = TBitField(256);
	cout << "������� ���� 1" << endl;
	cin >> D;

	TBitField E = TBitField(256);
	cout << "������� ���� 2" << endl;
	cin >> E;

	if (E == D) cout << "���� 1 == ���� 2" << endl;
	else cout << "���� 1 != ���� 2" << endl;

	cout << D << endl;

	TBitField H = TBitField(256);
	TBitField G = TBitField(256);

	H = D | E;
	G = D & E;
	cout << "���� 1 | ���� 2 = " << H << endl;
	cout << "���� 1 & ���� 2 = " << G << endl;
	cout << "~���� 1 = " << ~E << endl;
	system("pause");
}