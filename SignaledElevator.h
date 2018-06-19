#ifndef SIGNALEDELEVATOR_H
#define SIGNALEDELEVATOR_H
#include "Elevator.h"
#include "SignalCore_B.h"

/* open door, pop from list, if new order same as current direction and floor, ignore it. 
 * No: Keep the signal until door is closed.
 * getDirection() method returns a direction
 * 	if current floor same as the signal floor, 
 * 	return direction in signal
 * 	if signal floor is something other than current floor,
 * 	return direction according to the movement from current floor to the signaled floor
 */

template <class core>
class SignaledElevator
{
	protected:
		void setDirection();
		SignalCore_B* signalCore;
		Elevator elevator;
	public:
		SignaledElevator(int Flr = elegraphics::MAXFLOOR, Section s = elegraphics::secElevator);
		~SignaledElevator();
		/******Mutators*******/
		void addSignal(int, SignalCore_B::Direction);
		bool move();

		bool getInCustomer(Customer c)
		{ return elevator.getInCustomer(c); }
		bool getOutCustomer()
		{ return elevator.getOutCustomer(); }
		void incrementCustomers()
		{ elevator.incrementCustomers(); }
		/******Observers******/
		elegraphics::ElevatorDirection getDirection() const
		{ return elevator.getCurrentDirection(); }
		elegraphics::ElevatorDoorState getDoorState() const
		{ return elevator.getCurrentDoorState(); }
		int getFloor() const 
		{ return elevator.getCurrentFloor(); }
		bool isFull() const
		{ return elevator.isFull(); }
		bool hasCustomerToGetOut() const;
		/**@brief indicating whether the elevator is ready for
		 * new customers to get in */
		bool isLoadable() const
		{ 
			return 
				elevator.getCurrentDoorState() == elegraphics::open &&
				!elevator.hasCustomerToGetOut();
		}
};

#include "SignaledElevator.cpp"

#endif
