#ifndef ELEGRAPHICS_H
#define ELEGRAPHICS_H

#include <iostream>
#include <string>
#include "conio.h"
#include "section.h"
/** \addtogroup elegraphics
  @{
  */
namespace elegraphics {
	/**************Constants*************/
	const int MAXFLOOR = 9; /**< the maximum floor number allowed.
							 Currently only allowing 9 because it 
							 is the biggest one-digit number.*/
	const int FLRHEIGHT = 4; /**< the height of each floor. */
	enum Direction /** the state of the elevator */
	{ 	up, 	/**< when the elevator is going upward */
		down, 	/**< when the elevator is going down */
		open 	/**< when the elevator's door is open */
	}; 

	Section secElevator(2,1, // starting x and y
						7,FLRHEIGHT*MAXFLOOR); // width and height
	Section secFloor(secElevator.col+secElevator.width, secElevator.row, // starting x, y
					 20, secElevator.height); // width and height
					



	/**************Functions****************/
	void drawFloor(int);
	void drawElevator(int floor, Direction d);
	void drawElevatorAndFloor(int, int, Direction); // a combined drawFloor and drawElevator, clearing partial screen automatically
	// void drawCustomerInElevator(int floor, Customer[] c); // Just a thought that might be used
	void clrscr();
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
/*
  @} end of doxygen group */
#endif
