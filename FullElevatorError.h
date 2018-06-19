#include <exception>

/**@brief an exception thrown when trying to load customers
 * to a full elevator 
 */
class FullElevatorError: public std::exception {
	public:
		enum Direction {up, down, none};
		explicit FullElevatorError(
				int flr,
				Direction dir = none,
				const char* msg = 
				"Elevator full when trying to load customers."): 
			floor(flr),
			direction(dir),
			message(msg) {}
		const char* what() const noexcept override
		{ return message; }
		const int getFloor() const noexcept
		{ return floor; }
		const Direction getDirection() const noexcept
		{ return direction; }
	private:
		const int floor;
		const Direction direction;
		const char* message;
};
