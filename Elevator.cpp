#include "Elevator.h"

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


void Elevator::goUp() 
{
	if (currentFloor == maxFloor)
		return;
	currentState = elegraphics::up;
	currentFloor++;
	drawMe();

}

void Elevator::goDown()
{
	if (currentFloor == 1)
		return;
	currentState = elegraphics::down;
	currentFloor--;
	drawMe();
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
	Customer targetCustomer = customers.popCustomer(
			[d](Customer c) -> bool
			{
				return c.destinationFloor == d;
			}); // pop a customer who already arrived
	drawMe();
	if (targetCustomer.destinationFloor != -1)
		return true;
	else 
		return false;
}
