/* getSize and getMaxSize may be unnecessary */

#include "CustomerList.h"
#include "EmptyError.h"

CustomerList::CustomerList():
	maxCustomers(DEFAULT_MAX_CUSTOMER)
{}

CustomerList::CustomerList(int max):
	maxCustomers(max)
{}

bool CustomerList::isFull() const
{
	return (this->customers.size() == maxCustomers);
}

bool CustomerList::isEmpty() const
{
	return customers.empty();
}

/**@brief get the number of customers in this list
 */
int CustomerList::getSize() const
{
	return customers.size();
}

/**@brief get the maximum customers this list can contain
 */
int CustomerList::getMaxSize() const
{
	return maxCustomers;
}

/**@brief add a customer to the CustomerList
 */
bool CustomerList::addCustomer(Customer c)
{
	if (isFull()) return false;
	this->customers.push_back(c);
	return true;
}

/**@brief remove and return a customer from the customer list
 * @param query a function object determining eligible customers
 * @return a customer that made query return true
 * @throw EmptyError no suitable customer found to be popped
 */
Customer CustomerList::popCustomer(std::function<bool(Customer)> query) 
{
	std::list<Customer>::iterator it = this->customers.begin();
	while (it != this->customers.end()) {
		if (query(*it))
		{
			Customer result = *it;
			this->customers.erase(it);
			return result;
		}
		else
		{
			it++;
		}
	}
	throw (EmptyError("No suitable customer found."));
}

/**@brief get the raw list to iterate through the customers in the list.
 * @return a constant reference to the internal list
 */
const std::list<Customer>& CustomerList::getList() const 
{
	return this->customers;
}

void CustomerList::incrementCustomers()
{
	for (auto& i: customers)
		i.incrementTimeSpent();
}

bool CustomerList::hasCustomer(
		std::function<bool(Customer)> f)
{
	for (const auto& i: customers)
		if (f(i))
			return true;
	return false;
}
