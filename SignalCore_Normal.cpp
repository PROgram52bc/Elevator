#include "SignalCore_Normal.h" 
#include "EmptyError.h"
#include <string>

SignalCore_Normal::SignalCore_Normal() {}
SignalCore_Normal::~SignalCore_Normal() {}
/**@brief check if the signal can be inserted at the beginning */
bool SignalCore_Normal::_insertableAtBeginning(
		int currentFloor,
		int signal,
		SignalCore_B::Direction direction) const
{
	if (signalList.empty()) 
		/* if empty, insert the signal at the beginning */
		return true;
	if (signal == currentFloor && 
			_good_direction(
				direction,
				currentFloor, 
				signalList.front().floor)) 
		/* if signal given IS the current floor 
		 * and the direction given is same as the current direction 
		 * insert at the beginning */
		return true;
	if (currentFloor == signalList.front().floor)
		/* if the next target is the same as current floor 
		 * (in other words, the elevator is stopped 
		 * and loading customers, in which case we should
		 * definitely not add the signal in the front
		 * of the list)*/
		return false;
	/* Set up a general testing 
	 * whether or not to insert in the front of the list */
	SignalCore_B::Direction currentDirection;
	if (currentFloor < signalList.front().floor)
		currentDirection = SignalCore_B::up;
	else
		currentDirection = SignalCore_B::down;
	if (_insertable(
				Signal(currentFloor, currentDirection),
				signalList.front(),
				Signal(signal, direction)))
		/* if insertable at the beginning,
		 * add to the beginning of the list */
		return true;
	return false;
}

/**@brief Add a customer request signal to the queue */
void SignalCore_Normal::addSignal(int currentFloor, int signal, SignalCore_B::Direction direction) 
{
	if (_insertableAtBeginning(currentFloor, signal, direction))
		/* if can be inserted at the beginning, do it */
	{
		signalList.push_front(Signal(signal, direction));
		return;
	}
	/* if not insertable at beginning, get a postion to insert */
	auto itPos = 
		getInsertPosition(Signal(signal, direction));
	if (_combinable(
				*itPos,
				Signal(signal, direction)))
		/* if this signal can be combined,
		 * combine it. */
	{
		_combineInsert(
				itPos,
				Signal(signal, direction));
	}
	else
		/* if cannot be combined,
		 * push it after the current signal */
	{
		signalList.insert_after(
				itPos,
				Signal(signal,direction));
	}

}

/**@brief a general tester for signalCore_Normal
 * @return true if toBeInserted can be inserted between curr and next */
bool SignalCore_Normal::_insertable(Signal curr, Signal next, Signal toBeInserted) const
{
	if (_in_between(
				toBeInserted.floor, 
				curr.floor, 
				next.floor) &&
			_good_direction(
				toBeInserted.direction,
				curr.floor, 
				next.floor
				))
		/* if it is in between it and next, 
		 * and on the same direction,
		 * insert after the current one */
		return true;
	if (!_same_direction(
				next.direction,
				curr.floor,
				next.floor) &&
			(
			 next.direction == toBeInserted.direction
			 ||
			 toBeInserted.direction == SignalCore_B::both
			) &&
			_same_direction(
				next.direction,
				toBeInserted.floor,
				next.floor)
	   ) 
		/* if changing direction at next 
		 * and the signal's direction is same as next
		 * (or is both -- pushed from the inside)
		 * and the signal can be covered before next,
		 * insert after the current one */
		return true;
	return false;
	
}

/**@brief combine the given signal with the existing signal
 */
void SignalCore_Normal::_combineInsert(
		std::forward_list<SignalCore_Normal::Signal>::iterator it, 
		Signal toBeCombined)
{
	if (toBeCombined.direction == it->direction)
		/* if the exact same signal sent, do nothing */
		return;
	if (it->direction == SignalCore_B::both || 
			toBeCombined.direction == SignalCore_B::both)
		/* if floor request are the same
		 * and at least one of the directions
		 * is "both,"
		 * combine the two signals,
		 * up/down has priority over both
		 */
	{
		if (it->direction == SignalCore_B::both)
			it->direction = toBeCombined.direction;
		return;
	}
	else
		throw(
				std::logic_error("Signal 1: floor(" +
					std::to_string(it->floor) + "), " + 
					"direction(" +
					std::to_string(it->direction) + ") " +
					"can't be combined with " +
					"Signal 2: floor(" +
					std::to_string(toBeCombined.floor) + ")" +
					"direction(" +
					std::to_string(toBeCombined.direction) + ") "
					));
}

/**@brief get the position for inserting a signal
 * @warning _insertableAtBeginning() should be called
 * prior to calling this method to check if it's possible 
 * to insert at the beginning.
 * @return an iterator to signalList, indicating the position
 * either to be replaced or to be inserted after
 */
std::forward_list<SignalCore_Normal::Signal>::iterator 
	SignalCore_Normal::getInsertPosition(Signal sig)
{
	for (auto it = signalList.begin();
			it != signalList.end();
			++it)
	{
		if (
				next(it) == signalList.end()
			/* if it is the last signal, return it. */
				||
				_combinable(*it, sig)
			/* if sig can be combined with *it, return it */
				|| 
				_insertable(
					*it,
					*next(it),
					sig))
			/* if sig is insertable between it and next(it),
			 * return it. */
		{
			return it;
		}
	}
	throw(std::logic_error(
				"Cannot get a valid position to insert signal."));
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
