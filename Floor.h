#ifndef FLOOR_H
#define FLOOR_H
#include "Customer.h"
#include "CustomerList.h"
#include "eleGraphics/eleGraphics.h"
#include <vector>

/* Next step:
 * Think about the memory management of 
 * the floors, is there any other way
 * apart from dynamically allocate certain
 * number of CustomerList and access
 * through a raw pointer?
 * Tue May 22 15:59:16 CST 2018
 */

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
		Customer getOutCustomerFromFloor(std::function<bool(Customer)> f, int flr);
};


#endif
