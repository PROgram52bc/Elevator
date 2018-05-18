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

	/**************Functions****************/
	void drawFloor(int flr);
	void drawElevator(int floor, Direction d);
	void drawElevatorAndFloor(int flr, int max, Direction d); // a combined drawFloor and drawElevator, clearing partial screen automatically
	// void drawCustomersInElevator(int floor, Customer[] c); // Just a thought that might be used
	// void drawCustomersOnFloor(int floor, list<Customer*>&);
	void clrscr();
}
/*
  @} end of doxygen group */
#endif
