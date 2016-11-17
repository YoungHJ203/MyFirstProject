#include<process.h>
#include<iostream>
#include"KeyEvent.h"
#include"Game.h"
using namespace std;

// system function _ print the number every 0.5 second
unsigned int __stdcall mythread(void*) {
	int i = 0;
	while (1) {
		cout << GetCurrentThreadId() << ": " << i++<<endl;
		Sleep(500);
	}

	return 0;
}

// system function_ get key
unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getKey();
		switch (i) {
		case 37: {cout << "Left key is pressed" << endl; break; }
		case 38: {cout << "Up key is pressed" << endl; break; }
		case 39: {cout << "Right key is pressed" << endl; break; }
		case 40: {cout << "Down key is pressed" << endl; break; }
		}
	}

	return 0;
}

Game* game = new Game();
// system function _ move the cursor
unsigned int __stdcall mythread1(void*) {
	int i = 0;
	while (1) {
		game->move();
		Sleep(500);
	}

	return 0;
}

// system function _ get key
unsigned int __stdcall keyEvent1(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getKey();
		if (i != -1) game->setDirection(i);
	}

	return 0;
}


int main(){

	HANDLE handleA, handleB;
	
	// make thread
	handleA = (HANDLE)_beginthreadex(0,0,&mythread1,(void*)0,0,0);
	handleB = (HANDLE)_beginthreadex(0,0,&keyEvent1,(void*)0,0,0);

	// run thread
	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);
	
	// close thread
	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}
