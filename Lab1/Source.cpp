#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, k;

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


	cout << endl << "���� ��������� ���������" << endl;	
	
	cout << endl << "������� ���������� �������" << endl;
	cin >> n;
	TSet d(n+1);
	cin >> d;

	cout << endl << "�������� ���������" << endl;
	cout << d << endl;

	system("pause");
}