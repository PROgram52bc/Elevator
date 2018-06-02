CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
LIBS = -lpthread # -lncurses # add at the end of a recipe
OBJ = CustomerList.o Elevator.o SignalCore_Normal.o SignaledElevator.o Floor.o
ELEGRAPHICSOBJ = eleGraphics/*.o
TESTELEVATORCPP = testElevator.cpp 
TESTELEVATOREXE = $(basename $(TESTELEVATORCPP))

# for multiple testing of the elevator class
$(TESTELEVATOREXE): %: %.cpp elegraphics $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(ELEGRAPHICSOBJ) $< -o $@ 

# for independent testing of different component
test%: test%.cpp %.o
	$(CXX) $(CXXFLAGS) $^ -o $@

testSignaledElevator: testSignaledElevator.cpp elegraphics $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(ELEGRAPHICSOBJ) $< -o $@ $(LIBS)

testFloor: testFloor.cpp elegraphics $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(ELEGRAPHICSOBJ) $< -o $@ 

RawElevatorDemo: RawElevatorDemo.cpp elegraphics $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(ELEGRAPHICSOBJ) $< -o $@ 

elegraphics:
	$(MAKE) -C eleGraphics

$(OBJ): %.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

.PHONY: clean

clean:
	$(RM) $(OBJ) *.o test*[^.][^c][^p][^p]
	$(MAKE) -C eleGraphics clean
