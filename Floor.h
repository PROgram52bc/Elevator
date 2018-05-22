#ifndef FLOOR_H
#define FLOOR_H
#include "Customer.h"
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
		int maxFloor;
		CustomerList* floors;
	public:
		Floor();
		Floor(int maxFlr);
};


#endif
