#ifndef CONSOLESECTION_H
#define CONSOLESECTION_H
#include "section.h"

class ConsoleSection: public Section {
	private:
		int cursorRow;
	public:
		explicit ConsoleSection(int c, int r, int w, int h): Section(c,r,w,h), cursorRow(1) {}
		void focusCursor(int c=1, int r=1);
		void sendMsg(const std::string& message);
};

#endif
