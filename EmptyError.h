#include <iostream>
#include <exception>

/**@brief an exception indicating container is empty */ 
class EmptyError: public std::exception {
	private:
		const char* message;
	public:
		explicit EmptyError(const char* msg): message(msg) {}
		const char* what() const noexcept override { return message; }
};
