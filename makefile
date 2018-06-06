CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
LIBS = -lpthread # -lncurses # add at the end of a recipe
OBJ = CustomerList.o Elevator.o SignalCore_Normal.o Floor.o Platform.o
ELEGRAPHICSOBJ = eleGraphics/*.o


testPlatform: testPlatform.cpp elegraphics $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(ELEGRAPHICSOBJ) $< -o $@ $(LIBS)

testSignaledElevator: testSignaledElevator.cpp elegraphics $(OBJ) SignaledElevator.cpp
	$(CXX) $(CXXFLAGS) $(OBJ) $(ELEGRAPHICSOBJ) $< -o $@ $(LIBS)

testFloor: testFloor.cpp elegraphics CustomerList.o Elevator.o Floor.o
	$(CXX) $(CXXFLAGS) CustomerList.o Elevator.o Floor.o $(ELEGRAPHICSOBJ) $< -o $@ 

RawElevatorDemo: RawElevatorDemo.cpp elegraphics CustomerList.o Elevator.o
	$(CXX) $(CXXFLAGS) CustomerList.o Elevator.o $(ELEGRAPHICSOBJ) $< -o $@ 

elegraphics:
	$(MAKE) -C eleGraphics

Platform.o: Platform.cpp Platform.h SignaledElevator.h SignaledElevator.cpp 
	# SignaledElevator.* is template files.
	# Whenever they change, Platform.o should be recompiled
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(OBJ): %.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# for independent testing of different component
test%: test%.cpp %.o
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean

clean:
	$(RM) $(OBJ) *.o test*[^.][^c][^p][^p]
	$(MAKE) -C eleGraphics clean
