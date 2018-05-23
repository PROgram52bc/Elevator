#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "CustomerList.h"
#include "eleGraphics/eleGraphics.h"

class Elevator 
{
	protected:

		/****Variables****/
		static const int DEFAULT_MAX_CUSTOMER = 9;
		const int maxFloor;
		const int maxCustomers;
		int currentFloor;
		CustomerList customers;
		elegraphics::ElevatorState currentState;

		/****Helpers Methods****/
		void drawMe();
	public:
		/****Constructor***/
		Elevator();
		Elevator(int);

		/****Mutators****/
		void goUp();
		void goDown();
		bool getInCustomer(Customer c);
		bool getOutCustomer();

		/****Observers****/
		bool isFull();
		int getCurrentFloor() { return currentFloor; }
		elegraphics::ElevatorState getCurrentState() { return currentState; }

};

#endif
