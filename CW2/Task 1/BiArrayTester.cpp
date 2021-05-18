#include <stdlib.h>
#include <iostream>
#include <utility>

#include "BiArrayTester.h"
#include "BiArray.h"

BiArrayTester::BiArrayTester() : TesterBase() {
}

BiArrayTester::~BiArrayTester() {
}

void BiArrayTester::testDefCtor() {
	funcname_ = "BiArrayTester::testDefCtor";

	BiArray a;
	if (a.getSize() != 0 || a.getCapacity() != INITIALCAP)
		errorOut_("Empty BiArray not constructed correctly",0);

	passOut_("Tested the default constructor.");
}

void BiArrayTester::testValueCtor() {
	funcname_ = "BiArrayTester::testValueCtor";

	int arr1[1] = {0};
	BiArray a1(arr1,1);
	if (a1.getSize() != 1 || a1.getCapacity() != INITIALCAP)
		errorOut_("size-1 value constructor incorrect size or capacity",1);
	if (a1[0] != 0) errorOut_("size-1 value constructor incorrect content",2);

	int arr2[10] = {0,1,2,3,4,5,6,7,8,9};
	BiArray a2(arr2,10);
	if (a2.getSize() != 10 || a2.getCapacity() != 30)
		errorOut_("value constructor incorrect size or capacity",3);
	for(int i=0;i<10;i++)
		if (a2[i] != i) errorOut_("value constructor incorrect content",4);

	passOut_("Tested the value constructor.");
}


void BiArrayTester::testCopyCtor() {
	funcname_ = "BiArrayTester::testCopyCtor";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	BiArray b(a);
	if (b.getSize() != 10 || a.getSize() != 10) errorOut_("Unequal size reported",0);
	 for(int i=0;i<10;i++) 
	 
	 	if (b[i]!=a[i] || b[i]!=i || a[i]!=i) errorOut_("Unequal value detected",1);
	
	passOut_("Tested the copy constructor.");
}

void BiArrayTester::testMoveCtor() {
	funcname_ = "BiArrayTester::testMoveCtor";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	BiArray b = std::move(a);
	if (b.getSize() != 10) errorOut_("Unequal size reported",0);
	for(int i=0;i<10;i++) 
		if (b[i]!=i) errorOut_("Unequal value detected",1);

	passOut_("Tested the move constructor.");
}

void BiArrayTester::testCopyAsg() {
	funcname_ = "BiArrayTester::testCopyAsg";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	BiArray b;
	b = a;
	if (b.getSize() != 10 || a.getSize() != 10) errorOut_("Unequal size reported",0);
	for(int i=0;i<10;i++) 
		if (b[i]!=a[i] || b[i]!=i || a[i]!=i)
			errorOut_("Unequal value detected",1);

	passOut_("Tested the copy assignment operator.");
}

void BiArrayTester::testMoveAsg() {
	funcname_ = "BiArrayTester::testMoveAsg";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	BiArray b;
	b = std::move(a);
	if (b.getSize() != 10) errorOut_("Unequal size reported",0);
	for(int i=0;i<10;i++) 
		if (b[i]!=i)
			errorOut_("Unequal value detected",1);

	passOut_("Tested the move assignment operator.");
}

void BiArrayTester::testGet () {
	funcname_ = "BiArrayTester::testGet";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	int v; bool b;
	for(int i=0;i<10;i++) {
		b = a.get(i,v);
		if (!b) errorOut_("get returned false when in bounds",1);
		if (v != i) errorOut_("get retrieved wrong value",2);
	}
	b = a.get(-1,v);
	if (b) errorOut_("get returned true when out of bounds",3);
	b = a.get(10,v);
	if (b) errorOut_("get returned true when out of bounds",4);

	passOut_("Tested get.");
}

void BiArrayTester::testSet () {
	funcname_ = "BiArrayTester::testSet";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	int v; bool b;
	for(int i=0;i<10;i++) {
		b = a.set(i,i);
		if (!b) errorOut_("set returned false when in bounds",1);
		a.get(i,v);
		if (v != i) errorOut_("set wrong value",2);
	}
	b = a.set(-1,0);
	if (b) errorOut_("set returned true when out of bounds",3);
	b = a.set(10,0);
	if (b) errorOut_("set returned true when out of bounds",4);

	passOut_("Tested set.");
}

void BiArrayTester::testOperatorBracketConst() {
	funcname_ = "BiArrayTester::testOperatorBracketConst";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	const BiArray& b = a;
	for(int i=0;i<10;i++) {
		if (b[i] != i) errorOut_("OperatorBracketConst wrong",1);
	}

	passOut_("Tested OperatorBracketConst");
}

void BiArrayTester::testOperatorBracket() {
	funcname_ = "BiArrayTester::testOperatorBracket";

	int arr[]{0,0,0,0,0,0,0,0,0,0};
	BiArray a{arr,10};
	for(int i=0;i<10;i++) a[i] = i;
	int v;
	for(int i=0;i<10;i++) {
		a.get(i,v);
		if (v != i) errorOut_("OperatorBracket wrong",1);
	}

	passOut_("Tested OperatorBracket");
}

void BiArrayTester::testGetSize () {
	funcname_ = "BiArrayTester::testGetSize";

	BiArray a;
	if (a.getSize() != 0) errorOut_("getSize wrong size",1);
	for(int i=0;i<10;i++) {
		a.push_back(i);
		if (a.getSize() != i+1) errorOut_("getSize wrong size",2);
	}
	for(int i=0;i<10;i++) {
		a.pop_front();
		if (a.getSize() != 9-i) errorOut_("getSize wrong size",3);
	}

	passOut_("Tested getSize");
}

void BiArrayTester::testPrint () {
	funcname_ = "BiArrayTester::testPrint";

	BiArray a;
	string s = "[]";
	if (s != a.print()) errorOut_("Error printing empty biarray",1);

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray b{arr,10};
	s = "[0 1 2 3 4 5 6 7 8 9]";
	if (s != b.print()) errorOut_("Error printing biarray",2);

	passOut_("Tested print");
}

void BiArrayTester::testPushBack () {
	funcname_ = "BiArrayTester::testPushBack";

	BiArray a;
	for(int i=0;i<10;i++) {
		a.push_back(i);
		if (a.getSize() != i+1) errorOut_("Push_back wrong size",1);
	}
	for(int i=0;i<10;i++) {
		if (a[i] != i) errorOut_("Push_back wrong value",2);
	}

	passOut_("Tested PushBack");
}

void BiArrayTester::testPopBack() {
	funcname_ = "BiArrayTester::testPopBack";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	bool b;
	for(int i=0;i<10;i++) {
		if (a[9-i]!=9-i) errorOut_("Pop_back wrong value",1);
		b = a.pop_back();
		if (a.getSize() != 9-i) errorOut_("Pop_back wrong size",2);
		if (!b) errorOut_("Pop_back returned false when not empty",3);
	}
	b = a.pop_back();
	if (b) errorOut_("Pop_back returned true when empty",4);

	passOut_("Tested PopBack");
}

void BiArrayTester::testPushFront () {
	funcname_ = "BiArrayTester::testPushFront";

	BiArray a;
	for(int i=0;i<10;i++) {
		a.push_front(i);
		if (a.getSize() != i+1) errorOut_("Push_front wrong size",1);
	}
	for(int i=0;i<10;i++) {
		if (a[i] != 9-i) errorOut_("Push_front wrong value",2);
	}

	passOut_("Tested PushFront");
}

void BiArrayTester::testPopFront () {
	funcname_ = "BiArrayTester::testPopFront";

	int arr[]{0,1,2,3,4,5,6,7,8,9};
	BiArray a{arr,10};
	bool b;
	for(int i=0;i<10;i++) {
		if (a[0]!=i) errorOut_("Pop_front wrong value",1);
		b = a.pop_front();
		if (a.getSize() != 9-i) errorOut_("Pop_front wrong size",2);
		if (!b) errorOut_("Pop_front returned false when not empty",3);
	}
	b = a.pop_front();
	if (b) errorOut_("Pop_front returned true when empty",4);

	passOut_("Tested PopFront");

}

void BiArrayTester::testResizing () {
	funcname_ = "BiArrayTester::testResizing";

	BiArray a;
	if (a.getCapacity() != INITIALCAP) errorOut_("wrong capacity",1);
	for(int i=0;i<100;i++) {
		a.push_back(i);
		if (a.getCapacity() < INITIALCAP) errorOut_("wrong capacity",6);
		if (a.getCapacity() < a.getSize() || a.getCapacity() > 5*a.getSize()) errorOut_("wrong capacity",2);
	}
	for(int i=0;i<100;i++) {
		a.push_front(i);
		if (a.getCapacity() < INITIALCAP) errorOut_("wrong capacity",6);
		if (a.getCapacity() < a.getSize() || a.getCapacity() > 5*a.getSize()) errorOut_("wrong capacity",3);
	}
	for(int i=0;i<100;i++) {
		a.pop_back();
		if (a.getCapacity() < INITIALCAP) errorOut_("wrong capacity",6);
		if (a.getCapacity() < a.getSize() || a.getCapacity() > 5*a.getSize()) errorOut_("wrong capacity",4);
	}
	for(int i=0;i<99;i++) {
		a.pop_front();
		if (a.getCapacity() < INITIALCAP) errorOut_("wrong capacity",6);
		if (a.getCapacity() < a.getSize() || a.getCapacity() > 5*a.getSize()) {
			errorOut_("wrong capacity",5);}
	}

	passOut_("Tested resizing");
}

void BiArrayTester::testOperatorEqual() {
	funcname_ = "BiArrayTester::testOperatorEqual";

	BiArray a;
	BiArray b;
	if (!(a==b)) errorOut_("Equal BiArrays reported as unequal",1);

	for(int i=0;i<9;i++) a.push_back(i);
	for(int i=0;i<10;i++) b.push_back(i);
	if (a==b) errorOut_("Unequal BiArrays reported as equal",2);

	a.push_back(9);
	if (!(a==b)) errorOut_("Equal BiArrays reported as unequal",3);

	b.set(5,6);
	if (a==b) errorOut_("Unequal BiArrays reported as equal",4);

	BiArray c;
	BiArray d;
	for(int i=0;i<10;i++) c.push_back(i);
	for(int i=9;i>=0;i--) d.push_front(i);
	if (!(c==d)) errorOut_("Equal BiArrays reported as unequal",5);
	passOut_("Tested operator equal.");
}

void BiArrayTester::testOperatorUnequal() {
	funcname_ = "BiArrayTester::testOperatorUnequal";

	BiArray a;
	BiArray b;
	if (a!=b) errorOut_("Equal BiArrays reported as unequal",1);

	for(int i=0;i<9;i++) a.push_back(i);
	for(int i=0;i<10;i++) b.push_back(i);
	if (!(a!=b)) errorOut_("Unequal BiArrays reported as equal",2);

	a.push_back(9);
	if (a!=b) errorOut_("Equal BiArrays reported as unequal",3);

	b.set(5,6);
	if (!(a!=b)) errorOut_("Unequal BiArrays reported as equal",4);

	BiArray c;
	BiArray d;
	for(int i=0;i<10;i++) c.push_back(i);
	for(int i=9;i>=0;i--) d.push_front(i);
	if (c!=d) errorOut_("Equal BiArrays reported as unequal",5);
	passOut_("Tested operator unequal.");
}
