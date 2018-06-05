#include "Platform.h"
#include <functional>
#include "EmptyError.h"
/* fixme: When two signals at the same floor with different 
 * direction collapse, the program (move function or signalCore) 
 * should not open the door twice
 */
Platform::Platform(int maxFlr):
	sigElevator(maxFlr, elegraphics::secElevator),
	floor(maxFlr),
	isRunning(false)
{ elegraphics::secConsoleOut.sendMsg("Platform created!");}

void Platform::addCustomerToFloor(Customer cust, int flr)
{
	std::lock_guard<std::mutex> l(mtx);
	int dest = cust.getDestinationFloor();
	if (dest == flr)
		throw(std::logic_error("Added a Customer with destination == current floor"));
	if (dest > flr)
		sigElevator.addSignal(flr, SignalCore_B::up);
	else if (dest < flr)
		sigElevator.addSignal(flr, SignalCore_B::down);
	floor.addCustomerToFloor(cust, flr);
}

void Platform::process()
{
	std::lock_guard<std::mutex> l(mtx);
	if (sigElevator.getDoorState() == elegraphics::open)
	{
		loadCustomer() ||
			sigElevator.move();
	}
	else
		sigElevator.move();
	incrementCustomers();
}

/**@brief manage the loading of customers, once at a time
 * @retval true if loaded
 * @retval false if not loaded
 */
bool Platform::loadCustomer()
{
	/** Try get customer out of elevator */
	if (sigElevator.getOutCustomer())
		return true;
	/** If elevator is full, can't do anything */
	if (sigElevator.isFull())
		return false;
	/** Try get customer from floor to elevator */
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
	/** if no customer available, can't do anything */
	catch (EmptyError)
	{ return false; }
	/** get the customer into the elevator */
	if (sigElevator.getInCustomer(cust))
	{
		sigElevator.addSignal(
				cust.getDestinationFloor(),
				SignalCore_B::both);
		return true;
	}
	/** by this time, the elevator is not full,
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

void Platform::run() 
{
	if (isRunning)
		throw (std::runtime_error("Platform is already running."));
	std::thread t(&Platform::run_func, this);
	t.join();
	isRunning = true;
}
