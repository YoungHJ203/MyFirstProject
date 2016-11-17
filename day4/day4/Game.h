#include<Windows.h>
#include<iostream>
using namespace std;
// Game class
class Game {
private:
	int x;		// x position
	int y;		// y position
	int direction;	// direction that is enterd

	// cursor position
	void gotoXY(int x, int y) {
		COORD pos = {x,y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

public:
	// constructor
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	}
	
	// set direction
	void setDirection(int i) {
		direction = i;
	}
	
	// move the cursor
	void move() {
		if (direction == 37) {
			x--;
		}
		else if (direction == 38) {
			y--;
		}
		else if (direction == 39) {
			x++;
		}
		else if (direction == 40) {
			y++;
		}
		// print the current postion
		system("cls");
		this->gotoXY(x, y);
		cout << x << " " << y << "бс";
	}

	
	
};
