# Tips for learning:
# $@ for target name
# $^ for all prerequisites
# $< for first prerequisites
CXX = g++
CXXFLAGS = -std=c++11
TESTEXE = testElegraphics
$(TESTEXE): conio.o eleGraphics.o testEleGraphics.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

eleGraphics.o: eleGraphics.cpp eleGraphics.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

conio.o: conio.cpp conio.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o

cleanall:
	$(RM) $(TESTEXE) *.o
