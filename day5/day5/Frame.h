#pragma once
#include<iostream>
#include<string>
using namespace std;

class Frame {
public:
	Frame() {}

	void* operator new(size_t size) {
		cout << "Allocator with new operator" << endl;
		cout << "size : " << size<<endl;
		void* temp = malloc(size);

		if (!temp) {
			throw string("bad allocation");
		}

		return temp;
	}

	void* operator new[](size_t size) {
		cout << "Allocator with new[] operator " << endl;

		void *temp = malloc(size);

		if (!temp) {
			throw string("bad allocation");
		}
		return temp;
	}

	void operator delete(void* addr) {
		cout << "Free with delete operator" << endl;
		free(addr);
	}

	void operator delete[](void* addr) {
		cout << "Free with delete[] operator" << endl;
		free(addr);
	}

};
