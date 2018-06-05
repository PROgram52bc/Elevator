#ifndef SIGNALCORE_NORMAL_H
#define SIGNALCORE_NORMAL_H

#include "SignalCore_B.h"
#include <forward_list>
#include <iostream>

class SignalCore_Normal: public SignalCore_B
{
	public:
		SignalCore_Normal();
		~SignalCore_Normal();
		virtual void addSignal(int currentFloor, int signal, SignalCore_B::Direction direction) override;
		virtual void popSignal() override;
		virtual int getSignal() const override;
		virtual bool isEmpty() const override
		{ return signalList.empty(); }
		void printList() const {
			//first version start
			for (auto& i: signalList)
				std::cout << i.floor << " ";
			std::cout << std::endl;
			for (auto& i: signalList)
				std::cout << i.direction << " ";
			std::cout << std::endl;
			//first version end
			//second version start
			//for (const int& i:signalList)
			//	std::cout << i << " ";
			//std::cout << std::endl;
			// second version end
		}
		virtual Direction getDirection() const override;

	private:
		class Signal {
			public:
				int floor;
				Direction direction;
				Signal(int f, Direction d): floor(f), direction(d) {}
		};
		/**@brief helper function
		 * @param x the floor to be tested
		 * @param a the first boundary floor
		 * @param b the second boundary floor
		 * @retval true if x is in between a and b 
		 * @retval false if x is not in between a and b
		 */
		bool in_between(int x, int a, int b) 
		{ return (x>a&&x<b || x<a&&x>b); }
		/**@brief helper function
		 * @param from the starting floor
		 * @param to the destination floor
		 * @param dir the direction to be tested
		 * @retval true if the current movement corresponds to dir
		 * @retval false if not corresponds to dir or if dir is both
		 */
		bool same_direction(Direction dir, int from, int to) 
		{ return  (to-from)*dir > 0; }
		/**@brief helper function
		 * @param from the starting floor
		 * @param to the destination floor
		 * @param dir the direction to be tested
		 * @retval true if the current movement corresponds to 
		 * dir or if dir is both
		 * @retval false if not corresponds to dir 
		 */
		bool good_direction(Direction dir, int from, int to)
		{ return dir == both || same_direction(dir, from, to); }

		bool insertable(Signal curr, Signal next, Signal toBeInserted);
		void _iterateInsert(int signal, SignalCore_B::Direction direction);

		std::forward_list<Signal> signalList;
};

#endif
