#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;
void menu();
void primeNumbers();
void operations();

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������������ �������� ��������� ���������" << endl;

	menu();

	cout << endl << "���� ��������� A" << endl;	
	cout << endl << "������� ���������� �������" << endl;
	cin >> n;
	TSet A(n+1);
	cin >> A;

	cout << endl << "�������� ���������" << endl;
	cout << A << endl;
	cout << "����� ��������� " << A.GetPower() << endl;
	
	cout << endl << "���� ��������� B" << endl;
	cout << endl << "������� ���������� �������" << endl;
	cin >> n;
	TSet B(n + 1);
	cin >> B;

	cout << endl << "�������� ���������" << endl;
	cout << B << endl;
	cout << "����� ��������� " << B.GetPower() << endl;

	cout << endl << "������� ������� ��� ���������� � ��������� A" << endl;
	cin >> n;
	A = A + n;
	cout << A << endl;
	

	cout << endl << "������� ������� ��� ���������� �� ��������� A" << endl;
	cin >> n;
	A = A - n;
	cout << A << endl;

	if (A == B)
		cout << "A == B" << endl;
	else 
		cout << "A != B" << endl;
	
	cout << "A + B = {" << A + B << "}" << endl;
	cout << "A * B = {" << A * B << "}" << endl;

	cout << "~A = {" << ~A << "}" << endl;

	B = A;
	cout << "��������� B ����� ����������� ��������� A = {" << B << "}" << endl;

	TBitField C = B;
	cout << "������� ����, ���������� �� B " << C << endl;

	cout << endl << "������� ������� �������� �� ������� � ��������� B" << endl;
	cin >> n;
	if (B.IsMember(n))
		cout << n << " �������� ��������� ��������� B" << endl;
	else 
		cout << n << " �� �������� ��������� ��������� B" << endl;
		
	system("pause");
}

void menu()
{
	int input = -1;
	while (input == -1) {
		cout << "������� ����� ��������� ��������"								<< endl
			 << "\t1. ��������� ������ ���������� � ���������� ������� �����"	<< endl
			 << "\t2. ������ ��� ��������� � �������� ��� ���� ��������"		<< endl;
		cin >> input;
	}
	switch (input) {
		case 1:
			primeNumbers();
			break;
		case 2: 
			operations();
			break;
		default: input = -1;
	}
}

void primeNumbers()
{
	int n, m, k;

	cout << "	������ ����������" << endl;
	cout << "������� ������� ������� ����� �������� - ";

	cin >> n;
	TSet s(n + 1); // ���������� ���������

	for (m = 2; m <= n; m++)
		s.InsElem(m); // �������� �� sqrt(n) � �������� �������

	for (m = 2; m * m <= n; m++) // ���� � � s, �������� �������
		if (s.IsMember(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.IsMember(k)) s.DelElem(k); // ���������� � s �������� - ������� �����

	cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
}
