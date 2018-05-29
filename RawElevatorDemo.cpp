#include <iostream>
#include <thread>
#include <chrono>
#include "Elevator.h"
#include "eleGraphics/eleGraphics.h"

using namespace std;
const int pause = 1;

int main() {
	elegraphics::clrscr();
	Elevator my_ele;
	char signal;
	while (cin.get(signal)) {
		switch(signal) {
			case 'j':
				my_ele.goDown();
				break;
			case 'k':
				my_ele.goUp();
				break;
			case 'r':
				my_ele.getOutCustomer();
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				my_ele.getInCustomer(Customer(int(signal)-48));
				break;
		}
		elegraphics::secConsoleIn.clrSection();
		elegraphics::secConsoleIn.focusCursor();
	}





	return 0;
}
