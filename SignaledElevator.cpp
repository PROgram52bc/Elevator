#ifndef SIGNALEDELEVATOR_CPP
#define SIGNALEDELEVATOR_CPP
#include "SignaledElevator.h"

/**@brief constructor */
template <class core>
SignaledElevator<core>::SignaledElevator(int maxFlr, Section sec):
	elevator(maxFlr, sec)
{
	signalCore = new core;
}

/**@brief destructor */
template <class core>
SignaledElevator<core>::~SignaledElevator()
{
	delete signalCore;
}

/**@brief move the elevator according to the requests made*/
template <class core>
bool SignaledElevator<core>::move() 
{
	if (elevator.getCurrentDoorState() == elegraphics::open)
	{
		signalCore->popSignal();
		elevator.setCurrentDoorState(elegraphics::closed);
		return true;
	}
	if (signalCore->isEmpty())
	{
		setDirection();
		return false;
	}
	else // if signalCore not empty
	{
		int nextFloor = signalCore->getSignal();
		int currentFloor = elevator.getCurrentFloor();
		if (nextFloor > currentFloor)
		{
			elevator.goUp();
		}
		else if (nextFloor < currentFloor)
		{
			elevator.goDown();
		}
		else // if nextFloor == currentFloor
		{
			elevator.setCurrentDoorState(elegraphics::open);
			setDirection();
		}
		return true;
	}
}

template <class core>
void SignaledElevator<core>::addSignal(int flr, SignalCore_B::Direction dir)
{
	signalCore->addSignal(elevator.getCurrentFloor(), flr, dir);
}

template <class core>
void SignaledElevator<core>::setDirection()
{
	if (signalCore->isEmpty() || 
			signalCore->getDirection() == SignalCore_B::both)
		elevator.setCurrentDirection(elegraphics::none);
	else if (signalCore->getDirection() == SignalCore_B::up)
		elevator.setCurrentDirection(elegraphics::up);
	else if (signalCore->getDirection() == SignalCore_B::down)
		elevator.setCurrentDirection(elegraphics::down);
}

#endif
