#ifndef FLOOR_H
#define FLOOR_H
#include "Customer.h"
#include "CustomerList.h"
#include "eleGraphics/eleGraphics.h"
#include <vector>

class Floor {
	private:
		static const int DEFAULT_MAX_CUSTOMER = 20;
		const int maxFloor;
		const int maxCustomersPerFloor;
		std::vector<CustomerList> floors;
		Section section;
		void drawMe();
	public:
		Floor(int maxFlr = elegraphics::MAXFLOOR,
				int maxCus = DEFAULT_MAX_CUSTOMER,
				Section sec = elegraphics::secFloor );
		~Floor();
		bool getMaxFloor() const { return maxFloor; }
		bool floorIsEmpty(int flr) const;
		bool floorIsFull(int flr) const;
		bool addCustomerToFloor(Customer c, int flr);
		bool hasCustomerOnFloor(
				std::function<bool(Customer)> f,
				int flr)
		{ return floors.at(flr-1).hasCustomer(f); }
		Customer getOutCustomerFromFloor(
				std::function<bool(Customer)> f, 
				int flr);
		void incrementCustomers()
		{ 
			for (auto& floor: floors)
				floor.incrementCustomers();
		}
};


#endif
