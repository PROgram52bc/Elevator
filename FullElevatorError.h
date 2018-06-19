#include <exception>
#include "ElevatorState.h"

/**@brief an exception thrown when trying to load customers
 * to a full elevator 
 */
class FullElevatorError: public std::exception {
	public:
		explicit FullElevatorError(
				int flr,
				ElevatorDirection dir = none,
				const char* msg = 
				"Elevator full when trying to load customers."): 
			floor(flr),
			direction(dir),
			message(msg) {}
		const char* what() const noexcept override
		{ return message; }
		const int getFloor() const noexcept
		{ return floor; }
		const ElevatorDirection getDirection() const noexcept
		{ return direction; }
	private:
		const int floor;
		const ElevatorDirection direction;
		const char* message;
};
