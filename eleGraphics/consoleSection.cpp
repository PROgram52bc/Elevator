#include "consoleSection.h"

/**@brief set cursor to the current section, used for input sections
 */
void ConsoleSection::focusCursor(int col, int row) 
{
	if (col>this->getWidth() || row>this->getHeight())
		throw std::out_of_range("Invalid position to focus cursor.");
	int globalCol = this->getStartCol() + col - 1;
	int globalRow = this->getStartRow() + row - 1;
	cout << conio::gotoRowCol(globalRow, globalCol) << flush;
}

void ConsoleSection::sendMsg(const std::string& message)
{
	// clear section and reset cursor if needed
	int charAvail = (this->getHeight() - this->cursorRow) 
		* this->getWidth();
	if (message.length() > charAvail)
	{
		this->clrSection();
		this->cursorRow = 1;
	}
	// insert string in multiple lines
	std::string rest(message);
	while (rest.length() > this->getWidth()) // when string too long
	{
		string segment = rest.substr(0, this->getWidth());
		rest = rest.substr(this->getWidth());
		this->drawStrAt(segment, 1, this->cursorRow++);
	}
	this->drawStrAt(rest, 1, this->cursorRow++);
}
