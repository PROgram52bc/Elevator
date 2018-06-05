#include "SignalCore_Normal.h"
#include <iostream>
using namespace std;

int main() {
	SignalCore_Normal sgn;
	sgn.addSignal(2, 5, SignalCore_B::down);
	sgn.addSignal(2, 5, SignalCore_B::down);
	sgn.addSignal(8, 5, SignalCore_B::both);
	//sgn.addSignal(3, 4, SignalCore_B::both);

	sgn.printList();
	return 0;
}
