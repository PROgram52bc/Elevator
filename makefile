CXX = g++
CXXFLAGS = -std=c++11 
LIBS = -lncurses #add at the end of a recipe
OBJ = eleGraphics/*.o *.o
TESTELEVATORCPP = testElevator2.cpp testElevator.cpp
TESTELEVATOREXE = $(basename $(TESTELEVATORCPP))

# for multiple testing of the elevator class
$(TESTELEVATOREXE): %: %.cpp elegraphics Elevator.o
	$(CXX) $(CXXFLAGS) $(OBJ) $< -o $@ 

# for general testing of different component
test%: test%.cpp %.o
	$(CXX) $(CXXFLAGS) $^ -o $@

elegraphics:
	$(MAKE) -C eleGraphics

Elevator.o: Elevator.cpp Elevator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

tests: $(TESTEXE)

clean:
	$(RM) $(OBJ) *.o test*[^.][^c][^p][^p]
	$(MAKE) -C eleGraphics clean
