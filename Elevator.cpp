#include <iostream>
#include "Elevator.h"
#include "eleGraphics/eleGraphics.h"

using namespace std;
/**********************Constructors*********************/
Elevator::Elevator(): 
	currentFloor(1), 
	maxFloor(elegraphics::MAXFLOOR),
	currentState(elegraphics::up)
{
	drawMe();
}


/**********************Destructors*********************/
Elevator::~Elevator() {}


/**********************Methods definitions*********************/

void Elevator::drawMe() {
	elegraphics::drawElevatorAndFloor(currentFloor, maxFloor, currentState);
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
