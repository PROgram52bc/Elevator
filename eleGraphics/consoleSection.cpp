#include "consoleSection.h"

/**@brief set cursor to the current section, used for input sections
 */
void ConsoleSection::focusCursor(int col, int row) 
{
	/* protect output conflict with multiple threads */
	std::lock_guard<std::mutex> lg(outputMutex);
	if (col>this->getWidth() || row>this->getHeight())
		throw std::out_of_range("Invalid position to focus cursor.");
	int globalCol = this->getStartCol() + col - 1;
	int globalRow = this->getStartRow() + row - 1;
	cout << conio::gotoRowCol(globalRow, globalCol) << flush;
}

void ConsoleSection::sendMsg(const std::string& message)
{
	/* protect output conflict with multiple threads */
	std::lock_guard<std::mutex> lg(outputMutex);
	// clear section and reset cursor if needed
	int charAvail = (this->getHeight() - this->cursorRow) 
		* this->getWidth();
	if (message.length() > charAvail)
	{
		this->_clrSection();
		this->cursorRow = 1;
	}
	// insert string in multiple lines
	std::string rest(message);
	while (rest.length() > this->getWidth()) // when string too long
	{
		string segment = rest.substr(0, this->getWidth());
		rest = rest.substr(this->getWidth());
		this->_drawStrAt(segment, 1, this->cursorRow++);
	}
	this->_drawStrAt(rest, 1, this->cursorRow++);
}
