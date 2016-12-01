#pragma once
#include<iostream>
#include<string>
#include<map>
#include<list>

using namespace std;

class Word {
public:
	Word(string word) {
		this->word = word;
	}
	~Word() {}

	string getWord() {
		return this->word;
	}

private:
	string word;
};