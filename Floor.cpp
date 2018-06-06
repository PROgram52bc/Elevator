#include "Floor.h"
#include "EmptyError.h"

Floor::Floor(int maxFlr, int maxCus, Section sec): 
	maxFloor(maxFlr),
	maxCustomersPerFloor(maxCus),
	floors(maxFloor, CustomerList(maxCustomersPerFloor)),
	section(sec)
{ }

Floor::~Floor()
{ }

void Floor::drawMe()
{
	section.clrSection();
	for (int i=0; i<maxFloor; i++)
		elegraphics::drawCustomersOnFloor(floors.at(i), i+1, section);
}

/**@brief report whether a floor is empty
 * @param flr the floor number, starting with 1 */
bool Floor::floorIsEmpty(int flr) const
{ 
	if (flr>maxFloor || flr<1)
		throw (std::out_of_range
				("Given floor number out of range.")
			  );
	return floors.at(flr-1).isEmpty(); 
}

/**@brief report whether a floor is full
 * @param flr the floor number, starting with 1 */
bool Floor::floorIsFull(int flr) const
{ 
	if (flr>maxFloor || flr<1)
		throw (std::out_of_range
				("Given floor number out of range.")
			  );
	return floors.at(flr-1).isFull();
}

/**@brief add a customer to floor
 * @return a boolean indicating whether succeeded or failed.
 * @param c the customer being added
 * @param flr the number of the floor to add customer to
 */
bool Floor::addCustomerToFloor(Customer c, int flr)
{
	if (floorIsFull(flr))
		return false;
	bool result = floors.at(flr-1).addCustomer(c);
	drawMe();
	return result;
}

bool Floor::hasCustomerOnFloor(
		std::function<bool(Customer)> f,
		int flr)
{
	auto listFloor = floors.at(flr-1).getList();
	for (const auto& i: listFloor)
		if (f(i))
			return true;
	return false;
}

/**@brief remove a customer from the floor
 * @throw EmptyError when no customer is available
 */
Customer Floor::getOutCustomerFromFloor(
		std::function<bool(Customer)> f,
		int flr)
{
	if (floorIsEmpty(flr))
		throw (EmptyError
				("Can't get out customer, floor is empty."));
	Customer result = floors.at(flr-1).popCustomer(f);
	drawMe();
	return result;
}
