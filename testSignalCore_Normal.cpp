#include "SignalCore_Normal.h"
#include <iostream>
using namespace std;

int main() {
	SignalCore_Normal sgn;
	//sgn.addSignal(2, 4, SignalCore_B::down);
	//sgn.addSignal(2, 8, SignalCore_B::both);
	sgn.addSignal(3, 9, SignalCore_B::both);
	sgn.addSignal(3, 8, SignalCore_B::both);
	sgn.addSignal(7, 9, SignalCore_B::down);

	sgn.printList();
	return 0;
}
