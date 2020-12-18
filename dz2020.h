#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

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
	Sentence* sentences[maxSentences]; //массив из указателей на предложения в тексте
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
	words[index];
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
	for (int i = 0; i < text.nSentences; i++)
		out << text.sentences[i] << '.' << endl;
	return out;
}
//---------------------------------------------------------------------
Sentence& GetSentence(char* str) {
	Sentence sentence = *new Sentence;
	sentence.nWords = 0;
	char* wordDelims = " ,";
	char* word, * nextWord;
	while (word = strtok_s(nextWord, wordDelims, &nextWord))
		sentence.words[sentence.nWords++] = word;
	return sentence;
}
//---------------------------------------------------------------------
Text& GetText(char* txt) {
	Text text = *new Text;
	char* sentenceDelim = ".";
	char* token, * nextToken = txt;
	while (token = strtok_s(nextToken, sentenceDelim, &nextToken))
		text.sentences[text.nSentences++] = GetSentence(token);
	return text;
}
//---------------------------------------------------------------------
