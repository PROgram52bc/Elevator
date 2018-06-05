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
		elegraphics::ElevatorDoorState currentDoorState;
		elegraphics::ElevatorDirection currentDirection;

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
		void setCurrentDoorState(
				elegraphics::ElevatorDoorState st);
		void setCurrentDirection(
				elegraphics::ElevatorDirection st);
		void incrementCustomers()
		{ customers.incrementCustomers(); }

		/****Observers****/
		bool isFull() const
		{ return customers.isFull(); }
		int getCurrentFloor() const { return currentFloor; }
		elegraphics::ElevatorDoorState 
			getCurrentDoorState() const { return currentDoorState; }
		elegraphics::ElevatorDirection 
			getCurrentDirection() const { return currentDirection; }

};

#endif
