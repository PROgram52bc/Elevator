#include <iostream>
#include "Elevator.h"
#include "eleGraphics/eleGraphics.h"
#include "eleGraphics/conio.h"

using namespace std;
/**********************Constructors*********************/
Elevator::Elevator(): 
	currentFloor(1), 
	maxFloor(elegraphics::MAXFLOOR),
	currentDirection(elegraphics::up)
{
	drawMe();
}


/**********************Destructors*********************/
Elevator::~Elevator() {}


/**********************Methods definitions*********************/

void Elevator::drawMe() {
	cout << conio::clrscr();
	elegraphics::drawFloor(maxFloor);
	elegraphics::drawElevator(currentFloor, currentDirection);
	cout << conio::gotoRowCol(elegraphics::BASEROW + 1,1);
}


void Elevator::goUp() 
{
	if (currentFloor == maxFloor)
		return;
	currentDirection = elegraphics::up;
	currentFloor++;
	drawMe();

}
void Elevator::goDown()
{
	if (currentFloor == 1)
		return;
	currentDirection = elegraphics::down;
	currentFloor--;
	drawMe();
}
