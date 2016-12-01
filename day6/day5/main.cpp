#include"Frame.h"
#include"ExArray.h"
#include"Word.h"
#include<vector>
#include<list>
#include<map>
#include<fstream>

template<typename T>
void mySwap(T& num1,T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

void dump(list<string> &l) {
	list<string>::iterator iter = l.begin();

	while (iter !=l.end()) {
		cout << *iter << endl;
		iter++;
	}
}

void main() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 50);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << "access index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);

	vector<int>::iterator iter = v.begin();

	cout << "access index at 1 with iterator" << iter[1]<<endl;

	while (iter != v.end()) {
		cout << *iter << endl;
		iter++;
	}

	list<string> names;
	names.insert(names.begin(), "Konkuk");
	names.insert(names.begin(), "University");
	names.insert(names.begin(), "SCLAB");
	names.insert(names.begin(), "CSY");
	dump(names);
	cout << "===" << endl;
	names.reverse();
	dump(names);

	map<string, int> m;

	// mapping a price with the destination
	m["seoul"] = 100;
	m["daegu"] = 120;
	m["busan"] = 200;

	cout << "Train to seoul = " << m["seoul"] << "$" << endl;
	cout << "Train to daegu = " << m["daegu"] << "$" << endl;
	cout << "Train to busan = " << m["busan"] << "$" << endl;

	map<char, list<Word>> m1;
	list<Word> aList;
	list<Word> bList;

	// add list
	aList.push_back(Word("apple"));
	aList.push_back(Word("appear"));

	bList.push_back(Word("bread"));
	bList.push_back(Word("bring"));
	bList.push_back(Word("bow"));

	// maping a list with the word 
	m1['a'] = aList;
	m1['b'] = bList;

	m1['a'].push_back(Word("appraisal"));
	m1['a'].push_back(Word("avoid"));

	list<Word>::iterator iter2 = aList.begin();

	while (iter2 != aList.end()) {
		cout << iter2->getWord() << endl;
		iter2++;
	}

	map<char, list<Word>>::const_iterator iter1 = m1.begin();


	// print all words in the map
	while (iter1 != m1.end()) {
		cout << iter1->first << ":" << endl; // key 값 출력

		list<Word> temp = iter1->second;	// value를 임시로 저장
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end()) {
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}

		cout << "\n===" << endl;
		iter1++;
	}

	// initialization and mapping with the new list
	for (int i = 0; i < 26; i++) {
		list<Word> temp;
		char c = 'a';
		m1[c++] = temp;
	}


	ifstream ifs;
	ifs.open("WordList.txt");

	if (!ifs) {
		cout << "Unable to open file" << endl;
	}

	string temp;
	while (ifs >> temp) {
		char first = temp[0];
		m1[first].push_back(temp);
	}

	ifs.close();
	iter1 = m1.begin();
	// print all words in the map
	while (iter1 != m1.end()) {
		cout << iter1->first << ":" << endl; // key 값 출력

		list<Word> temp = iter1->second;	// value를 임시로 저장
		list<Word>::const_iterator iter_list = temp.begin();

		while (iter_list != temp.end()) {
			Word word = *iter_list;
			cout << word.getWord() << ", ";
			iter_list++;
		}

		cout << "\n===" << endl;
		iter1++;
	}
	
}