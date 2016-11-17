#pragma once
#include<Windows.h>
#include<iostream>
using namespace std;
// Key Event
class KeyEvent {
public:
	// constructor 
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	
	// get key 
	int getKey() {
		ReadConsoleInput(hln,&lnRec,1,&NumRead);
		if (lnRec.EventType == KEY_EVENT) {
			if (lnRec.EventType == KEY_EVENT) {
				if (lnRec.Event.KeyEvent.bKeyDown) {
					downKey = lnRec.Event.KeyEvent.wVirtualKeyCode;
					return downKey;
				}
				else {
					return -1;
				}
			}
		}
	}


private:
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD lnRec;
	DWORD NumRead;
	int downKey;

};
