#include "section.h"
#include "conio.h"
#include <string>
#include <iostream>

int main() {
	using namespace std;
	using namespace conio;
	cout << conio::clrscr() << flush;
	Section testSec1(1,1,50,20);

	testSec1.clrSection();
	// draw a frame
	testSec1.drawStrAt(string(testSec1.getWidth(), '*')); // top
	testSec1.drawStrAt(string(testSec1.getWidth(), '*'), 1, -1); // bottom
	for (int row=1; row<= testSec1.getHeight(); row++)
	{
		testSec1.drawStrAt("*", 1, row);
		testSec1.drawStrAt("*", testSec1.getWidth(), row);
	}


	testSec1.drawStrAt("NONONONOvvvv", -47, -1); // test left overflow
	testSec1.drawStrAt("vvvvNONONONO", 47, -2); // test right overflow

	testSec1.drawStrAt("Cyan Background", 2, -3, CYAN); // test bg color
	testSec1.drawStrAt("Green Foreground", 2, -4, RESET, GREEN); // test fg color
	testSec1.drawStrAt("Blue Foreground and Yellow background", 2, -5, YELLOW, BLUE); // test both

}
