#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

//Структуры Text и Sentence (со статическими массивами):
const int maxWords = 40;
struct Sentence {
	char* words[maxWords];  //массив указателей на слова в предложении
	int nWords;  //фактическое число слов в предложении
	char*& operator[](int index); //перегрузка оператора индексации
	int wordsAttributes[maxWords]; //массив признаков слов
	Sentence(); //конструктор
};
Sentence::Sentence() {
	nWords = 0;
	for (int i = 0; i < maxWords; i++) {
		words[i] = 0;
		wordsAttributes[i] = 0;
	}
}

const int maxSentences = 10;
struct Text {
	Sentence sentences[maxSentences]; //массив из указателей на предложения в тексте
	int nSentences; //фактическое число слов в предложении
	Sentence& operator[](int index); //перегрузка оператора индексации
	int sentencesAttributes[maxSentences]; //массив признаков придложений
	Text(); //конструктор
};
Text::Text() {
	nSentences = 0;
	for (int i = 0; i < maxSentences; i++) {
		sentencesAttributes[i] = 0;
	}
}
//=====================================================================

Text& GetText(char*);
Sentence& GetSentence(char*);
//---------------------------------------------------------------------
Sentence& Text::operator[](int index)
{
	return sentences[index];
}
//---------------------------------------------------------------------
char*& Sentence::operator[](int index)
{
	return words[index];
}
//---------------------------------------------------------------------
ostream& operator <<(ostream& out, Sentence& sentence)
{
	for (int i = 0; i < sentence.nWords; i++)
		out << sentence.words[i] << " ";
	out << '\b';
	return out;
}
//---------------------------------------------------------------------
ostream& operator <<(ostream& out, Text& text)
{
	for (int i = 0; i < text.nSentences - 1; i++)
		out << text.sentences[i] << '.' << endl;
	return out;
}
//---------------------------------------------------------------------
Text& GetText(char* txt) {
	Text text = *new Text;
	const char* sentenceDelim = ".";
	char* token, * nextToken = txt;
	while (token = strtok_s(nextToken, sentenceDelim, &nextToken))
		text.sentences[text.nSentences++] = GetSentence(token);
	return text;
}
//---------------------------------------------------------------------
Sentence& GetSentence(char* str) {
	Sentence sentence = *new Sentence;
	sentence.nWords = 0;
	const char* wordDelims = " ,";
	char* word, * nextWord = str;
	while (word = strtok_s(nextWord, wordDelims, &nextWord))
		sentence.words[sentence.nWords++] = word;
	return sentence;
}
//---------------------------------------------------------------------
char* inputText()
{
	int n = 100; //начальный размер буфера
	int count = 0;
	char* str = new char[n];
	cout << "\n Введите текст из латинских букв, пробелов и знаков пунктуации,\n"
		<< "заканчивающийся символом \"конец текста\" (нажмите Enter): \n";
	char symb;
	//ввод текста
	while ((symb = _getch()) != char(13))
	{
		switch (symb)
		{
		case 8:
			if (count != 0) {
				_putch('\b');
				_putch(' ');
				_putch('\b');
				str[--count] = '0';
			}
			break;
		default:
			if (((symb >= 'a') && (symb <= 'z')) || ((symb >= 'A') && (symb <= 'Z')) || (symb == ',') || (symb == ' ') || (symb == '.')) {
				_putch(symb);
				str[count] = symb;
				count++;
			}
		}
	}
	_putch('\n');
	return str;
}
//---------------------------------------------------------------------
//<ДЗ для варианта 18>
void delWords(Sentence& sentence) {              //удаление слов, равных последнему слову в предложении.
	for (int i = 0; i < sentence.nWords - 1; i++)
	{
		if (strcmp(sentence[i], sentence[sentence.nWords - 1]) == 0)
		{
			for (int j = i; j < sentence.nWords - 1; j++)
				sentence[j] = sentence[j + 1];
			--sentence.nWords;
			--i;
		}
	}

	return;
}

void Changes(Sentence& sentence) {               //замена окончаний у слов
	for (int i = 0; i < sentence.nWords; i++)
	{
		char* word = new char[maxWords];
		if ((strcmp((sentence[i] + (strlen(sentence[i]) - 2)), "ov") == 0)
			|| (strcmp((sentence[i] + (strlen(sentence[i]) - 2)), "in") == 0)
			|| (strcmp((sentence[i] + (strlen(sentence[i]) - 2)), "ev") == 0))
		{
			for (int j = 0; j < strlen(sentence[i]) - 2; j++)
				word[j] = sentence[i][j];
			word[strlen(sentence[i]) - 2] = 'i';
			word[strlen(sentence[i]) - 1] = 'd';
			word[strlen(sentence[i])] = 'z';
			word[strlen(sentence[i]) + 1] = 'e';
			sentence.words[i] = word;
		}
		if ((strcmp((sentence[i] + (strlen(sentence[i]) - 3)), "ova") == 0)
			|| (strcmp((sentence[i] + (strlen(sentence[i]) - 3)), "ina") == 0)
			|| (strcmp((sentence[i] + (strlen(sentence[i]) - 3)), "eva") == 0))
		{
			for (int j = 0; j < strlen(sentence[i]) - 3; j++)
				word[j] = sentence[i][j];
			word[strlen(sentence[i]) - 3] = 'i';
			word[strlen(sentence[i]) - 2] = 'd';
			word[strlen(sentence[i]) - 1] = 'z';
			word[strlen(sentence[i])] = 'e';
			sentence.words[i] = word;
		}
	}
	return;
}
void dz18(Text& text) {
	cout << endl << "\"Оставить в предложениях слова, отличающихся от последнего слова предложения и если\n"
		<< "слово оканчивается на ov, ova, in, ina, ev, eva, заменить это окончание на idze.\"\n" << endl;

	cout << "Печать текста после удаления слов, совпадающих с последним:\n";
	for (int k = 0; k < text.nSentences; k++)
		delWords(text.sentences[k]);
	cout << text << endl;

	cout << "Печать текста после замены окончаний ov, ova, in, ina, ev, eva на idze:\n";
	for (int k = 0; k < text.nSentences - 1; k++)
		Changes(text.sentences[k]);
	cout << text << endl;
	return;
}
//---------------------------------------------------------------------
