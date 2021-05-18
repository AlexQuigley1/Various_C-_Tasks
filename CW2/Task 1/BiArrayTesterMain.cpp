#include <iostream>
#include <string>

#include "BiArrayTester.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {

	while (argc > 1) {
		switch (argv[--argc][0]) {			
		case 'a':
		{
			BiArrayTester t;
			t.testDefCtor();
		}
		break;
		case 'b':
		{
			BiArrayTester t;
			t.testValueCtor();
		}
		break;
		case 'c':
		{
			BiArrayTester t;
			t.testCopyCtor();
		}
		break;
		case 'd'://this broke
		{
			BiArrayTester t;
			t.testMoveCtor();
		}
		break;
		case 'e':
		{
			BiArrayTester t;
			t.testCopyAsg();
		}
		break;
		case 'f':
		{
			BiArrayTester t;
			t.testMoveAsg();
		}
		break;
		case 'g':
		{
			BiArrayTester t;
			t.testGet();
		}
		break;
		case 'h':
		{
			BiArrayTester t;
			t.testSet();
		}
		break;
		case 'i':
		{
			BiArrayTester t;
			t.testOperatorBracketConst();
		}
		break;
		case 'j':
		{
			BiArrayTester t;
			t.testOperatorBracket();
		}
		break;
		case 'k':
		{	
			BiArrayTester t;
			t.testGetSize();
		}
		break;
		case 'l':
		{	
			BiArrayTester t;
			t.testPrint();
		}
		break;
		case 'm':
		{
			BiArrayTester t;
			t.testPushBack();
		}
		break;
		case 'n':
		{
			BiArrayTester t;
			t.testPopBack();
		}
		break;
		case 'o':
		{
			BiArrayTester t;
			t.testPushFront();
		}
		break;
		case 'p':
		{
			BiArrayTester t;
			t.testPopFront();
		}
		break;
		case 'q':
		{	
			BiArrayTester t;
			t.testResizing();
		}
		break;
		case 'r':
		{	
			BiArrayTester t;
			t.testOperatorEqual();
		}
		break;
		case 's':
		{	
			BiArrayTester t;
			t.testOperatorUnequal();
		}
		break;
		default:
		{
			cout<<"Options are a -- s."<<endl;
		}
		break;
       	}		
	}
	
	return 0;
}

