#include "Floor.h"
#include <iostream>
#include <cassert>
using namespace std;
int main() {

	Floor flr;
	flr.addCustomerToFloor(Customer(5),3);
	flr.addCustomerToFloor(Customer(5),6);
	flr.addCustomerToFloor(Customer(7),4);
	flr.addCustomerToFloor(Customer(6),3);

//	elegraphics::secConsoleOut.sendMsg("Has up on floor 3:");
//	if (flr.hasCustomerOnFloor( 
//				[](Customer c) 
//				{ return c.getDestinationFloor() > 3; },
//				3))
//		elegraphics::secConsoleOut.sendMsg("true");
//	else
//		elegraphics::secConsoleOut.sendMsg("false");
	assert(flr.hasCustomerOnFloor([=](Customer c) 
				{ return c.getDestinationFloor() > 3; },
				3) == true);
	assert(flr.hasCustomerOnFloor([=](Customer c) 
				{ return c.getDestinationFloor() < 3; },
				3) == false);
	assert(flr.hasCustomerOnFloor([=](Customer c) 
				{ return c.getDestinationFloor() > 6; },
				6) == false);
	assert(flr.hasCustomerOnFloor([=](Customer c) 
				{ return c.getDestinationFloor() < 8; },
				8) == false);
	assert(flr.hasCustomerOnFloor([=](Customer c) 
				{ return c.getDestinationFloor() > 4; },
				4) == true);
	
	return 0;
}
