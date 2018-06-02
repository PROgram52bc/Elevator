#include "SignaledElevator.h"
#include "SignaledElevator.cpp"
#include "SignalCore_Normal.h"
#include <thread>
#include <chrono>


std::mutex mtx;

void run_elevator(SignaledElevator<SignalCore_Normal>& e)
{
	
	while (1)
	{
		e.move();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}


using namespace std;
const int pause = 1;

int main() {
	elegraphics::clrscr();
	SignaledElevator<SignalCore_Normal> my_ele;
	thread run(run_elevator, std::ref(my_ele));
	run.detach();
	char signal;
	elegraphics::secConsoleOut.sendMsg("Welcome to SignaledElevator!");
	elegraphics::secConsoleOut.sendMsg("");
	elegraphics::secConsoleIn.focusCursor();
	while (cin.get(signal)) {
		switch(signal) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				my_ele.addSignal(int(signal-48), SignalCore_B::down);
				elegraphics::secConsoleOut.sendMsg("Signal " + to_string(signal-48) + ", down, added.");
				break;
			case 'q':
				return 0;
		}
		elegraphics::secConsoleIn.clrSection();
		elegraphics::secConsoleIn.focusCursor();
	}
	return 0;
}
