CXX = g++
CXXFLAGS = -std=c++11
OBJ = Elevator.o eleGraphics/*.o
TESTCPP = testElevator2.cpp testElevator.cpp
TESTEXE = $(basename $(TESTCPP))


elegraphics:
	$(MAKE) -C eleGraphics

Elevator.o: Elevator.cpp Elevator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

tests: $(TESTEXE)

$(TESTEXE): %: %.cpp elegraphics Elevator.o
	$(CXX) $(CXXFLAGS) $(OBJ) $< -o $@

cleanTest:
	$(RM) $(TESTEXE)

clean:
	$(RM) $(TESTEXE)

cleanAll:
	$(RM) $(TESTEXE) $(OBJ)
