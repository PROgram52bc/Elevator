#ifndef ELEGRAPHICS
#define ELEGRAPHICS

#include <iostream>
#include <string>
#include "conio.h"
namespace eleGraphics {

	/**************Constants*************/
	const int MAXFLOOR = 10; // the maximum floor number allowed
	const int MAXFLOORPERCOL = 10; // the maximum floor number per column
	const int LABELPERFLR = 5; // print floor number for every LABELPERFLR floors
	const int BASEROW = 22; // the row number for floor 1
	const int FLRWIDTH = 2; // the width of a floor/ available space for elevator
	const int FLRHEIGHT = 2; // the height of a floor
	const int LEFTMARGIN = 5; // the margin on the left for numbering
	enum Direction { up, down, open };
	/**************Functions****************/
	void drawFloor(int);
	void drawElevator(int floor, Direction d);
	namespace {
		/*
		   Let's make the coordinate for elevator always the upper left corner!
		   _  _
			!*
		   _**_

		   '!' is the coordinate we are getting.
	   */

		int getRowNum(int floor) {
			return BASEROW + 1 - floor * (FLRHEIGHT);
		}
		int getColNum(int floor) {
			return 2 + LEFTMARGIN;
		}
	}
}
#endif
