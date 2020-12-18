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
	int wordsAttributes[maxWords]; //массив признаков слов:
		// 0 - атрибут не установлен (по умолчанию);
		// 1 - слово совпадает с последним словом предложения;
		// 2 - повторяющееся слово;
		// 3 - неповторяющееся слово.
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
	int sentencesAttributes[maxSentences]; //массив признаков придложений:
	   // 0 - атрибут не установлен (по умолчанию);
	   // 1 - повествовательное предложение;
	   // 2 - вопросительное предложение;
	   // 3 - восклицательное предложение.
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
void markRepeatedWord(Text& text)       //отметить в тексте повторяющеися слова 
{
	for (int k = 0; k < text.nSentences; k++) 
	{
		for (int i = 0; i < text.sentences[k].nWords; i++)
		{
			if (text.sentences[k].wordsAttributes[i] == 0)
			{
				for (int j = i + 1; j < text[k].nWords; j++)
				{
					if (strcmp(text[k][i], text[k][j]) == 0)
					{
						text[k].wordsAttributes[j] = 2; //повторное вхождение слова
						text[k].wordsAttributes[i] = 1; //первое вхождение слова
					}
				}
			}
		}
	}
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
