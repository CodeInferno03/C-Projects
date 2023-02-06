CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = Rune_trial.o

Rune_trial: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o Rune_trial Rune_trial.o

Rune_trial.o: Rune_trial.cpp 
	$(CXX) -g $(CXXFLAGS) -c Rune_trial.cpp

clean:
	rm -f *.o
	rm Rune_trial