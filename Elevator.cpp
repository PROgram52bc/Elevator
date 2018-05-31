#include "Elevator.h"
#include "EmptyError.h"

using namespace std;
/**********************Constructors*********************/
Elevator::Elevator(): 
	maxFloor(elegraphics::MAXFLOOR),
	maxCustomers(DEFAULT_MAX_CUSTOMER),
	customers(maxCustomers),
	currentFloor(1), 
	currentState(elegraphics::up) 
{ 
	drawMe();
}

Elevator::Elevator(int maxFlr):
	maxFloor(maxFlr),
	maxCustomers(DEFAULT_MAX_CUSTOMER),
	customers(maxCustomers),
	currentFloor(1),
	currentState(elegraphics::up)
{ 
	drawMe();
}


/**********************Methods definitions*********************/

void Elevator::drawMe() {
	elegraphics::drawElevatorAndFloor(currentFloor, maxFloor, currentState);
	elegraphics::drawCustomersInElevator(customers, currentFloor);
}


bool Elevator::goUp() 
{
	if (currentFloor == maxFloor)
		return false;
	currentState = elegraphics::up;
	currentFloor++;
	drawMe();
	return true;
}

bool Elevator::goDown()
{
	if (currentFloor == 1)
		return false;
	currentState = elegraphics::down;
	currentFloor--;
	drawMe();
	return true;
}

bool Elevator::isFull()
{
	return customers.isFull();
}

bool Elevator::getInCustomer(Customer c)
{
	bool result = customers.addCustomer(c);
	drawMe();
	return result;
}

bool Elevator::getOutCustomer()
{
	int d = this->currentFloor;
	try {
		customers.popCustomer(
				[d](Customer c) -> bool
				{
				return c.getDestinationFloor() == d;
				}); // try to pop a customer who already arrived
	}
	// if failed, return false
	catch (EmptyError) { return false; } 
	// if succeeded, redraw the elevator and return true
	drawMe();
	return true;
}
