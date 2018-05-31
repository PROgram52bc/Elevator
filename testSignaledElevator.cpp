#include "SignaledElevator.h"
#include "SignaledElevator.cpp"
#include "SignalCore_Normal.h"


int main() {

	SignaledElevator<SignalCore_Normal> sig;
	sig.move();

	return 0;
}
