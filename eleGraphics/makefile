# Tips for learning:
# $@ for target name
# $^ for all prerequisites
# $< for first prerequisites
CXX = g++
CXXFLAGS = -std=c++11
OBJ = conio.o eleGraphics.o section.o
TESTCPP = testEleGraphics.cpp 
TESTEXE = $(basename $(TESTCPP))

tests: $(TESTEXE)

$(TESTEXE): %: %.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $< -o $@

eleGraphics.o: eleGraphics.cpp eleGraphics.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

testSection: testSection.cpp section.o
	$(CXX) $(CXXFLAGS) testSection.cpp section.o conio.o -o $@

section.o: section.cpp section.h conio.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

conio.o: conio.cpp conio.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o

cleanAll:
	$(RM) $(TESTEXE) *.o
