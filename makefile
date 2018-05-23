CXX = g++
CXXFLAGS = -std=c++11 
LIBS = -lncurses #add at the end of a recipe
OBJ = CustomerList.o Elevator.o
TESTELEVATORCPP = testElevator.cpp testElevator2.cpp 
TESTELEVATOREXE = $(basename $(TESTELEVATORCPP))

# for multiple testing of the elevator class
$(TESTELEVATOREXE): %: %.cpp elegraphics $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) eleGraphics/*.o $< -o $@ 

# for independent testing of different component
test%: test%.cpp %.o
	$(CXX) $(CXXFLAGS) $^ -o $@

elegraphics:
	$(MAKE) -C eleGraphics

$(OBJ): %.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

tests: $(TESTEXE)

clean:
	$(RM) $(OBJ) *.o test*[^.][^c][^p][^p]
	$(MAKE) -C eleGraphics clean
