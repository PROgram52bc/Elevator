#include "section.h"

using namespace std;
using namespace conio;

void Section::clrSection() {
	for (int i=0; i<height; i++)
	{
		cout << gotoRowCol(row+i, col);
		for (int nspace=0; nspace<width; nspace++)
			cout << " " << flush;
	}
}
void Section::drawStrAt(const string& toBeDrawn, int r, int c) {
	if (r>height || c>width) // if place to be drawn is out of range
		throw (out_of_range("trying to draw a string out of the section."));
	int globalRow = r+row-1; // setting up the actual position
	int globalCol = c+col-1;
	cout << gotoRowCol(globalRow, globalCol);
	if (toBeDrawn.length() > width-r+1) // if the string is longer than available space
		cout << toBeDrawn.substr(0, width-r+1); // draw only the first half of the string
	else
		cout << toBeDrawn;
}
