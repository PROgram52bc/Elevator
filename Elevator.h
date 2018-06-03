#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "CustomerList.h"
#include "eleGraphics/eleGraphics.h"

class Elevator 
{
	protected:
		/****Variables****/
		static const int DEFAULT_MAX_CUSTOMER = 9;
		Section section;
		const int maxFloor;
		const int maxCustomers;
		int currentFloor;
		CustomerList customers;
		elegraphics::ElevatorState currentState;

		/****Helpers Methods****/
		void drawMe();
	public:
		/****Constructor***/
		Elevator(int maxFlr = elegraphics::MAXFLOOR, Section s = elegraphics::secElevator);

		/****Mutators****/
		bool goUp();
		bool goDown();
		bool getInCustomer(Customer c);
		bool getOutCustomer();
		void setCurrentState(elegraphics::ElevatorState st);
		void incrementCustomers()
		{ customers.incrementCustomers(); }

		/****Observers****/
		bool isFull();
		int getCurrentFloor() { return currentFloor; }
		elegraphics::ElevatorState getCurrentState() { return currentState; }

};

#endif
