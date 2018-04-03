#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <string>
#include "conio.h"


class Section { 
	public:
		const int
			col,
			row,
			width,
			height;
		Section(int c, int r, int w, int h):
			col(c), row(r), width(w), height(h) {}
		void clrSection();
		void drawStrAt(const string&, int row=1, int col=1);
};


#endif
