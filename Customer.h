#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
	private:
		int timeSpent;
		int destinationFloor;
	public:
		int getTimeSpent() const { return timeSpent; }
		int getDestinationFloor() const { return destinationFloor; }
		void incrementTimeSpent() { ++timeSpent; }
		Customer(): timeSpent(0), destinationFloor(1) {}
		Customer(int flr): timeSpent(0), destinationFloor(flr) {}
};


#endif
