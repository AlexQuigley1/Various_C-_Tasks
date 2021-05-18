#include <iostream>
#include <string>

#include "ModPolyTester.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {

	while (argc > 1) {
		switch (argv[--argc][0]) {
		case 'a':
		{
			ModPolyTester t;
			t.testIntModDefCtor();
		}
		break;
		case 'b':
		{
			ModPolyTester t;
			t.testIntModValueCtor();
		}
		break;
		case 'c':
		{
			ModPolyTester t;
			t.testIntModAdd();
		}
		break;
		case 'd':
		{
			ModPolyTester t;
			t.testIntModMultiply();
		}
		break;
		case 'e':
		{
			ModPolyTester t;
			t.testIntModInverse();
		}
		break;
		case 'f':
		{
			ModPolyTester t;
			t.testIntModEquality();
		}
		break;
		case 'g':
		{
			ModPolyTester t;
			t.testIntModPrint();
		}
		break;
		case 'h':
		{
			ModPolyTester t;
			t.testPolyDefCtor();
		}
		break;
		case 'i':
		{
			ModPolyTester t;
			t.testPolyValueCtor();
		}
		break;
		case 'j':
		{
			ModPolyTester t;
			t.testPolyAdd();
		}
		break;
		case 'k':
		{
			ModPolyTester t;
			t.testPolyPrint();
		}
		break;
		case 'l':
		{
			ModPolyTester t;
			t.testModPolyDefCtor();
		}
		break;
		case 'm':
		{
			ModPolyTester t;
			t.testModPolyValueCtor();
		}
		break;
		case 'n':
		{
			ModPolyTester t;
			t.testModPolyAdd();
		}
		break;
		case 'o':
		{
			ModPolyTester t;
			t.testModPolyPrint();
		}
		break;
		case 'p':
		{
			ModPolyTester t;
			t.testPrintPretty();
		}
		break;
		default:
		{
			cout<<"Options are a -- p."<<endl;
		}
		break;
       	}
	}

	return 0;
}

