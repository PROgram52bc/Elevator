/*
 * testconio.cpp: test program for the conio function set
 */

#include <iostream>
#include "eleGraphics.h"
#include "conio.h"

using namespace std;
using namespace conio;

int main() {

	cerr << clrscr() << flush;
	for (int i=5; i>1; i--) {
		cout << clrscr();
		eleGraphics::drawFloor(7);
		eleGraphics::drawElevator(i,eleGraphics::down);
		cout << gotoRowCol(100,0) << "Press something to make it go down." << endl;
		cin.get();
	}

	return 0;
}

