#ifndef ELEGRAPHICS_H
#define ELEGRAPHICS_H

#include <iostream>
#include <string>
#include "conio.h"
#include "section.h"
#include "consoleSection.h"
#include "../Customer.h"
#include "../CustomerList.h"
#include "../ElevatorState.h"
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
	const int CONSOLEINWIDTH = 30; /**< Width of input section */
	const int CONSOLEINHEIGHT = 5; /**< Height of input section */
	const int CONSOLEOUTWIDTH = 30; /**< Width of output setion */
	extern Section secElevator;
	extern Section secElevatorB;
	extern Section secFloor;
	extern ConsoleSection secConsoleIn;
	extern ConsoleSection secConsoleOut;

	/**************Helper Functions****************/
	void drawCustomers(const CustomerList& listCustomer, Section sec, int numPerRow, int maxCustomer = 20, int startCol = 1, int startRow = 1);
	void drawFloor(int flr, Section sec = secElevator);
	void drawElevator(int floor, ElevatorDoorState ds, ElevatorDirection dir, Section sec);
	int getFlrTopRow(int flr);
	int getFlrBotRow(int flr);

	/**************Functions****************/
	void drawElevatorAndFloor(int floor, int maxFloor, ElevatorDoorState ds, ElevatorDirection dir, Section sec);
	void drawCustomersInElevator(const CustomerList& listCustomer, int floor, Section sec = secElevator); 
	void drawCustomersOnFloor(const CustomerList& listCustomer, int floor, Section sec = secFloor);
	
	void clrscr();
}
/*
  @} end of doxygen group */
#endif
