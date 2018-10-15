#include <locale.h>
#include <iostream>
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m, k;

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


	cout << endl << "¬вод элементов множества" << endl;	
	
	cout << endl << "¬ведите наибольший элемент" << endl;
	cin >> n;
	TSet d(n+1);
	cin >> d;

	cout << endl << "¬ведЄнное множество" << endl;
	cout << d << endl;

	system("pause");
}