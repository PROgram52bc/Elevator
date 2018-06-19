#include "Elevator.h"
#include "EmptyError.h"

using namespace std;
/**********************Constructors*********************/

Elevator::Elevator(int maxFlr, Section sec):
	maxFloor(maxFlr),
	maxCustomers(DEFAULT_MAX_CUSTOMER),
	customers(maxCustomers),
	currentFloor(1),
	currentDoorState(closed),
	currentDirection(none),
	section(sec)
{ 
	drawMe();
}


/**********************Methods definitions*********************/

void Elevator::drawMe() 
{
	elegraphics::drawElevatorAndFloor(currentFloor, maxFloor, currentDoorState, currentDirection, section);
	elegraphics::drawCustomersInElevator(customers, currentFloor, section);
}

bool Elevator::goUp() 
{
	if (currentDoorState == open)
		throw(std::runtime_error("Can't go up with door open."));
	if (currentFloor == maxFloor)
		return false;
	// currentDirection = up;
	currentFloor++;
	drawMe();
	return true;
}

bool Elevator::goDown()
{
	if (currentDoorState == open)
		throw(std::runtime_error("Can't go down with door open."));
	if (currentFloor == 1)
		return false;
	// currentDirection = down;
	currentFloor--;
	drawMe();
	return true;
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

bool Elevator::hasCustomerToGetOut() const 
{
	return hasCustomer(
			[=](Customer c) { return
			c.getDestinationFloor() == currentFloor;
			});
}

void Elevator::setCurrentDoorState(
		ElevatorDoorState ds)
{
	currentDoorState = ds;
	drawMe();
}
void Elevator::setCurrentDirection(
		ElevatorDirection dir)
{
	currentDirection = dir;
	drawMe();
}
