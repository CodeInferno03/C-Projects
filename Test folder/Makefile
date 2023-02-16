CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = test.o

test: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o test test.o

Rune_trial.o: test.cpp 
	$(CXX) -g $(CXXFLAGS) -c test.cpp

clean:
	rm -f *.o
	rm test