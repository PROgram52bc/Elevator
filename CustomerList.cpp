/* getSize and getMaxSize may be unnecessary */

#include "CustomerList.h"

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

int CustomerList::getSize() const
{
	return customers.size();
}

int CustomerList::getMaxSize() const
{
	return maxCustomers;
}

bool CustomerList::addCustomer(Customer c)
{
	if (isFull()) return false;
	this->customers.push_back(c);
	return true;
}

/**@brief remove and return a customer from the customer list
 * @param query a function object determining eligible customers
 * @return a customer that made query return true
 * @throw std::runtime_error no suitable customer found to be popped
 */
Customer CustomerList::popCustomer(std::function<bool(Customer)> query) {
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
	// return Customer(-1);
	// throw a runtime_error exception instead :
	throw (std::runtime_error("No suitable customer found."));
}

/**@brief get the raw list to iterate through the customers in the list.
 * @return a constant reference to the internal list
 */
const std::list<Customer>& CustomerList::getList() const {
	return this->customers;
}

