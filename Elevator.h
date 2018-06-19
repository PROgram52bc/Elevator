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
		ElevatorDoorState currentDoorState;
		ElevatorDirection currentDirection;

		/****Helper Methods****/
		void drawMe();
	public:
		/****Constructor***/
		Elevator(int maxFlr = elegraphics::MAXFLOOR, Section s = elegraphics::secElevator);

		/****Mutators****/
		bool goUp();
		bool goDown();
		bool getInCustomer(Customer c);
		bool getOutCustomer();
		bool hasCustomer(std::function<bool(Customer)> f) const
		{ return customers.hasCustomer(f); }
		bool hasCustomerToGetOut() const;
		void setCurrentDoorState(
				ElevatorDoorState st);
		void setCurrentDirection(
				ElevatorDirection st);
		void incrementCustomers()
		{ customers.incrementCustomers(); }

		/****Observers****/
		bool isFull() const
		{ return customers.isFull(); }
		int getCurrentFloor() const { return currentFloor; }
		ElevatorDoorState 
			getCurrentDoorState() const { return currentDoorState; }
		ElevatorDirection 
			getCurrentDirection() const { return currentDirection; }
};

#endif
