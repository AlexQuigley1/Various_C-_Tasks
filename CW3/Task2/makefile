# Makefile

# the C++ compiler
CXX     = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3 -std=c++14

#ifeq "$(CXXVERSION)" "4.6.3"
#	CXXFLAGS += -std=c++0x
#else
#	CXXFLAGS += -std=c++11
#endif

All: all
all: main

main: main.cpp Student.o Supervisor.o Project.o
	$(CXX) $(CXXFLAGS) main.cpp Student.o Supervisor.o Project.o -o main

Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp -o Student.o

Supervisor.o: Supervisor.cpp Supervisor.h
	$(CXX) $(CXXFLAGS) -c Supervisor.cpp -o Supervisor.o

Project.o: Project.cpp Project.h
	$(CXX) $(CXXFLAGS) -c Project.cpp -o Project.o
	
deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.gch *.stackdump

