#include "Floor.h"
#include <iostream>
using namespace std;
int main() {

	Floor flr;
	flr.addCustomerToFloor(Customer(5),3);
	flr.addCustomerToFloor(Customer(5),6);
	flr.addCustomerToFloor(Customer(7),4);
	flr.addCustomerToFloor(Customer(6),3);
	flr.getOutCustomerFromFloor([](Customer c)
			{ return c.getDestinationFloor() == 6; }, 3);
	return 0;
}
