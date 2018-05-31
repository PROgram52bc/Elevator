#ifndef SIGNALCORE_B_H
#define SIGNALCORE_B_H

/**@brief a base class with defined interface for the signal core */
class SignalCore_B {
	public:
		enum Direction { up=1, down=-1, both=0 };
		virtual void addSignal(int currentFloor, int signal, Direction direction) = 0;
		virtual void popSignal() = 0;
		virtual int getSignal() const = 0;
		virtual bool isEmpty() const = 0;
		virtual ~SignalCore_B() {};
};

#endif
