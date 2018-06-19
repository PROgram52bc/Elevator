#ifndef SIGNALEDELEVATOR_CPP
#define SIGNALEDELEVATOR_CPP

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

/**@brief move the elevator according to the requests made
 * and get out Customers who have arrived at destination
 */
template <class core>
bool SignaledElevator<core>::move() 
{
	if (elevator.getCurrentDoorState() == open)
	{
		if (!getOutCustomer())
		{
			signalCore->popSignal();
			setDirection();
			elevator.setCurrentDoorState(closed);
		}
			return true;
	}
	if (signalCore->isEmpty())
	{
		setDirection();
		return false;
	}
	else // if signalCore not empty
	{
		setDirection();
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
			elevator.setCurrentDoorState(open);
		}
		return true;
	}
}

template <class core>
void SignaledElevator<core>::addSignal(int flr, SignalCore_B::Direction dir)
{
	signalCore->addSignal(elevator.getCurrentFloor(), flr, dir);
}

/**@brief set elevator state according to the next direction
 * in signalList
 */
template <class core>
void SignaledElevator<core>::setDirection()
{
	if (signalCore->isEmpty())
		/* When there is no more signal
		 * set direction to none */
	{
		elevator.setCurrentDirection(none);
		return;
	}
	/* next signal's floor number */
	int sigFloor = signalCore->getSignal();
	/* current floor number */
	int currFloor = elevator.getCurrentFloor();
	/* next signal's direction */
	SignalCore_B::Direction 
		sigDir = signalCore->getDirection();
	/* the elevator's direction to be set */
	ElevatorDirection 
		dirToBeSet;

	if (sigFloor == currFloor)
		/* When arrived at the next signal,
		 * set direction according to the signal's direction */
	{
		if (sigDir == SignalCore_B::both)
			dirToBeSet = none;
		else if (sigDir == SignalCore_B::up)
			dirToBeSet = up;
		else if (sigDir == SignalCore_B::down)
			dirToBeSet = down;
	}
	else /* if signalCore->getSignal() != getCurrentFloor() */
		/* When not yet arrived at the next signal, 
		 * set direction based on the positions
		 * of the next signal and the current floor */
//	{
//		if (sigDir == SignalCore_B::both)
//			/* Only when the next signal
//			 * is from inside the elevator */
//		{
			if (sigFloor > currFloor)
				dirToBeSet = up;
			else /* if sigFloor < currFloor */
				dirToBeSet = down;
//		}
//		else
//		{
//			dirToBeSet = none;
//		}
//	}
	elevator.setCurrentDirection(dirToBeSet);
}

/**@brief check if there are customer to get out at current floor */
template <class core>
bool SignaledElevator<core>::hasCustomerToGetOut() const
{
	int currentFloor = elevator.getCurrentFloor();
	return elevator.hasCustomer(
			[currentFloor](Customer c) { return 
			c.getDestinationFloor() == currentFloor;
			});
}

#endif
