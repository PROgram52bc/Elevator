#ifndef SIGNALCORE_NORMAL_H
#define SIGNALCORE_NORMAL_H

#include "SignalCore_B.h"
#include <forward_list>

class SignalCore_Normal: public SignalCore_B
{
	public:
		SignalCore_Normal();
		~SignalCore_Normal();
		virtual void addSignal(int currentFloor, int signal, SignalCore_B::Direction direction) override;
		virtual void popSignal() override;
		virtual int getSignal() const override;
		virtual bool isEmpty() const override;
	private:
		class Signal {
			public:
				int floor;
				Direction direction;
				Signal(int f, Direction d): floor(f), direction(d) {}
		};
		std::forward_list<Signal> signalList;
};

#endif
