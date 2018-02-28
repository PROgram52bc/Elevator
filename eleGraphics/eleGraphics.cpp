
/*
 * A preliminary library for graphing the elevator simulator
 */

#include <iostream>
#include <string>
#include "conio.h"
#include "eleGraphics.h"

using namespace std;
using namespace conio;

namespace eleGraphics {
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

	}

	
}
