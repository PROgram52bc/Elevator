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
	elegraphics::secConsoleOut.sendMsg("Welcome to Dimen!");
	elegraphics::secConsoleIn.focusCursor();
	while (cin.get(signal)) {
		switch(signal) {
			case 'j':
				my_ele.goDown();
				elegraphics::secConsoleOut.sendMsg("Laowugui went to dimen.");
				break;
			case 'k':
				my_ele.goUp();
				elegraphics::secConsoleOut.sendMsg("Laowugui went up.");
				break;
			case 'r':
				if(my_ele.getOutCustomer())
					elegraphics::secConsoleOut.sendMsg("Laowugui went away.");
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
				if(my_ele.getInCustomer(Customer(int(signal)-48)))
					elegraphics::secConsoleOut.sendMsg("Laowugui to floor " + to_string(signal-48) + " added.");
				break;
		}
		elegraphics::secConsoleIn.clrSection();
		elegraphics::secConsoleIn.focusCursor();
	}





	return 0;
}
