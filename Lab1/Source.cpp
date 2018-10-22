#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, k, count;

	cout << "������������ �������� ��������� ���������" << endl;
	cout << "			 ������ ����������			  " << endl;
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
	cout << endl << "������ ������� �����" << endl;
	count = 0;

	k = 1;

	system("pause");
}