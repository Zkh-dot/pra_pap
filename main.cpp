#include "dz2020.h"

using namespace std;

int menu();

int main() {
	system("chcp 1251 >nul");
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* txt = 0;
	Text text;
	char* word = 0;
	char ch = 'x';
	while (true) {
		switch (menu()) {
		case 1: cout << "Выполнено действие 1";
			break;
		case 2: text = GetText(txt);
			cout << text << endl;
			break;
		case 3: cout << "Выполнено действие 3";
			break;
		case 4: cout << "Выполнено действие 4";
			break;
		//  <вызов функции, реализующей вариант другого члена группы>
		case 5: cout << "Выполнено действие 5";
			break;
		case 6: delete[] txt; return 0;
		default: cout << ("Надо вводить числа от 1 до 6\n");
			break;
		}
	}
	system("pause");
	return 0;
}

//---------------------------------------------------------------------
int menu() {
	cout << "===================ДОМАШНЕЕ ЗАДАНИЕ===================\n";
	cout << "\t1 - Ввод текста с клавиатуры\n";
	cout << "\t2 - Заполнение струкуры Text\n";
	cout << "\t3 - Заполнение струкуры Sentence\n";
	cout << "\t4 - ДЗ вариант 18\n";
	cout << "\t5 - ДЗ вариант 12\n";
	cout << "\t6 - Выход\n";
	int choice;
	cout << "Выберете действие: ";
	cin >> choice;
	while (cin.fail()) {
		cout << "Ошибка ввода. Повторите ввод\n";
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Выберете действие: ";
		cin >> choice;
	}
	return choice;
}
//---------------------------------------------------------------------
