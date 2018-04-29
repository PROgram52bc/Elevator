# Tips for learning:
# $@ for target name
# $^ for all prerequisites
# $< for first prerequisites
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
OBJ = conio.o eleGraphics.o section.o
TESTCPP = testEleGraphics.cpp testSection.cpp
TESTEXE = $(basename $(TESTCPP))

# tests: $(TESTEXE)
# 
# $(TESTEXE): %: %.cpp $(OBJ)
# 	$(CXX) $(CXXFLAGS) $(OBJ) $< -o $@

testEleGraphics: testEleGraphics.cpp eleGraphics.o section.o conio.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

testSection: testSection.cpp section.o conio.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

eleGraphics.o: eleGraphics.cpp eleGraphics.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

section.o: section.cpp section.h conio.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

conio.o: conio.cpp conio.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(TESTEXE) *.o
