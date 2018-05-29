#ifndef CONSOLESECTION_H
#define CONSOLESECTION_H
#include "section.h"

/* Next step:
 * implement sendMsg(string) method
 * It should support
 * 1. manual new line
 * 2. strings longer than the width
 */
class ConsoleSection: public Section {
	private:
		int cursorRow;
	public:
		explicit ConsoleSection(int c, int r, int w, int h): Section(c,r,w,h), cursorRow(1) {}
		void focusCursor(int c=1, int r=1);
		void sendMsg(const std::string& message);
};

#endif
