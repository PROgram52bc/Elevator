#ifndef SIGNALEDELEVATOR_H
#define SIGNALEDELEVATOR_H
#include "Elevator.h"
#include "SignalCore_B.h"

template <class core>
class SignaledElevator
{
	private:
		void setState();
	protected:
		SignalCore_B* signalCore;
		Elevator elevator;
	public:
		SignaledElevator(int Flr = elegraphics::MAXFLOOR, Section s = elegraphics::secElevator);
		~SignaledElevator();
		void addSignal(int, SignalCore_B::Direction);
		bool move();
};

#endif
