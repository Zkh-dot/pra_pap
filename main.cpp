#include "dz2020.h"

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
		case 1: txt = inputText();
			cout << txt << endl;
			break;
		case 2: text = GetText(txt);
			cout << endl << text << endl;
			break;
		case 3: cout << text[0][0] + 2 << endl;
				break;
		case 4: cout << "Выполнено действие dz18";
			break;
			//  <вызов функции, реализующей вариант другого члена группы>
		case 5: cout << "Выполнено действие dz12";
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
