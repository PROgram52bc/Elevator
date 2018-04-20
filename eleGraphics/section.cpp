#include "section.h"

using namespace std;
using namespace conio;

/**
  * @brief Clear the section
  */
void Section::clrSection() {
	for (int i=0; i<height; i++)
	{
		cout << gotoRowCol(row+i, col);
		for (int nspace=0; nspace<width; nspace++)
			cout << " " << flush;
	}
}
/** 
  @throw throws an out_of_range exception if the starting point is invalid.

  @param toBeDrawn 
  @param c the column (x) to start drawing at, 
  if negative, count from the bottom of the section,
  omit the part that goes out of the section.
  @param r the row (y) to start drawing at, 
  if negative, count from the right and align string to the right,
  omit the part that goes out of the section.
  @param bg the background color of string.
  @param fg the foreground color of string.
  */
void Section::drawStrAt(const string& toBeDrawn,
						int c, 
						int r,
						conio::Color bg, 	
						conio::Color fg	
						) {
	cout << conio::bgColor(bg);
	cout << conio::fgColor(fg);
	bool rAlign = false;
	// check if row is negative
	if (r<0) {
		r = this->height + 1 + r;
	}
	// check if col is negative
	if (c<0) {
		c = this->width + 1 + c;
		rAlign = true;
	}
	// check if the point is out of range
	if (r==0 || c==0 || r>height || c>width) // if place to be drawn is out of range
		throw (out_of_range("trying to draw " + toBeDrawn + " out of the section."));
	
	// Index for getting the sub-string
	int startIdx = 0;
	int lengthToDraw = toBeDrawn.length();

	if (rAlign) // if right aligned, truncate the left side
	{
		if (toBeDrawn.length() > c) // if out of range
		{
			startIdx = toBeDrawn.length() - c; // set the start index to be truncated from
		}
	}
	else // if left aligned, truncate the right side
	{
		if (toBeDrawn.length() > width+1-c) // if out of range
		{
			lengthToDraw = width+1-c; // truncate the length to available space only
		}
	}

	// setting up the actual position
	int globalRow = r+row-1;  	// for row just set it
	int globalCol = c+col-1; 	
	// for col we need to translate to left alignment and							
    // check if the left side goes out of section
	if (rAlign) { 
		globalCol = globalCol - toBeDrawn.length() + 1;
		if (globalCol<col) globalCol=col;
	}

	// draw the string
	cout << gotoRowCol(globalRow, globalCol);
	cout << toBeDrawn.substr(startIdx, lengthToDraw); 
	cout << conio::resetAll();
}
