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
	if (elevator.getCurrentState() == elegraphics::open)
	{
		signalCore->popSignal();
		setState();
		return true;
	}
	if (!signalCore->isEmpty()) {
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
			elevator.setCurrentState(elegraphics::open);
		}
		return true;
	}
	return false;
}

template <class core>
void SignaledElevator<core>::addSignal(int flr, SignalCore_B::Direction dir)
{
	signalCore->addSignal(elevator.getCurrentFloor(), flr, dir);
}

template <class core>
void SignaledElevator<core>::setState()
{
	if (signalCore->isEmpty())
	{
		elevator.setCurrentState(elegraphics::closed);
		return;
	}
	int nextFloor = signalCore->getSignal();
	int currentFloor = elevator.getCurrentFloor();
	if (nextFloor == currentFloor)
	{
		throw (std::logic_error("Can't set state with the target floor == current floor."));
	}
	if (nextFloor > currentFloor)
	{
		elevator.setCurrentState(elegraphics::up);
		return;
	}
	if (nextFloor < currentFloor)
	{
		elevator.setCurrentState(elegraphics::down);
		return;
	}
}

#endif
