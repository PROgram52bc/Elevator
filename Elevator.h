#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "CustomerList.h"
#include "eleGraphics/eleGraphics.h"
/* Next step:
 * Think about what mechanics is appropriate
 * for getting customers out of the elevator.
 * e.g. You should only need to get out customer
 * whose destination is the current floor
 * However, for the graphics to display separate
 * customers, it's better to get them out one
 * by one instead of all at the same time.
 * You might also want to display the customer
 * that you just got out.
 * Tue May 22 16:03:32 CST 2018
 */

class Elevator 
{
	protected:

		/****Variables****/
		static const int DEFAULT_MAX_CUSTOMER = 9;

		const int maxFloor;
		const int maxCustomers;
		int currentFloor;
		CustomerList customers;
		elegraphics::ElevatorState currentState;

		/****Methods****/
		bool isFull();
		void drawMe();
	public:
		Elevator();
		Elevator(int);
		void goUp();
		void goDown();
		bool addCustomer(Customer c);
};

#endif
