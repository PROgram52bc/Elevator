#include "SignalCore_Normal.h" 
#include "EmptyError.h"

SignalCore_Normal::SignalCore_Normal() {}
SignalCore_Normal::~SignalCore_Normal() {}

/**@brief Add a customer request signal to the queue */
void SignalCore_Normal::addSignal(int currentFloor, int signal, SignalCore_B::Direction direction) 
{
	if (signalList.empty()) 
		/* if empty, insert the signal at the beginning */
	{
		signalList.push_front(Signal(signal, direction));
		return;
	}

	if (signal == currentFloor && 
			good_direction(
				direction,
				currentFloor, 
				signalList.front().floor)) 
		/* if signal given IS the current floor 
		 * and the direction given is same as the current direction 
		 * insert at the beginning */
	{
		signalList.push_front(Signal(signal, direction));
		return;
	}
	if (currentFloor == signalList.front().floor)
		/* if the next target is the same as current floor 
		 * (in other words, the elevator is stopped 
		 * and loading customers, in which case we should
		 * definitely not add the signal in the front
		 * of the list)*/
	{
		_iterateInsert(signal, direction);
		return;
	}
	/* Set up a general testing 
	 * whether or not to insert in the front of the list */
	SignalCore_B::Direction currentDirection;
	if (currentFloor < signalList.front().floor)
		currentDirection = SignalCore_B::up;
	else
		currentDirection = SignalCore_B::down;
	if (insertable(
				Signal(currentFloor, currentDirection),
				signalList.front(),
				Signal(signal, direction)))
		/* if insertable at the beginning,
		 * add to the beginning of the list */
	{
		signalList.push_front(Signal(signal, direction));
		return;
	}

	/* if not inserted until here, do iterate insert */
	_iterateInsert(signal,direction);

}

/**@brief a general tester for signalCore_Normal
 * @bug if curr is the same as next, undefined retval
 * @bug if toBeInserted is the same as curr, undefined retval
 * @bug if toBeInserted is the same as next, undefined retval 
 * @bug if toBeInserted.direction is both, undefined retval
 * @return true if toBeInserted can be inserted between curr and next */
bool SignalCore_Normal::insertable(Signal curr, Signal next, Signal toBeInserted)
{
	if (in_between(
				toBeInserted.floor, 
				curr.floor, 
				next.floor) &&
			good_direction(
				toBeInserted.direction,
				curr.floor, 
				next.floor
				))
		/* if it is in between it and next, 
		 * and on the same direction,
		 * insert after the current one */
		return true;
	if (!same_direction(
				next.direction,
				curr.floor,
				next.floor) &&
			next.direction == 
			toBeInserted.direction &&
			same_direction(
				next.direction,
				toBeInserted.floor,
				next.floor)
	   ) 
		/* if changing direction at next 
		 * and the signal's direction is same as next
		 * and the signal can be covered before next,
		 * insert after the current one */
		return true;
	return false;
	
}
/**@brief responsible for inserting the signal somewhere after the first signal in the list 
 * @warning when calling this method, signalList can't be empty!
 *
 */
void SignalCore_Normal::_iterateInsert(int signal, SignalCore_B::Direction direction)
{
	auto it = signalList.begin();
	while (1)
	{
		if (signal == it->floor) 
		{
			if (direction == it->direction)
				/* if the exact same signal sent, do nothing */
				return;
			if (it->direction == SignalCore_B::both ||
					direction == SignalCore_B::both)
				/* if floor request are the same
				 * and at least one of the directions
				 * is "both,"
				 * combine the two signals,
				 * up/down has priority over both
				 */
			{
				if (it->direction == SignalCore_B::both)
					it->direction = direction;
				return;
			}
		}
		if (next(it) == signalList.end())
			/* if this is the last signal, insert after it */
		{
			signalList.insert_after(it, Signal(signal,direction));
			return;
		}
		if (insertable(
					*it,
					*next(it),
					Signal(signal, direction)))
			/* if it is insertable between it and next(it)
			 * insert after it. */
		{
			signalList.insert_after(it, Signal(signal,direction));
			return;
		}
		it++;
		continue;
	}
	return;
}

void SignalCore_Normal::popSignal() 
{ 
	if (isEmpty()) throw (EmptyError("SignalList empty, can't pop signal."));
	signalList.pop_front();
}

/**@brief get the next request's floor number */
int SignalCore_Normal::getSignal() const 
{ 
	if (isEmpty()) throw (EmptyError("SignalList empty, can't get signal."));
	return signalList.front().floor; 
}

/**@brief get the next request's direction */
SignalCore_B::Direction SignalCore_Normal::getDirection() const
{ 
	if (isEmpty()) throw (EmptyError("SignalList empty, can't get direction."));
	return signalList.front().direction; 
}
