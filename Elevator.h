#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <list>
#include "eleGraphics/eleGraphics.h"

class Elevator 
{
	private:	
		void drawMe();
		int currentFloor;
		int maxFloor;
		list<Customer> customers;
		elegraphics::ElevatorState currentState;
	public:
		Elevator();
		~Elevator();
		void goUp();
		void goDown();
};

#endif
