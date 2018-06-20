#ifndef CURSORSIGNALCORE_B_H
#define CURSORSIGNALCORE_B_H

#include "SignalCore_B.h"
/**@brief a signalcore interface for more advanced operation:
 * 1. check the distance to a given signal
 * 2. a cursor to locate specific signal
 * 3. get signal direction and floor, remove signal with cursor
 */
class CursorSignalCore_B : public SignalCore_B {
	public:
		/**@brief returns an integer indicating the distance
		 * to the signal, only used for multiple elevators
		 */
		virtual int getSignalDistance(int currentFloor, int signal, Direction direction)
		{ return 0; }
		virtual bool cursorToNext() = 0;
		virtual bool cursorToPrev() = 0;
		virtual bool cursorIsLast() = 0 const;
		virtual int getCursorSignal() const = 0;
		virtual Direction getCursorDirection() const = 0;
		virtual void popCursorSignal() = 0;


};



#endif
