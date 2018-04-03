
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
	void drawFloor(int n) {
		if (n > MAXFLOOR)
			n = MAXFLOOR;
		for (int i=0; i<n; i++)
		{
			if (i % LABELPERFLR == 0) // for every 5 floor, print floor number
				cout << gotoRowCol(BASEROW - FLRHEIGHT * i, 1) << i+1;
			cout << gotoRowCol(BASEROW - FLRHEIGHT * i, 1 + LEFTMARGIN) << "_"
				<< string(FLRWIDTH, ' ') << "_";
		}
		cout << gotoRowCol(BASEROW + 1,1);
	}

	namespace {
		string upElevator[] = {
			"^^",
			"||"
		};
		string downElevator[] = {
			"||",
			"vv"
		};
		string openElevator[] = {
			"[]",
			"[]"
		};
		// section_elevator is only visible in the elegraphics namespace (encapsulated)
		Section section_elevator(6, 1, 4, 22);
	}

	void drawElevator(int floor, Direction direction) {
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

		for (int row=0; row<FLRHEIGHT; row++)
		{
			cout << gotoRowCol(getRowNum(floor) + row, getColNum(floor))
				<< pEle[row];
		}
		cout << gotoRowCol(BASEROW + 1,1);

	}

	void clrscr() {
		cout << conio::clrscr();
	}

	void Section::clrSection() {
		for (int i=0; i<height; i++)
		{
			cout << gotoRowCol(row+i, col);
			for (int nspace=0; nspace<width; nspace++)
				cout << " " << flush;
		}
	}

	void drawElevatorAndFloor(int totalFloor, int floor, Direction direction) {
		section_elevator.clrSection();
		drawFloor(totalFloor);
		drawElevator(floor, direction);
	}

}
