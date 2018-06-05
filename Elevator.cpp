#include "Elevator.h"
#include "EmptyError.h"

using namespace std;
/**********************Constructors*********************/

Elevator::Elevator(int maxFlr, Section sec):
	maxFloor(maxFlr),
	maxCustomers(DEFAULT_MAX_CUSTOMER),
	customers(maxCustomers),
	currentFloor(1),
	currentDoorState(elegraphics::closed),
	currentDirection(elegraphics::none),
	section(sec)
{ 
	drawMe();
	elegraphics::secConsoleOut.sendMsg("elevator created!");
}


/**********************Methods definitions*********************/

void Elevator::drawMe() 
{
	elegraphics::drawElevatorAndFloor(currentFloor, maxFloor, currentDoorState, currentDirection, section);
	elegraphics::drawCustomersInElevator(customers, currentFloor, section);
}

bool Elevator::goUp() 
{
	if (currentDoorState == elegraphics::open)
		throw(std::runtime_error("Can't go up with door open."));
	if (currentFloor == maxFloor)
		return false;
	// currentDirection = elegraphics::up;
	currentFloor++;
	drawMe();
	return true;
}

bool Elevator::goDown()
{
	if (currentDoorState == elegraphics::open)
		throw(std::runtime_error("Can't go down with door open."));
	if (currentFloor == 1)
		return false;
	// currentDirection = elegraphics::down;
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

void Elevator::setCurrentDoorState(
		elegraphics::ElevatorDoorState ds)
{
	currentDoorState = ds;
	drawMe();
}
void Elevator::setCurrentDirection(
		elegraphics::ElevatorDirection dir)
{
	currentDirection = dir;
	drawMe();
}
