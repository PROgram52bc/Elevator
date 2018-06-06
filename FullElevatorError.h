#include <exception>

/**@brief an exception thrown when trying to load customers
 * to a full elevator 
 */
class FullElevatorError: public std::exception {
	private:
		const int floor;
		const char* message;
	public:
		explicit FullElevatorError(
				int flr,
				const char* msg = 
				"Elevator full when trying to load customers."): 
			floor(flr),
			message(msg) {}
		const char* what() const noexcept override
		{ return message; }
		const int getFloor() const noexcept
		{ return floor; }
};
