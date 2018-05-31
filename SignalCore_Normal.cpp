#include "SignalCore_Normal.h" 

SignalCore_Normal::SignalCore_Normal() {}
SignalCore_Normal::~SignalCore_Normal() {}

/**@brief Add a customer request signal to the queue */
void SignalCore_Normal::addSignal(int currentFloor, int signal, SignalCore_B::Direction direction) {
//	if ( signalList.empty() || // if empty insert the signal right away
//		(signal == currentFloor || // if signal is the current floor, and it's going in the same direction 
//		in_between(signal, currentFloor, signalList.front()))
//	&& 	same_direction(currentFloor, signalList.front(), direction) )// or if signal in between current floor and the next, and it is in the right direction, insert the signal right away (at the front)
//	{
//		signalList.push_front(signal);
//		return;
//	}
//	// new signal should be inserted AFTER the first signal in the list
//	auto it = signalList.begin();
//	while (1) 
//	{
//		if (signal == *it) // if the same signal sent, do nothing
//			return;
//		if (next(it) == signalList.end() || // if this is the last signal, insert after it
//			in_between(signal, *it, *next(it)) &&
//			same_direction(*it, *next(it), direction)) // or if it is in between and on the same direction, insert after the current one
//		{
//			signalList.insert_after(it, signal);
//			return;
//		}
//		// otherwise, set iterator to the next one, start over again
//		it++;
//		continue;
//	}
	return;
}

void SignalCore_Normal::popSignal() { return; }
int SignalCore_Normal::getSignal() const { return 0; }
bool SignalCore_Normal::isEmpty() const { return false; }
