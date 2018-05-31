#ifndef SIGNALEDELEVATOR_CPP
#define SIGNALEDELEVATOR_CPP
#include "SignaledElevator.h"
#include <iostream>

/**@brief constructor */
template <class core>
SignaledElevator<core>::SignaledElevator(int maxFlr, Section sec):
	elevator(maxFlr, sec)
{
	signalCore = new core;
	std::cout << "core created!" << std::endl;
}

/**@brief destructor */
template <class core>
SignaledElevator<core>::~SignaledElevator()
{
	delete signalCore;
	std::cout << "core deleted!" << std::endl;
}

/**@brief move the elevator according to the requests made*/
template <class core>
bool SignaledElevator<core>::move() 
{
	return false;
}

template <class core>
void SignaledElevator<core>::addSignal(int flr, SignalCore_B::Direction dir)
{
	return;
}

#endif
