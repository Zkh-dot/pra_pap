##pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

//Ñòðóêòóðû Text è Sentence (ñî ñòàòè÷åñêèìè ìàññèâàìè):
const int maxWords = 40;
struct Sentence {
	char* words[maxWords];  //ìàññèâ óêàçàòåëåé íà ñëîâà â ïðåäëîæåíèè
	int nWords;  //ôàêòè÷åñêîå ÷èñëî ñëîâ â ïðåäëîæåíèè
	char*& operator[](int index); //ïåðåãðóçêà îïåðàòîðà èíäåêñàöèè
	int wordsAttributes[maxWords]; //ìàññèâ ïðèçíàêîâ ñëîâ:
		// 0 - àòðèáóò íå óñòàíîâëåí (ïî óìîë÷àíèþ);
		// 1 - ñëîâî ñîâïàäàåò ñ ïîñëåäíèì ñëîâîì ïðåäëîæåíèÿ;
		// 2 - ïîâòîðÿþùååñÿ ñëîâî;
		// 3 - íåïîâòîðÿþùååñÿ ñëîâî.
	Sentence(); //êîíñòðóêòîð
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
	Sentence* sentences[maxSentences]; //ìàññèâ èç óêàçàòåëåé íà ïðåäëîæåíèÿ â òåêñòå
	int nSentences; //ôàêòè÷åñêîå ÷èñëî ñëîâ â ïðåäëîæåíèè
	Sentence& operator[](int index); //ïåðåãðóçêà îïåðàòîðà èíäåêñàöèè
	int sentencesAttributes[maxSentences]; //ìàññèâ ïðèçíàêîâ ïðèäëîæåíèé:
	   // 0 - àòðèáóò íå óñòàíîâëåí (ïî óìîë÷àíèþ);
	   // 1 - ïîâåñòâîâàòåëüíîå ïðåäëîæåíèå;
	   // 2 - âîïðîñèòåëüíîå ïðåäëîæåíèå;
	   // 3 - âîñêëèöàòåëüíîå ïðåäëîæåíèå.
	Text(); //êîíñòðóêòîð
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
Sentence& Text::operator[](int index)
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
----------------------------
