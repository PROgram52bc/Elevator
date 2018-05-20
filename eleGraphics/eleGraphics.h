#ifndef ELEGRAPHICS_H
#define ELEGRAPHICS_H

#include <iostream>
#include <string>
#include <list>
#include "conio.h"
#include "section.h"
#include "../Customer.h"
/** \addtogroup elegraphics
  @{
  */
namespace elegraphics {
	/**************Constants*************/
	const int MAXFLOOR = 9; /**< the maximum floor number allowed.
							 Currently only allowing 9 because it 
							 is the biggest one-digit number.*/
	const int FLRHEIGHT = 4; /**< the height of each floor. */
	enum ElevatorState /** the state of the elevator */
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

	/**************Helper Functions****************/
	void drawFloor(int flr);
	void drawElevator(int floor, ElevatorState d);
	int getFlrTopRow(int flr);
	int getFlrBotRow(int flr);

	/**************Functions****************/
	void drawElevatorAndFloor(int flr, int max, ElevatorState d); 
	void drawCustomersInElevator(const list<Customer>& listCustomer, int floor); 
	// void drawCustomersOnFloor(int floor, list<Customer*>&);
	
	void clrscr();
}
/*
  @} end of doxygen group */
#endif
