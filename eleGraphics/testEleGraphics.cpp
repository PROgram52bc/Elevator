/*
 * testconio.cpp: test program for the conio function set
 */

#include <iostream>
#include <list>
#include "eleGraphics.h"
#include "conio.h"
#include "../Customer.h"

using namespace std;

int main() {

	elegraphics::clrscr();
	list<Customer> customers;
	customers.push_back(Customer(5));
	customers.push_back(Customer(9));
	customers.push_back(Customer(3));
	customers.push_back(Customer(3));
	list<Customer> floor1(customers);
	list<Customer> floor2(customers);
	elegraphics::drawCustomersOnFloor(floor1, 1);
	elegraphics::drawCustomersOnFloor(floor2, 2);
	

	for (int i=1; i<=9; i++) {
		elegraphics::drawElevatorAndFloor(i, 9, elegraphics::up);
		elegraphics::drawCustomersInElevator(customers, i);
		cin.get();
	}

//	for (int i=5; i>1; i--) {
//		drawElevatorAndFloor(10, i, elegraphics::down);
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

