# Tips for learning:
# $@ for target name
# $^ for all prerequisites
# $< for first prerequisites
CMD = g++
FLAG = -std=c++11
target: conio.o eleGraphics.o testEleGraphics.cpp
	$(CMD) $(FLAG) $^ -o $@

eleGraphics.o: eleGraphics.cpp eleGraphics.h
	$(CMD) $(FLAG) -c $< -o $@ 

conio.o: conio.cpp
	$(CMD) $(FLAG) -c $^ -o $@

clean:
	rm *.o

cleanall:
	rm target *.o
