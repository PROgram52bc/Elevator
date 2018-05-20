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

	const int elevatorWidth = 10; /**< Width of the elevator section */
	const int queueWidth = 20; /**< Width of the customer queue */

	Section secElevator(1,1, // starting x and y
			elevatorWidth,FLRHEIGHT*MAXFLOOR); // width and height
	Section secFloor(secElevator.getConsecutiveCol(), secElevator.getStartRow(), // starting x, y
			queueWidth, secElevator.getHeight()); // width and height


	string upElevator[] = {
		"^     ^",
		"|     |",
		"|     |",
		"|     |"
	};
	string downElevator[] = {
		"|     |",
		"|     |",
		"|     |",
		"v     v"
	};
	string openElevator[] = {
		"[     ]",
		"|     |",
		"|     |",
		"[     ]"
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
	void drawFloor(int n) {
		if (n > MAXFLOOR)
			n = MAXFLOOR; // draw only until the max floor
		for (int i=1; i<=n; i++) // i indicates the floor number
		{
			int floorRow = getFlrBotRow(i); // convert i to the actual row number from bottom
			secElevator.drawStrAt(to_string(i)+"_", 1, floorRow);
			secElevator.drawStrAt("_", -1, floorRow);
		}
	}

	/** @brief draw the elevator inside the floor frame */
	void drawElevator(int floor, ElevatorState state) {
		string* pEle = nullptr;
		switch (state) {
			case up:
				pEle = upElevator;
				break;
			case down:
				pEle = downElevator;
				break;
			case open:
				pEle = openElevator;
				break;
		}

//		int numRowFromBottom = floor*FLRHEIGHT;
//		int floorRow = -1 * numRowFromBottom; // convert floor to the actual row number from bottom
		int floorRow = getFlrTopRow(floor);
		for (int strRowNum=0; strRowNum<FLRHEIGHT; strRowNum++) /**< tracking the line number in the elevator string array */
		{
			secElevator.drawStrAt(pEle[strRowNum], 3, floorRow, conio::RESET, conio::GREEN);
			floorRow++; // increment negative index -> absolute value smaller -> going down
		}
		cout << gotoRowCol(secElevator.getConsecutiveRow(),
				secElevator.getStartCol());

	}

	/** @brief a combined drawFloor and drawElevator, clearing section automatically.
	*/
	void drawElevatorAndFloor(int floor, int maxFloor, ElevatorState state) {
		secElevator.clrSection();
		drawFloor(maxFloor);
		drawElevator(floor, state);
	}
	void drawCustomersInElevator(const list<Customer>& listCustomer, int floor) {
		int maxCustomer = 9;
		int numPerRow = 3;
		int startCol = 5; // which col in section to start drawing customer
		int colOffset = 0;
		int currentRow = getFlrTopRow(floor);
		auto itCustomer = listCustomer.cbegin();
		for (int i=0; i<maxCustomer && itCustomer != listCustomer.cend() ; i++) {
			int customerFloor = itCustomer->destinationFloor;
			int customerTimeSpent = itCustomer->timeSpent;
			conio::Color customerColor = conio::GREEN;
			if (customerTimeSpent > 10)
				customerColor = conio::YELLOW;
			else if (customerTimeSpent > 20)
				customerColor = conio::RED;
			secElevator.drawStrAt(to_string(customerFloor), 
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

	/** @brief clear the entire screen */
	void clrscr() {
		cout << conio::clrscr();
	}


}
