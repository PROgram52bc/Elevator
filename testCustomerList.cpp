#include "CustomerList.h"
#include <iostream>

using namespace std;
void printList(const list<Customer>& l) {
	for (auto& i: l)
		cout << i.destinationFloor << " ";
	cout << endl;
}

int main() {

	CustomerList c1;
	CustomerList c2(15);
	cout << "c1.getSize(): "
		<< c1.getSize() << endl;
	cout << "c2.getSize(): "
		<< c2.getSize() << endl;

	// print
	cout << "c1: ";
	printList(c1.getList());
	cout << "c2: ";
	printList(c2.getList());

	cout << "adding customers:" << endl;
	for (int i=0; i<15; i++)
	{
		if (!c1.addCustomer(Customer(i)))
			cout << "Failed adding customer to c1" << endl;
		c2.addCustomer(Customer(i));
	}
	
	// print
	cout << "c1: ";
	printList(c1.getList());
	cout << "c2: ";
	printList(c2.getList());

	// check if full
	cout << "c1.isFull(): "
		<< c1.isFull()
		<< endl;
	cout << "c2.isFull(): "
		<< c2.isFull()
		<< endl;

	cout << "Pop 1 customer from c1: " << endl;
	// pop floor numbers less than 5
	Customer poped = c1.popCustomer([](Customer c) {return c.destinationFloor<5;});
	cout << poped.destinationFloor << " poped." << endl;
	printList(c1.getList());

	cout << "Loop pop: " << endl;
	// note: this is the syntax of continue pop until not available
	do {
		poped = c1.popCustomer([](Customer c){return c.destinationFloor<5;});
		if (poped.destinationFloor != -1)
			cout << poped.destinationFloor << " poped." << endl;
		else
			break;
	}
	while (1);
	printList(c1.getList());
	

}