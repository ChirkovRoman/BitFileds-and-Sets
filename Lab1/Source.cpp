#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, k;
	/*
	cout << "“естирование программ поддержки множества" << endl;
	cout << "	–ешето Ёратосфена			  " << endl;
	cout << "¬ведите верхнюю границу целых значений - ";

	cin >> n;
	TSet s(n + 1); // заполнение множества

	for (m = 2; m <= n; m++) 
		s.InsElem(m); // проверка до sqrt(n) и удаление кратных

	for (m = 2; m * m <= n; m++) // если м в s, удаление кратных
		if (s.IsMember(m)) 
			for (k = 2 * m; k <= n; k += m) 
				if (s.IsMember(k)) s.DelElem(k); // оставшиес€ в s элементы - простые числа

	cout << endl << "ѕечать множества некратных чисел" << endl << s << endl;
	*/

	cout << endl << "¬вод множества A" << endl;	
	cout << endl << "¬ведите наибольший элемент" << endl;
	cin >> n;
	TSet A(n+1);
	cin >> A;

	cout << endl << "¬ведЄнное множество" << endl;
	cout << A << endl;

	cout << endl << "¬вод множества B" << endl;
	cout << endl << "¬ведите наибольший элемент" << endl;
	cin >> n;
	TSet B(n + 1);
	cin >> B;

	cout << endl << "¬ведЄнное множество" << endl;
	cout << B << endl;

	cout << endl << "¬ведите элемент дл€ добавлени€ в множество A" << endl;
	cin >> n;
	A = A + n;
	cout << A << endl;

	cout << endl << "¬ведите элемент дл€ исключени€ из множества A" << endl;
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