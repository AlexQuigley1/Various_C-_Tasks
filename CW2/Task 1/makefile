# Makefile

# the C++ compiler
CXX     = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3

ifeq "$(CXXVERSION)" "4.6.3"
	CXXFLAGS += -std=c++0x
else
	CXXFLAGS += -std=c++11
endif

All: all
all: main BiArrayTesterMain

main: main.cpp BiArray.o
	$(CXX) $(CXXFLAGS) main.cpp BiArray.o -o main

BiArray.o: BiArray.cpp BiArray.h
	$(CXX) $(CXXFLAGS) -c BiArray.cpp -o BiArray.o

BiArrayTesterMain: BiArrayTesterMain.cpp BiArray.o BiArrayTester.o TesterBase.o
	$(CXX) $(CXXFLAGS) BiArrayTesterMain.cpp BiArray.o BiArrayTester.o TesterBase.o -o BiArrayTesterMain

BiArrayTester.o: BiArrayTester.cpp BiArrayTester.h	
	$(CXX) $(CXXFLAGS) -c BiArrayTester.cpp -o BiArrayTester.o

TesterBase.o: TesterBase.cpp TesterBase.h
	$(CXX) $(CXXFLAGS) -c TesterBase.cpp -o TesterBase.o

deepclean: 
	rm -f *~ *.o main *.exe *.stackdump main

clean:
	-rm -f *~ *.o *.stackdump

