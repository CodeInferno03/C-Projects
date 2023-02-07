CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = Rune_sim.o

Rune_sim: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o Rune_sim Rune_sim.o

Rune_trial.o: Rune_sim.cpp 
	$(CXX) -g $(CXXFLAGS) -c Rune_sim.cpp

clean:
	rm -f *.o
	rm Rune_sim