
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
	Section secElevator(1,1, // starting x and y
						8,FLRHEIGHT*MAXFLOOR); // width and height
	Section secFloor(secElevator.col+secElevator.width, secElevator.row, // starting x, y
					 20, secElevator.height); // width and height

	/** @brief draw the floor frame */
	void drawFloor(int n) {
	//  123456789
	// 1#_|   |_
	// 2  |   |
	// 3  |   |
	// 4  v   v
	// 5
	// 6
	// 7
	// 8
	// 9
		if (n > MAXFLOOR)
			n = MAXFLOOR; // draw only until the max floor
		for (int i=1; i<=n; i++) // i indicates the floor number
		{
			int floorRow = (i-1)*FLRHEIGHT+1; // convert i to the actual row number from bottom
			secElevator.drawStrAt(to_string(i)+"_", 1, -1 * floorRow);
			secElevator.drawStrAt("_", -1, -1 * floorRow);
		}
	}

	namespace {
		string upElevator[] = {
			"^   ^",
			"|   |",
			"|   |",
			"|   |"
		};
		string downElevator[] = {
			"|   |",
			"|   |",
			"|   |",
			"v   v"
		};
		string openElevator[] = {
			"[   ]",
			"|   |",
			"|   |",
			"[   ]"
		};
	}

//	void drawElevator(int floor, Direction direction) {
//		string* pEle = nullptr;
//		switch (direction) {
//			case up:
//				pEle = upElevator;
//				break;
//			case down:
//				pEle = downElevator;
//				break;
//			case open:
//				pEle = openElevator;
//				break;
//		}
//
//		for (int row=0; row<FLRHEIGHT; row++)
//		{
//			cout << gotoRowCol(getRowNum(floor) + row, getColNum(floor))
//				<< pEle[row];
//		}
//		cout << gotoRowCol(BASEROW + 1,1);
//
//	}

	void clrscr() {
		cout << conio::clrscr();
	}

//	void drawElevatorAndFloor(int totalFloor, int floor, Direction direction) {
//		section_elevator.clrSection();
//		drawFloor(totalFloor);
//		drawElevator(floor, direction);
//	}

}
