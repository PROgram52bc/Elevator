#include "consoleSection.h"
#include <chrono>
#include <thread>
#include <string>

void refreshSection(Section& s)
{
	while(1)
		s.clrSection();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void printMsg(ConsoleSection& s, string str)
{
	while (1)
	{
		s.sendMsg(str);
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}

int main() {
	std::cout << conio::clrscr() << std::flush;
	
	unsigned width = 20,
			 height = 10;
	ConsoleSection c1(1, 1, width, height);
	ConsoleSection c2(c1.getConsecutiveCol(), c1.getStartRow(),
			width, height);
	ConsoleSection c3(c2.getConsecutiveCol(), c2.getStartRow(),
			width, height);
	std::thread t1(refreshSection, std::ref(c1));
	std::thread t2(printMsg, std::ref(c2), "This is c2 :)");
	std::thread t3(printMsg, std::ref(c3), "This is c3 :D");
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
