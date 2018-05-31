#include "EmptyError.h"
#include <iostream>
using namespace std;

int main() {

	try {
		throw (EmptyError("Testing EmptyError class."));
	}
	catch(EmptyError& e) {
		cout << "Empty Error caught." << endl;
		cout << "Message: " << e.what() << endl;
	}

	return 0;
}
