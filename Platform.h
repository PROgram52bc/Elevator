#ifndef PLATFORM_H
#define PLATFORM_H
#include "SignaledElevator.h"
#include "SignalCore_Normal.h"
#include "Floor.h"
#include "eleGraphics/eleGraphics.h"
#include <mutex>
#include <thread>
#include <list>

class Platform
{
	private:
		static const int resendDelay = 3;
		class resentSignal{
			public:
				int countDown;
				int floor;
				ElevatorDirection direction;
				resentSignal(int f, ElevatorDirection d):
					countDown(resendDelay),
					floor(f),
					direction(d) {}
		};
		std::list<resentSignal> resendList;
		void resendSignal();
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
