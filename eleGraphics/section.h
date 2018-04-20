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
		void drawStrAt( const string&, 
						int col=1, 
						int row=1, 
						conio::Color bg=conio::RESET, 
						conio::Color fg=conio::RESET);
};


#endif
