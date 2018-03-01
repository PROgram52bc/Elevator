#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "eleGraphics/eleGraphics.h"

class Elevator 
{
	private:	
		void drawMe();
		int currentFloor;
		int maxFloor;
		elegraphics::Direction currentDirection;
	public:
		Elevator();
		~Elevator();
		void goUp();
		void goDown();
};

#endif
