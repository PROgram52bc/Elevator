CXX = g++
CXXFLAGS = -std=c++11
OBJ = Elevator.o eleGraphics/*.o
TESTEXE = testElevator
TESTCXX = testElevator.cpp

$(TESTEXE): Elevator.o elegraphics $(TESTCXX)
	$(CXX) $(CXXFLAGS) $(OBJ) $(TESTCXX) -o $@

elegraphics:
	$(MAKE) -C eleGraphics

Elevator.o: Elevator.cpp Elevator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	$(RM) $(TESTEXE)
