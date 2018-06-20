#ifndef SIGNALCORE_B_H
#define SIGNALCORE_B_H

/**@brief a base class with defined interface for the signal core */
class SignalCore_B {
	public:
		/**@brief a representation for signal's directions */
		enum Direction { up=1, down=-1, both=0 };
		/**@brief adds a signal to the core */
		virtual void addSignal(int currentFloor, int signal, Direction direction) = 0;
		/**@brief removes the signal at front */
		virtual void popSignal() = 0;
		/**@brief get the floor number of the signal at front */ 
		virtual int getSignal() const = 0;
		/**@brief get the direction of the signal at front */ 
		virtual Direction getDirection() const = 0;
		/**@retval true if core is empty
		 * @retval false if core is not empty
		 */
		virtual bool isEmpty() const = 0;
		virtual ~SignalCore_B() {};
};

#endif
