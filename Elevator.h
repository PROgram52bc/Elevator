#ifndef ELEVATOR
#define ELEVATOR

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
