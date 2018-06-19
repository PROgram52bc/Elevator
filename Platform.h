#ifndef PLATFORM_H
#define PLATFORM_H
#include "SignaledElevator.h"
#include "SignalCore_Normal.h"
#include "Floor.h"
#include "eleGraphics/eleGraphics.h"
#include <mutex>
#include <thread>

class Platform
{
	//private:
		//std::list<
	protected:
		std::mutex mtx; // protects elevator and floor
		SignaledElevator<SignalCore_Normal> sigElevator;
		Floor floor;
		void process(); // get the next move
		bool isRunning;
		bool tryLoadElevator();
		void addSignalToElevator(int dest, int flr);
		void incrementCustomers()
		{ 
			sigElevator.incrementCustomers();
			floor.incrementCustomers();
		}
	public:
		void run_func();
		Platform(int maxFlr);
		void addCustomerToFloor(Customer cust, int flr);
		virtual thread run();
};

#endif
