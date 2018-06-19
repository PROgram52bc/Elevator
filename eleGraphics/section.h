#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <string>
#include <mutex>
#include "conio.h"


class Section { 
	private:
		const int
			col,
			row,
			width,
			height;
	protected:
		/* protect output conflict with multiple threads */
		static std::mutex outputMutex;
		void _drawStrAt( const string&, 
						int col=1, 
						int row=1, 
						conio::Color bg=conio::RESET, 
						conio::Color fg=conio::RESET);
		void _clrSection();
	public:
		/* Constructors */
		explicit Section(int c, int r, int w, int h):
			col(c), row(r), width(w), height(h) {}
		/* Accessors */
		int getStartCol() { return col; }
		int getStartRow() { return row; }
		int getEndCol() { return col+width-1; }
		int getEndRow() { return row+height-1; }
		int getConsecutiveCol() { return col+width; } /**< Return the column number right after the last column of this section */
		int getConsecutiveRow() { return row+height; } /**< Return the row number right after the last row of this section */
		int getWidth() { return width; }
		int getHeight() { return height; }
		void clrSection();
		void drawStrAt( const string&, 
						int col=1, 
						int row=1, 
						conio::Color bg=conio::RESET, 
						conio::Color fg=conio::RESET);
};


#endif
