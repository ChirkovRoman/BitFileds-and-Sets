#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, k;
	/*
	cout << "Тестирование программ поддержки множества" << endl;
	cout << "	Решето Эратосфена" << endl;
	cout << "Введите верхнюю границу целых значений - ";

	cin >> n;
	TSet s(n + 1); // заполнение множества

	for (m = 2; m <= n; m++) 
		s.InsElem(m); // проверка до sqrt(n) и удаление кратных

	for (m = 2; m * m <= n; m++) // если м в s, удаление кратных
		if (s.IsMember(m)) 
			for (k = 2 * m; k <= n; k += m) 
				if (s.IsMember(k)) s.DelElem(k); // оставшиеся в s элементы - простые числа

	cout << endl << "Печать множества некратных чисел" << endl << s << endl;
	*/

	cout << endl << "Ввод множества A" << endl;	
	cout << endl << "Введите наибольший элемент" << endl;
	cin >> n;
	TSet A(n+1);
	cin >> A;

	cout << endl << "Введённое множество" << endl;
	cout << A << endl;
	cout << "Всего элементов " << A.GetPower() << endl;

	cout << endl << "Ввод множества B" << endl;
	cout << endl << "Введите наибольший элемент" << endl;
	cin >> n;
	TSet B(n + 1);
	cin >> B;

	cout << endl << "Введённое множество" << endl;
	cout << B << endl;
	cout << "Всего элементов " << B.GetPower() << endl;

	cout << endl << "Введите элемент для добавления в множество A" << endl;
	cin >> n;
	A = A + n;
	cout << A << endl;
	

	cout << endl << "Введите элемент для исключения из множества A" << endl;
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


	cout << "Множество B после копирования множества A = {" << B << "}" << endl;

	TBitField C = B;
	cout << "Битовое поле, полученное из B " << C << endl;

	cout << endl << "Введите элемент проверки на наличие в множестве B" << endl;
	cin >> n;
	if (B.IsMember(n))
		cout << n << " является элементом множества B" << endl;
	else 
		cout << n << " не является элементом множества B" << endl;

	system("pause");
}