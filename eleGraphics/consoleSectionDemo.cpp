#include <iostream>
#include "consoleSection.h"


int main() {
	
	using namespace std;
	cout << conio::clrscr() << flush;
	ConsoleSection secOut(1,1,
			50,20);
	ConsoleSection secIn(secOut.getStartCol(), secOut.getConsecutiveRow(),
			secOut.getWidth(), 2);
	string outputStr;
	secOut.sendMsg("Enter a string for output...");
	while (1)
	{
		secIn.clrSection();
		secIn.drawStrAt(">>",1,1,conio::RESET,conio::GREEN);
		secIn.focusCursor(3,1);
		getline(cin, outputStr);
		secOut.sendMsg("Output String: " + outputStr);
	}
}
