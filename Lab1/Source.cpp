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
	cout << "Тестирование программ поддержки множества" << endl;
	menu();
}

void menu()
{
	int input = 0;
	while (input != -1) {
		cout << "Введите номер желаемого действия" << endl
			<< "\t1. Применить Решето Эратосфена и отобразить простые числа" << endl
			<< "\t2. Ввести два множества и провести над ними операции" << endl
			<< "\t-1. Завершить работу" << endl;
		cin >> input;

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

	int input = -1;
	while (input != -1) {
		cout << "Выберите дальнейшее действие:" << endl
			<< "\t1. Операции над A" << endl
			<< "\t2. Операции над B" << endl
			<< "\t3. Операции над обоими множествами" << endl
			<< "\t-1. Завершить работу" << endl;
		cin >> input;

		if ((input == 1) || (input == 2)) {
			cout << "Выберите дальнейшее действие:" << endl
				<< "\t1. Добавить элемент" << endl
				<< "\t2. Удалить элемент" << endl
				<< "\t3. Напечатать дополнение множества" << endl
				<< "\t4. Проверить наличие элемента" << endl;
			cin >> n;

			if (input == 1)
				oneSet(n, A);
			else
				oneSet(n, B);
		}

		if (input == 3) {
			cout << "Выберите дальнейшее действие:" << endl
				<< "\t1. Проверить равенство множеств А и B" << endl
				<< "\t2. Найти объединение множеств А и B" << endl
				<< "\t3. Найти пересечение множеств А и B" << endl
				<< "\t4. Скопировать A в B" << endl
				<< "\t5. Скопировать B в A" << endl;
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
				B = A;
				cout << "Множество B после копирования множества A = {" << B << "}" << endl;
				break;
			case 5:
				A = B;
				cout << "Множество A после копирования множества B = {" << A << "}" << endl;
				break;
			default:
				cout << "Введено неверное значение" << endl;
			}
		}

	}
}

void oneSet(int n, TSet S)
{
	int k;
	switch (n) {
	case 1:
		cout << "Введите элемент для добавления в множество" << endl;
		cin >> k;
		S = S + k;
		cout << S << endl;
		break;
	case 2:
		cout << "Введите элемент для исключения из множества" << endl;
		cin >> k;
		S = S - k;
		cout << S << endl;
		break;
	case 3:
		cout << "Дополнение множества = {" << ~S << "}" << endl;
		break;
	case 4:
		cout << "Введите элемент для проверки на наличие в множестве" << endl;
		cin >> k;
		if (S.IsMember(k))
			cout << k << " является элементом множества" << endl;
		else
			cout << k << " не является элементом множества" << endl;
	default:
		cout << "Введено неверное значение" << endl;
	}
}
