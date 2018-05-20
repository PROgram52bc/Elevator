#include <iostream>
#include <thread>
#include <chrono>
#include "Elevator.h"

using namespace std;
const int pause = 1;

int main() {
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
		}
	}





	return 0;
}
