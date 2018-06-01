#include "SignalCore_Normal.h"
#include <iostream>
using namespace std;

int main() {
	SignalCore_Normal sgn;
	sgn.addSignal(3, 5, SignalCore_B::down);
	sgn.addSignal(3, 2, SignalCore_B::up);
	sgn.addSignal(3, 1, SignalCore_B::both);
	sgn.addSignal(3, 4, SignalCore_B::both);

	sgn.printList();
	cout << "Get signal: " << sgn.getSignal() << endl;
	cout << "pop Signal once." << endl;
	sgn.popSignal();
	sgn.printList();
	return 0;
}
