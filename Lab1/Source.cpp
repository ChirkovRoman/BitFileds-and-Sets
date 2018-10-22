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
	cout << "Тестирование программ поддержки множества" << endl;
	menu();
}

void menu()
{
	int input = -1;
	while (input == -1) {
		cout << "Введите номер желаемого действия"								<< endl
			 << "\t1. Применить Решето Эратосфена и отобразить простые числа"	<< endl
			 << "\t2. Ввести два множества и провести над ними операции"		<< endl;
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

	cout << "	Решето Эратосфена" << endl;
	cout << "Введите верхнюю границу целых значений - ";

	cin >> n;
	TSet s(n + 1);

	for (m = 2; m <= n; m++)
		s.InsElem(m);

	for (m = 2; m * m <= n; m++)
		if (s.IsMember(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.IsMember(k)) s.DelElem(k);

	cout << endl << "Печать множества некратных чисел" << endl << s << endl;
}

void operations()
{
	int n;
	cout << "Ввод множества A" << endl;
	cout << "Введите наибольший элемент" << endl;
	cin >> n;
	TSet A(n + 1);
	cin >> A;

	cout << "Введённое множество" << endl;
	cout << A << endl;
	cout << "Всего элементов " << A.GetPower() << endl;

	cout << "Ввод множества B" << endl;
	cout << "Введите наибольший элемент" << endl;
	cin >> n;
	TSet B(n + 1);
	cin >> B;

	cout << "Введённое множество" << endl;
	cout << B << endl;
	cout << "Всего элементов " << B.GetPower() << endl;

	//int input = -1;
	while () {
		cout << "Выберите дальнейшее действие:" << endl
			<< "\t1. Операции над A" << endl
			<< "\t2. Операции над B" << endl
			<< "\t3. Операции над обоими множествами" << endl
			<< "\t-1. Завершить работу" << endl;
		//cin >> input;

		//if ((input == 1) || (input == 2))
			cout << "Выберите дальнейшее действие:" << endl
			<< "\t1. Добавить элемент" << endl
			<< "\t2. Удалить элемент" << endl;
		<< "\t3. Напечатать дополнение множества" << endl;
		/*
			<< "\t5. Проверить равенство множеств А и B" << endl
			<< "\t6. Найти объединение множеств А и B" << endl
			<< "\t7. Найти пересечение множеств А и B" << endl*/
			

			cin >> n;

		switch (n) {
		case 1:
			cout << "Введите элемент для добавления в множество A" << endl;
			cin >> n;
			A = A + n;
			cout << A << endl;
			break;
		case 2:
			cout << "Введите элемент для добавления в множество B" << endl;
			cin >> n;
			B = B + n;
			cout << B << endl;
			break;
		case 3:
			cout << "Введите элемент для исключения из множества A" << endl;
			cin >> n;
			A = A - n;
			cout << A << endl;
			break;
		case 4:
			cout << "Введите элемент для исключения из множества B" << endl;
			cin >> n;
			B = B - n;
			cout << B << endl;
			break;
		case 5:
			if (A == B)
				cout << "A == B" << endl;
			else
				cout << "A != B" << endl;
			break;
		case 6:
			cout << "A + B = {" << A + B << "}" << endl;
			break;
		case 7:
			cout << "A * B = {" << A * B << "}" << endl;
			break;
		case 8:
			cout << "~A = {" << ~A << "}" << endl;
			break;
		case 9:
			cout << "~B = {" << ~B << "}" << endl;
			break;

		}
	}

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

}
