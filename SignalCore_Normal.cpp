#include "SignalCore_Normal.h" 
#include "EmptyError.h"

SignalCore_Normal::SignalCore_Normal() {}
SignalCore_Normal::~SignalCore_Normal() {}

/**@brief Add a customer request signal to the queue */
void SignalCore_Normal::addSignal(int currentFloor, int signal, SignalCore_B::Direction direction) {
	if ( signalList.empty() || // if empty, insert the signal right away
		(signal == currentFloor || // if signal is the current floor, and it's going in the same direction 
		in_between(signal, currentFloor, signalList.front().floor))
	&& 	good_direction(currentFloor, signalList.front().floor, direction) )// or if signal in between current floor and the next, and it is in the right direction, insert the signal right away (at the front)
	{
		signalList.push_front(Signal(signal, direction));
		return;
	}
	// new signal should be inserted AFTER the first signal in the list
	auto it = signalList.begin();
	while (1) 
	{
		if (signal == it->floor) // if the same signal sent, do nothing
			return;
		if (next(it) == signalList.end() || // if this is the last signal, insert after it
			in_between(signal, it->floor, next(it)->floor) &&
			good_direction(it->floor, next(it)->floor, direction)) // or if it is in between and on the same direction, insert after the current one
		{
			signalList.insert_after(it, Signal(signal,direction));
			return;
		}
		// otherwise, set iterator to the next one, start over again
		it++;
		continue;
	}
	return;
}

void SignalCore_Normal::popSignal() 
{ 
	if (isEmpty()) throw (EmptyError("signalList empty, can't pop signal."));
	signalList.pop_front();
}
int SignalCore_Normal::getSignal() const 
{ 
	if (isEmpty()) throw (EmptyError("signalList empty, can't get signal."));
	return signalList.front().floor; 
}
