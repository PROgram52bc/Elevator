#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <list>
#include "Customer.h"
#include <functional>

class CustomerList {
	private:
		static const int DEFAULT_MAX_CUSTOMER = 20;
		int maxCustomers;
		std::list<Customer> customers;
	public:
		CustomerList();
		CustomerList(int max);
		bool isFull() const;
		bool isEmpty() const;
		int getSize() const;
		int getMaxSize() const;
		bool addCustomer(Customer c);
		Customer popCustomer(std::function<bool(Customer)>);
		const std::list<Customer>& getList() const;

};

#endif
