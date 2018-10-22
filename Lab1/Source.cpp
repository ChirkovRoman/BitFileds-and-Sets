#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, k;
	/*
	cout << "������������ �������� ��������� ���������" << endl;
	cout << "	������ ����������			  " << endl;
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
	*/

	cout << endl << "���� ��������� A" << endl;	
	cout << endl << "������� ���������� �������" << endl;
	cin >> n;
	TSet A(n+1);
	cin >> A;

	cout << endl << "�������� ���������" << endl;
	cout << A << endl;

	cout << endl << "���� ��������� B" << endl;
	cout << endl << "������� ���������� �������" << endl;
	cin >> n;
	TSet B(n + 1);
	cin >> B;

	cout << endl << "�������� ���������" << endl;
	cout << B << endl;

	cout << endl << "������� ������� ��� ���������� � ��������� A" << endl;
	cin >> n;
	A = A + n;
	cout << A << endl;

	cout << endl << "������� ������� ��� ���������� �� ��������� A" << endl;
	cin >> n;
	A = A - n;
	cout << A << endl;

	//TSet R1 = A + B;
	//TSet R2 = A * B;
	cout << "A + B = {" << A + B << "}" << endl;
	cout << "A * B = {" << A * B << "}" << endl;
	cout << "~A = {" << ~A << "}" << endl;

	system("pause");
}