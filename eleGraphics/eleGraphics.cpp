/*
 * A preliminary library for graphing the elevator simulator
 */

#include <iostream>
#include <string>
#include "conio.h"
#include "eleGraphics.h"

using namespace std;
using namespace conio;

namespace elegraphics {

/*****************************Variables***************************/


	/**@brief graphic section for elevator 1 */
	Section secElevator(1,1, // starting x and y
			ELEVATORWIDTH,FLRHEIGHT*MAXFLOOR); // width and height
	/**@brief graphic section for floor */
	Section secFloor(secElevator.getConsecutiveCol(), secElevator.getStartRow(), // starting x, y
			QUEUEWIDTH, secElevator.getHeight()); // width and height
	/**@brief graphic section for elevator 2*/
	Section secElevatorB(secFloor.getConsecutiveCol(), secFloor.getStartRow(), // starting x and y
			ELEVATORWIDTH,FLRHEIGHT*MAXFLOOR); // width and height
	/**@brief graphic section for input */
	ConsoleSection secConsoleIn(secElevator.getStartCol(),secElevator.getConsecutiveRow(), // starting x, y
			CONSOLEINWIDTH, CONSOLEINHEIGHT); // width and height
	/**@brief graphic section for output */
	ConsoleSection secConsoleOut(secElevatorB.getConsecutiveCol(), secElevatorB.getStartRow(),
			CONSOLEOUTWIDTH, secElevatorB.getHeight());

	string upClosedElevator[] = {
		"^     ^",
		"|     |",
		"|     |",
		"|     |"
	};
	string downClosedElevator[] = {
		"|     |",
		"|     |",
		"|     |",
		"v     v"
	};
	string noneClosedElevator[] = {
		"|     |",
		"|     |",
		"|     |",
		"|     |"
	};
	string noneOpenElevator[] = {
		"[     ]",
		"o     o",
		"o     o",
		"[     ]"
	};
	string upOpenElevator[] = {
		"^     ^",
		"o     o",
		"o     o",
		"[     ]"
	};
	string downOpenElevator[] = {
		"[     ]",
		"o     o",
		"o     o",
		"v     v"
	};
/*****************************Functions***************************/
	/** @brief helper function to get the top row number of certain floor
	 *  @param [in] flr Floor number
	 *  @return top row number of that floor
	 */
	int getFlrTopRow(int flr) {
		return -1*FLRHEIGHT*flr;
	}


	/** @brief helper function to get the bottom row number of certain floor
	 *  @param [in] flr Floor number
	 *  @return bottom row number of that floor
	 */
	int getFlrBotRow(int flr) {
		return getFlrTopRow(flr)-1+FLRHEIGHT;
	}

	/** @brief draw the floor frame */
	void drawFloor(int n, Section sec) {
		if (n > MAXFLOOR)
			n = MAXFLOOR; // draw only until the max floor
		for (int i=1; i<=n; i++) // i indicates the floor number
		{
			int floorRow = getFlrBotRow(i); // convert i to the actual row number from bottom
			sec.drawStrAt(to_string(i)+"_", 1, floorRow);
			sec.drawStrAt("_", -1, floorRow);
		}
	}

	/** @brief draw the elevator inside the floor frame */
	void drawElevator(int floor, ElevatorDoorState ds, ElevatorDirection dir, Section sec) {
		string* pEle = nullptr;
		switch (ds) 
		{
			case open:
				switch(dir)
				{
					case up:
						pEle = upOpenElevator;
						break;
					case down:
						pEle = downOpenElevator;
						break;
					case none:
						pEle = noneOpenElevator;
						break;
				}
				break;
			case closed:
				switch(dir)
				{
					case up:
						pEle = upClosedElevator;
						break;
					case down:
						pEle = downClosedElevator;
						break;
					case none:
						pEle = noneClosedElevator;
				}
				break;
		}
		int floorRow = getFlrTopRow(floor);
		for (int strRowNum=0; strRowNum<FLRHEIGHT; strRowNum++) /**< tracking the line number in the elevator string array */
		{
			sec.drawStrAt(pEle[strRowNum], 3, floorRow, conio::RESET, conio::GREEN);
			floorRow++; // increment negative index -> absolute value smaller -> going down
		}

	}

	/** @brief a combined drawFloor and drawElevator, clearing section automatically.
	*/
	void drawElevatorAndFloor(int floor, int maxFloor, ElevatorDoorState ds, ElevatorDirection dir, Section sec) {
		sec.clrSection();
		drawFloor(maxFloor, sec);
		drawElevator(floor, ds, dir, sec);
		secConsoleIn.focusCursor();
	}

	/**@brief a helper function to draw customers from a CustomerList.
	 * @param listCustomer the CustomerList object containing customers to be drawn
	 * @param sec the section where the Customer is to be drawn
	 * @param numPerRow how many customers per row
	 * @param maxCustomer the maximum number of customers to be drawn
	 * @param startCol the column in section to start drawing
	 * @param startRow the row in section to start drawing
	 */
	void drawCustomers(const CustomerList& listCustomer, Section sec, int numPerRow, int maxCustomer, int startCol, int startRow) {
		int colOffset = 0;
		int currentRow = startRow;
		auto itCustomer = listCustomer.getList().cbegin();
		for (int i=0; i<maxCustomer && itCustomer != listCustomer.getList().cend() ; i++) {
			int customerFloor = itCustomer->getDestinationFloor();
			int customerTimeSpent = itCustomer->getTimeSpent();
			conio::Color customerColor = conio::GREEN;
			if (customerTimeSpent > 20)
				customerColor = conio::RED;
			else if (customerTimeSpent > 10)
				customerColor = conio::YELLOW;
			sec.drawStrAt(to_string(customerFloor), 
					startCol+colOffset,
					currentRow,
					customerColor);
			// advance offset
			if (colOffset == numPerRow-1) {
				colOffset = 0;
				currentRow++;
			}
			else {
				colOffset++;
			}
			// advance iterator
			itCustomer++;
		}

	}
	/** @brief draw customers in the elevator */
	void drawCustomersInElevator(const CustomerList& listCustomer, int floor, Section sec) {
		const int maxCustomer = 9;
		const int numPerRow = 3;
		const int startCol = 5; // which col in section to start drawing customer
		int startRow = getFlrTopRow(floor);
		drawCustomers(listCustomer, sec, numPerRow, maxCustomer, startCol, startRow);
		secConsoleIn.focusCursor();
	} 

	/** @brief draw customers on the floor */
	void drawCustomersOnFloor(const CustomerList& listCustomer, int floor, Section sec) {
		const int maxCustomer = 20;
		const int numPerRow = 20;
		const int startCol = 2; // which col in section to start drawing customer
		int startRow = getFlrBotRow(floor);
		drawCustomers(listCustomer, sec, numPerRow, maxCustomer, startCol, startRow);
		secConsoleIn.focusCursor();
	}

	/** @brief clear the entire screen */
	void clrscr() {
		cout << conio::clrscr();
	}
}
