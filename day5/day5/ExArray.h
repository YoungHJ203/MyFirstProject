#pragma once
#include<iostream>
using namespace std;

template<class T>
class ExArray{
public:
	ExArray(int s) {
		a = new T[size=s];
		
	}

	void addData(T data) {
		for (int i = 0; i < size; i++) {
			a[i] = data;
		}
	}

	void printData() {
		for (int i = 0; i < size; i++) {
			cout << a[i] << ",";
		}
		cout << endl;
	}

private:
	T* a;
	int size;
};