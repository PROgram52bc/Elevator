/*
 * testconio.cpp: test program for the conio function set
 */

#include <iostream>
#include "eleGraphics.h"
#include "conio.h"

using namespace std;

int main() {

	elegraphics::clrscr();
	elegraphics::drawFloor(3);

//	for (int i=5; i>1; i--) {
//		drawElevatorAndFloor(10, i, elegraphics::down);
//		cin.get();
//	}

//	clrscr();
//	Section section_test(1,1,5,5); 
//	for (int c=1; c<=15; c++)
//		for (int r=1; r<=15; r++)
//		{
//			cout << conio::gotoRowCol(r,c);
//			cout << (c+r) % 10;
//		}
//	section_test.clrSection();


	return 0;
}

