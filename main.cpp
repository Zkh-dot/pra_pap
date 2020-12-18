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
        case 1: cout << "Âûïîëíåíî äåéñòâèå 1";
            break;
        case 2: text = GetText(txt);
            cout << text << endl;
            break;
        case 3: cout << "Âûïîëíåíî äåéñòâèå 3";
            break;
        case 4: cout << "Âûïîëíåíî äåéñòâèå 4";
            break;
        //  <âûçîâ ôóíêöèè, ðåàëèçóþùåé âàðèàíò äðóãîãî ÷ëåíà ãðóïïû>
        case 5: cout << "Âûïîëíåíî äåéñòâèå 5";
            break;
        case 6: delete[] txt; return 0;
        default: cout << ("Íàäî ââîäèòü ÷èñëà îò 1 äî 6\n");
            break;
        }
    }
    system("pause");
    return 0;
}

//---------------------------------------------------------------------
int menu() {
    cout << "===================ÄÎÌÀØÍÅÅ ÇÀÄÀÍÈÅ===================\n";
    cout << "\t1 - Ââîä òåêñòà ñ êëàâèàòóðû\n";
    cout << "\t2 - Çàïîëíåíèå ñòðóêóðû Text\n";
    cout << "\t3 - Çàïîëíåíèå ñòðóêóðû Sentence\n";
    cout << "\t4 - ÄÇ âàðèàíò 18\n";
    cout << "\t5 - ÄÇ âàðèàíò 12\n";
    cout << "\t6 - Âûõîä\n";
    int choice;
    cout << "Âûáåðåòå äåéñòâèå: ";
    cin >> choice;
    while (cin.fail()) {
        cout << "Îøèáêà ââîäà. Ïîâòîðèòå ââîä\n";//rohbornb
        cin.clear();
        cin.ignore(10, '\n');
        cout << "Âûáåðåòå äåéñòâèå: ";
        cin >> choice;
    }
    return choice;
}
//----------------------------------------------------------------------
