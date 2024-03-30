CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

.PHONY : all
all : program

program : Runner.cpp Utilities.o DataReader.o UserInterface.o Application.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Utilities.o : Utilities/Utilities.cpp Utilities/Utilities.h
	$(CXX) $(CXXFLAGS) -c $<

DataReader.o : Data/DataReader.cpp Data/DataReader.h
	$(CXX) $(CXXFLAGS) -c $<

UserInterface.o : UserInterface/UserInterface.cpp UserInterface/UserInterface.h
	$(CXX) $(CXXFLAGS) -c $<

Application.o : Application/Application.cpp Application/Application.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean :
	rm *.o
	rm *~
	rm program
