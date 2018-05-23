#ifndef SIGNALEDELEVATOR_H
#define SIGNALEDELEVATOR_H
#include "Elevator.h"

/* Next step:
 * SignaledElevator:public Elevator
 * public inheritance from Elevator
 * additional protected variables:
 * list<Signal> signalList
 * additional public methods:
 * addSignal(flr, direction = both);
 * int nextSignal() const; // return next floor
 * popSignal(); // remove the next signal
 * debug: printSignalList() const;
 *
 *
 * enum Direction { up, down, both }
 * struct Signal {
 * 		Direction direction;
 * 		int floorNum;
 * 		Signal(f,d): floorNum
 * Wed May 23 15:06:07 CST 2018
 */
class SignaledElevator: public Elevator {
	protected:
		list<Signal> signalList
	public:
		enum Direction {up, down, both};
		void addSignal(int, Direction);
		bool move();

};

#endif
