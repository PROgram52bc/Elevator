/*
 * testconio.cpp: test program for the conio function set
 */

#include <iostream>
#include "eleGraphics.h"
#include "conio.h"
#include "../Customer.h"
#include "../CustomerList.h"

using namespace std;

int main() {

	elegraphics::clrscr();
	CustomerList customers;
	customers.addCustomer(Customer(5));
	customers.addCustomer(Customer(9));
	customers.addCustomer(Customer(3));
	customers.addCustomer(Customer(3));
	elegraphics::drawElevatorAndFloor(3,8,up);
	elegraphics::drawCustomersInElevator(customers, 3);
	elegraphics::drawCustomersOnFloor(customers, 3);
	

//	for (int i=1; i<=9; i++) {
//		elegraphics::drawElevatorAndFloor(i, 9, up);
//		elegraphics::drawCustomersInElevator(customers, i);
//		cin.get();
//	}

//	for (int i=5; i>1; i--) {
//		drawElevatorAndFloor(10, i, down);
//		cin.get();
//	}

//	clrscr();
//	Section section_test(1,1,5,5); 
//	for (int c=1; c<=15; c++)
//		for (int r=1; r<=15; r++)
//		{
//			cout << conio::gotoRowCol(r,c);
//			cout << (c+r) % 10;
//		}
//	section_test.clrSection();


	return 0;
}

