#include "Platform.h"
#include <iostream>

using namespace std;

int main() {
	elegraphics::clrscr();
	elegraphics::secConsoleOut.sendMsg("Welcome to platform!");
	Platform p(9);
	p.addCustomerToFloor(Customer(3),5);
	p.addCustomerToFloor(Customer(4),5);
	p.addCustomerToFloor(Customer(4),2);
	p.addCustomerToFloor(Customer(5),8);
	p.run();

	return 0;
}
