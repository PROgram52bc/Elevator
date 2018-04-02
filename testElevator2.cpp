
#include <iostream>
#include <thread>
#include <chrono>
#include "Elevator.h"

using namespace std;
const int pause = 1;

int main() {
	Elevator my_ele;
	cout << "Elevator created!" << endl;
	this_thread::sleep_for(chrono::seconds(pause));
	for (int i=0; i<7; i++)
	{
		my_ele.goUp();
		cout << "Going up!" << endl;
		this_thread::sleep_for(chrono::seconds(pause));
	}
	for (int i=0; i<9; i++)
	{
		my_ele.goDown();
		cout << "Going down!" << endl;
		this_thread::sleep_for(chrono::seconds(pause));
	}





	return 0;
}
