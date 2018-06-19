#include "Platform.h"
#include <functional>
#include "EmptyError.h"
#include "FullElevatorError.h"
/**@bug when the elevator is full, the platform should
 * manage to resend the signal for the unloaded customers
 * after the elevator has gone.
 * @bug SignaledElevator still gets some orders wrong,
 * to be observed
 */
Platform::Platform(int maxFlr):
	sigElevator(maxFlr, elegraphics::secElevator),
	floor(maxFlr),
	isRunning(false)
{ }

void Platform::addCustomerToFloor(Customer cust, int flr)
{
	std::lock_guard<std::mutex> l(mtx);
	int dest = cust.getDestinationFloor();
	addSignalToElevator(dest, flr);
	floor.addCustomerToFloor(cust, flr);
}

/**@brief add a signal to the elevator
 * according to the destination and current floor
 * @param dest the destination floor
 * @param flr the current floor
 * @throw logic_error if dest == flr
 */
void Platform::addSignalToElevator(int dest, int flr)
{
	if (dest == flr)
		throw(std::logic_error("Added a signal with destination == current floor"));
	if (dest > flr)
		sigElevator.addSignal(flr, SignalCore_B::up);
	else if (dest < flr)
		sigElevator.addSignal(flr, SignalCore_B::down);
}

void Platform::process()
{
	std::lock_guard<std::mutex> l(mtx);
	/* if elevator is ready to be loaded */
	if (sigElevator.isLoadable())
	{
		try
		{
			/* try to load the elevator */
			if (!tryLoadElevator())
				/* if failed to load (no customer avail on floor)
				 * continue the elevator's movement */
				sigElevator.move();
		}
		catch(FullElevatorError& e)
		{
			/* if the elevator is full, resend signal later
			 */
			elegraphics::secConsoleOut.sendMsg(
					"Full Elevator at floor " + 
					to_string(e.getFloor()) +
					" with direction: " +
					to_string(e.getDirection()));
			sigElevator.move();
		}
	}
	else
		sigElevator.move();
	incrementCustomers();
}

/**@brief get Customers from floor to the elevator
 * @retval true if loaded
 * @retval false if not loaded
 * @throw fixme: Do things here toFullElevatorError if elevator is full, for resending
 * the signal for unloaded customer
 */
bool Platform::tryLoadElevator()
{
//	/* Try get customer out of elevator */
//	if (sigElevator.getOutCustomer())
//		return true;
	/* If elevator is full, can't do anything */
	if (sigElevator.isFull())
		throw(FullElevatorError(
					sigElevator.getFloor(),
					FullElevatorError::Direction(sigElevator.getDirection())));
	/* Try get customer from floor to elevator */
	int currentFloor = sigElevator.getFloor();
	function<bool(Customer)> query;
	switch (sigElevator.getDirection()) {
		case elegraphics::up:
			query = 
				[=](Customer c)
				{ return c.getDestinationFloor() > currentFloor; };
			break;
		case elegraphics::down:
			query = 
				[=](Customer c)
				{ return c.getDestinationFloor() < currentFloor; };
			break;
		case elegraphics::none:
			query = 
				[=](Customer c)
				{ return false; };
			break;
	}
	Customer cust;
	try 
	{
		cust = floor.
			getOutCustomerFromFloor(query, currentFloor);
	}
	/* if no customer available, can't do anything */
	catch (EmptyError)
	{ return false; }
	/* get the customer into the elevator */
	if (sigElevator.getInCustomer(cust))
	{
		sigElevator.addSignal(
				cust.getDestinationFloor(),
				SignalCore_B::both);
		return true;
	}
	/* by this time, the elevator is not full,
	 * so it must be something wrong if can't get
	 * the customer into the elevator.
	 */
	else 
		throw (std::runtime_error("Failed to get customer into the elevator from floor"));
}

void Platform::run_func()
{
	while (1)
	{
		this->process();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

thread Platform::run() 
{
	if (isRunning)
		throw (std::runtime_error("Platform is already running."));
	std::thread t(&Platform::run_func, this);
	isRunning = true;
	return t;
}
