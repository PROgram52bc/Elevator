
/*
 * A preliminary library for graphing the elevator simulator
 */

#include <iostream>
#include <string>
#include "conio.h"
#include "eleGraphics.h"

using namespace std;
using namespace conio;



namespace elegraphics {
	
	const int elevatorWidth = 10; /**< Width of the elevator section */
	const int queueWidth = 20; /**< Width of the customer queue */

	Section secElevator(1,1, // starting x and y
						elevatorWidth,FLRHEIGHT*MAXFLOOR); // width and height
	Section secFloor(secElevator.getConsecutiveCol(), secElevator.getStartRow(), // starting x, y
					 queueWidth, secElevator.getHeight()); // width and height

	/** @brief draw the floor frame */
	void drawFloor(int n) {
		if (n > MAXFLOOR)
			n = MAXFLOOR; // draw only until the max floor
		for (int i=1; i<=n; i++) // i indicates the floor number
		{
			int floorRow = (i-1)*FLRHEIGHT+1; // convert i to the actual row number from bottom
			secElevator.drawStrAt(to_string(i)+"_", 1, -1 * floorRow);
			secElevator.drawStrAt("_", -1, -1 * floorRow);
		}
	}

	string upElevator[] = {
		"^     ^",
		"|     |",
		"|     |",
		"|     |"
	};
	string downElevator[] = {
		"|     |",
		"|     |",
		"|     |",
		"v     v"
	};
	string openElevator[] = {
		"[     ]",
		"|     |",
		"|     |",
		"[     ]"
	};

void drawElevator(int floor, int maxFloor, Direction direction) {
	string* pEle = nullptr;
	switch (direction) {
		case up:
			pEle = upElevator;
			break;
		case down:
			pEle = downElevator;
			break;
		case open:
			pEle = openElevator;
			break;
	}

	int numRowFromBottom = floor*FLRHEIGHT;
	int floorRow = -1 * numRowFromBottom; // convert floor to the actual row number from bottom
	for (int strRowNum=0; strRowNum<FLRHEIGHT; strRowNum++) /**< tracking the line number in the elevator string array */
	{
		secElevator.drawStrAt(pEle[strRowNum], 3, floorRow, conio::GREEN);
		floorRow++; // increment negative index -> absolute value smaller -> going down
	}
	cout << gotoRowCol(	secElevator.getConsecutiveRow(),
						secElevator.getStartCol());

}

void clrscr() {
	cout << conio::clrscr();
}

void drawElevatorAndFloor(int floor, int maxFloor, Direction direction) {
	secElevator.clrSection();
	drawFloor(maxFloor);
	drawElevator(floor, maxFloor, direction);
}
}
