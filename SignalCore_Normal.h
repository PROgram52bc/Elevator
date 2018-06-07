#ifndef SIGNALCORE_NORMAL_H
#define SIGNALCORE_NORMAL_H

#include "SignalCore_B.h"
#include <forward_list>
#include <iostream>

class SignalCore_Normal: public SignalCore_B
{
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
		bool _in_between(int x, int a, int b) const
		{ return (x>a&&x<b || x<a&&x>b); }
		/**@brief helper function
		 * @param from the starting floor
		 * @param to the destination floor
		 * @param dir the direction to be tested
		 * @retval true if the current movement corresponds to dir
		 * @retval false if not corresponds to dir or if dir is both
		 */
		bool _same_direction(Direction dir, int from, int to) const
		{ return  (to-from)*dir > 0; }
		/**@brief helper function
		 * @param from the starting floor
		 * @param to the destination floor
		 * @param dir the direction to be tested
		 * @retval true if the current movement corresponds to 
		 * dir or if dir is both
		 * @retval false if not corresponds to dir 
		 */
		bool _good_direction(Direction dir, int from, int to) const
		{ return dir == both || _same_direction(dir, from, to); }
		bool _is_opposite(Direction a, Direction b) const
		{ return a == (-1) * b;}

		bool _insertable(Signal curr, Signal next, Signal toBeInserted) const;
		void _iterateInsert(int signal, SignalCore_B::Direction direction);
		bool _combinable(
				Signal original,
				Signal toBeCombined) const
			/* only combinable if they are the same floor 
			 * and not opposite direction */
		{ return 
			toBeCombined.floor == original.floor
			&& 
			!_is_opposite(
					toBeCombined.direction,
					original.direction); 
		}
		void _combineInsert(
				std::forward_list<Signal>::iterator it,
				Signal toBeCombined);

	protected:
		std::forward_list<Signal>::iterator
			getInsertPosition(Signal sig);
		bool _insertableAtBeginning(int currentFloor, int signal, SignalCore_B::Direction direction) const;
		std::forward_list<Signal> signalList;

	public:
		SignalCore_Normal();
		~SignalCore_Normal();
		virtual void addSignal(
				int currentFloor, 
				int signal, 
				SignalCore_B::Direction direction) override;
		virtual void popSignal() override;
		virtual int getSignal() const override;
		virtual bool isEmpty() const override
		{ return signalList.empty(); }
		/**@brief a tester */
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

};

#endif
