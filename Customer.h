#ifndef CUSTOMER_H
#define CUSTOMER_H

struct Customer {
	int timeSpent;
	int destinationFloor;
	Customer(): timeSpent(0), destinationFloor(1) {}
	Customer(int flr): timeSpent(0), destinationFloor(flr) {}
};

#endif
