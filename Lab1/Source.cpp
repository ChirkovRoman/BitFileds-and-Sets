#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;
void menu();
void primeNumbers();
void operations();
void oneSet(int n, TSet S);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������������ �������� ��������� ���������" << endl;
	menu();
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
	TSet s(n + 1);

	for (m = 2; m <= n; m++)
		s.InsElem(m);

	for (m = 2; m * m <= n; m++)
		if (s.IsMember(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.IsMember(k)) s.DelElem(k);

	cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
}

void operations()
{
	int n;
	cout << "���� ��������� A" << endl;
	cout << "������� ���������� �������" << endl;
	cin >> n;
	TSet A(n + 1);
	cin >> A;

	cout << "�������� ���������" << endl;
	cout << A << endl;
	cout << "����� ��������� " << A.GetPower() << endl;

	cout << "���� ��������� B" << endl;
	cout << "������� ���������� �������" << endl;
	cin >> n;
	TSet B(n + 1);
	cin >> B;

	cout << "�������� ���������" << endl;
	cout << B << endl;
	cout << "����� ��������� " << B.GetPower() << endl;

	int input = -1;
	while (input != -1) {
		cout << "�������� ���������� ��������:" << endl
			<< "\t1. �������� ��� A" << endl
			<< "\t2. �������� ��� B" << endl
			<< "\t3. �������� ��� ������ �����������" << endl
			<< "\t-1. ��������� ������" << endl;
		cin >> input;

		if ((input == 1) || (input == 2)) {
			cout << "�������� ���������� ��������:" << endl
				<< "\t1. �������� �������" << endl
				<< "\t2. ������� �������" << endl
				<< "\t3. ���������� ���������� ���������" << endl;
			cin >> n;
			
			if(input == 1)
				oneSet(n, A);
			else
				oneSet(n, B);
		}

		if (input == 3) {
				cout << "�������� ���������� ��������:" << endl
				<< "\t1. ��������� ��������� �������� � � B" << endl
				<< "\t2. ����� ����������� �������� � � B" << endl
				<< "\t3. ����� ����������� �������� � � B" << endl
				<< "\t4. ����������� A � B" << endl
				<< "\t5. ����������� B � A" << endl;
			cin >> n;

			switch (n) {
			case 1:
				if (A == B)
					cout << "A == B" << endl;
				else
					cout << "A != B" << endl;
				break;
			case 2:
				cout << "A + B = {" << A + B << "}" << endl;
				break;
			case 3:
				cout << "A * B = {" << A * B << "}" << endl;
				break;
			case 4:
				cout << "A * B = {" << A * B << "}" << endl;
				break;
			case 5:
				cout << "A * B = {" << A * B << "}" << endl;
				break;
			

			}
		}
		

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

}

void oneSet(int n, TSet S)
{
	switch (n) {
	case 1:
		cout << "������� ������� ��� ���������� � ���������" << endl;
		cin >> n;
		S = S + n;
		cout << S << endl;
		break;
	case 2:
		cout << "������� ������� ��� ���������� �� ���������" << endl;
		cin >> n;
		S = S - n;
		cout << S << endl;
		break;
	case 3:
		cout << "���������� ��������� = {" << ~S << "}" << endl;
		break;
	}
}
