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
	const int ELEVATORWIDTH = 10; /**< Width of the elevator section */
	const int QUEUEWIDTH = 20; /**< Width of the customer queue */
	const int CONSOLEWIDTH = 30;
	const int CONSOLEHEIGHT = 5;
	enum ElevatorState /** the state of the elevator */
	{ 	up, 	/**< when the elevator is going upward */
		down, 	/**< when the elevator is going down */
		open 	/**< when the elevator's door is open */
	}; 
	extern Section secElevator;
	extern Section secElevatorB;
	extern Section secFloor;
	extern Section secConsole;

	/**************Helper Functions****************/
	void drawFloor(int flr, Section sec = secElevator);
	void drawElevator(int floor, ElevatorState d, Section sec = secElevator);
	int getFlrTopRow(int flr);
	int getFlrBotRow(int flr);

	/**************Functions****************/
	void drawElevatorAndFloor(int flr, int max, ElevatorState d, Section sec = secElevator); 
	void drawCustomersInElevator(const list<Customer>& listCustomer, int floor, Section sec = secElevator); 
	void drawCustomersOnFloor(const list<Customer>& listCustomer, int floor, Section sec = secFloor);
	
	void clrscr();
}
/*
  @} end of doxygen group */
#endif
