#include "Platform.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int totalTime = 30;

int main() {
	srand(int(time(0)));
	elegraphics::clrscr();
	elegraphics::secConsoleOut.sendMsg("Welcome to platform!");
	Platform p(9);
	thread t = p.run();
	for (int i=0; i<totalTime; i++)
	{
		int numCust = rand() % 3;
		for (int j=0; j<numCust; j++)
		{
			int fromFloor = rand() % 9 + 1; // 1-9
			int toFloor = rand() % 8 + 1; // 1-8
			if (toFloor>=fromFloor)
				toFloor++;
			p.addCustomerToFloor(Customer(toFloor), fromFloor);
			elegraphics::secConsoleOut.sendMsg(
					"Customer at floor " +
					to_string(fromFloor) + 
					" to floor " +
					to_string(toFloor) +
					" created!");
		}
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	t.join();

	return 0;
}
