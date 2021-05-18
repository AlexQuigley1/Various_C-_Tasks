#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <utility>
#include <stdexcept>
#include "Poly.h"
#include "IntMod.h"
#include "ModPolyTester.h"

using namespace std;

ModPolyTester::ModPolyTester() : TesterBase() {
}

ModPolyTester::~ModPolyTester() {
}

void ModPolyTester::testIntModDefCtor() {
	funcname_ = "ModPolyTester::testIntModDefCtor";

	IntMod<8> a;
	if (a.toInt() != 0)
		errorOut_("Default constructor did not set value to 0",0);

	passOut_("Tested IntMod default constructor.");
}

void ModPolyTester::testIntModValueCtor() {
	funcname_ = "ModPolyTester::testIntModValueCtor";

	IntMod<8> a(5);
	if (a.toInt() != 5)
		errorOut_("Value constructor did not set value correctly",0);

	IntMod<7> b(20);
	if (b.toInt() != 6)
		errorOut_("Value constructor did not set value correctly",1);

	IntMod<13> c(26);
	if (c.toInt() != 0)
		errorOut_("Value constructor did not set value correctly",2);

	IntMod<6> d(-5);
	if (d.toInt() != 1)
		errorOut_("Value constructor did not set value correctly",3);

	passOut_("Tested IntMod value constructor.");
}

void ModPolyTester::testIntModAdd() {
	funcname_ = "ModPolyTester::testIntModAdd";

	IntMod<8> a, b, c;
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			a = i; b = j;
			c = a + b;
			if (c.toInt() != (i+j)%8)
				errorOut_("IntMod not added correctly",1);
		}
	}
	passOut_("Tested IntModAdd.");
}

void ModPolyTester::testIntModMultiply() {
	funcname_ = "ModPolyTester::testIntModMultiply";

	IntMod<8> a, b, c;
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			a = i; b = j;
			c = a * b;
			if (c.toInt() != (i*j)%8)
				errorOut_("IntMod not multiplied correctly",1);
		}
	}

	passOut_("Tested IntModMultiply.");
}

void ModPolyTester::testIntModInverse() {
	funcname_ = "ModPolyTester::testIntModInverse";

	IntMod<11> arr[]{1,2,3,4,5,6,7,8,9,10};
	int inv[]{1,6,4,3,9,2,8,7,5,10};
	for(int i=0;i<10;i++) {
		try {
			if (arr[i].inverse().toInt() != inv[i])
				errorOut_("IntMod inverse not correct",0);
		} catch (const std::exception& e) {
			errorOut_("IntMod inverse exception thrown when inverse exist",1);
		}
	}

	IntMod<10> a, b;
	for(int i=0;i<10;i++) {
		a = i;
		try {
			b = a.inverse();
			if (i!=1 && i!=3 && i!=7 && i!=9)
				errorOut_("IntMod inverse exception not thrown when inverse not exist",2);
		}
		catch(const std::domain_error& e) {
			if (i==1 || i==3 || i==7 || i==9)
				errorOut_("IntMod inverse exception thrown when inverse exist",3);
		}
	}

	passOut_("Tested IntModInverse.");
}

void ModPolyTester::testIntModEquality() {
	funcname_ = "ModPolyTester::testIntModEquality";

	IntMod<8> a(4);
	IntMod<8> b(5);
	IntMod<8> c(12);
	IntMod<8> d(-3);
	if (a==b) errorOut_("Unequal IntMod reported as equal",1);
	if (!(a==c)) errorOut_("Equal IntMod reported as unequal",2);
	if (!(b==d)) errorOut_("Equal IntMod reported as unequal",2);

	passOut_("Tested IntModEquality.");
}

void ModPolyTester::testIntModPrint() {
	funcname_ = "ModPolyTester::testIntModPrint";

	cout << "------------ Program should print: ------------" << endl;
	string ans = "0123456701234567";
	cout << ans << endl;

	cout << "-------------- Program printed:  --------------" << endl;
	stringstream ss;
	IntMod<8> a;
	for(int i=0;i<16;i++) {
		a = i;
		ss << a;
	}
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("IntMod print not correct",0);

	passOut_("Tested IntModPrint.");
}

void ModPolyTester::testPolyDefCtor() {
	funcname_ = "ModPolyTester::testPolyDefCtor";

	Polynomial<int> p;
	if (p.degree() != 0) errorOut_("Poly def ctor degree not 0",0);
	if (p.getCoef(0) != 0) errorOut_("Poly def ctor coef not 0",1);

	Polynomial<double> q;
	if (q.degree() != 0) errorOut_("Poly def ctor degree not 0",2);
	if (q.getCoef(0) != 0) errorOut_("Poly def ctor coef not 0",3);

	passOut_("Tested PolyDefCtor.");
}

void ModPolyTester::testPolyValueCtor() {
	funcname_ = "ModPolyTester::testPolyValueCtor";

	vector<int> v{3,2,1,0,-1,-2,-3};
	Polynomial<int> p(v);
	if (p.degree() != 6) errorOut_("Poly val ctor degree not correct",0);
	for(int i=0;i<7;i++)
		if (p.getCoef(i) != v[6-i]) errorOut_("Poly val ctor coef not correct",1);

	v[0] = 0;
	Polynomial<int> p2(v);
	if (p2.degree() != 5) errorOut_("Poly val ctor degree not correct",2);

	vector<double> w{3.7,2.7,1.7,0.7,-0.3,-1.3,-2.3};
	Polynomial<double> q(w);
	if (q.degree() != 6) errorOut_("Poly val ctor degree not correct",3);
	for(int i=0;i<7;i++)
		if (q.getCoef(i) != w[6-i]) errorOut_("Poly val ctor coef not correct",4);

	passOut_("Tested PolyValueCtor.");
}

void ModPolyTester::testPolyAdd () {
	funcname_ = "ModPolyTester::testPolyAdd";

	Polynomial<int> p({3,2,1, 0,-1,-2,-3});
	Polynomial<int> q({    3,-1, 1, 3,-5});
	vector<int>   res {3,2,4,-1, 0, 1,-8};
	Polynomial<int> sum = p + q;

	if (sum.degree() != 6) errorOut_("Poly add deg not correct",0);
	for(int i=0;i<7;i++)
		if (sum.getCoef(i) != res[6-i]) errorOut_("Poly add coef not correct",1);

	// test trim
	sum = sum + Polynomial<int>({-3,-2,0,0,0,0,0});
	res = {0,0,4,-1,0,1,-8};
	if (sum.degree() != 4) errorOut_("Poly add deg not correct",2);
	for(int i=0;i<7;i++)
		if (sum.getCoef(i) != res[6-i]) errorOut_("Poly add coef not correct",3);

	// double
	Polynomial<double> pp({3.5,2.5,1.5, 0.5,-1.5,-2.5,-3.5});
	Polynomial<double> qq({        3  ,-1  , 1.5, 3  ,-5  });
	vector<double> ress   {3.5,2.5,4.5,-0.5,   0, 0.5,-8.5};
	Polynomial<double> summ = pp + qq;
	if (summ.degree() != 6) errorOut_("Poly add deg not correct",4);
	for(int i=0;i<7;i++)
		if (summ.getCoef(i) != ress[6-i]) errorOut_("Poly add coef not correct",5);

	passOut_("Tested PolyAdd.");
}

void ModPolyTester::testPolyPrint() {
	funcname_ = "ModPolyTester::testPolyPrint";

	cout << "------------ Program should print: ------------" << endl;
	string ans = "3x^6 + 2x^5 + 1x^4 + 0x^3 + -1x^2 + -2x^1 + -3x^0";
	cout << ans << endl;

	cout << "-------------- Program printed:  --------------" << endl;
	stringstream ss;
	Polynomial<int> p({3,2,1,0,-1,-2,-3});
	ss << p;
	cout << ss.str() << endl;

	if (ans != ss.str()) errorOut_("Poly print not correct",0);
	else passOut_("Tested PolyPrint");
}

void ModPolyTester::testModPolyDefCtor() {
	funcname_ = "ModPolyTester::testModPolyDefCtor";

	Polynomial< IntMod<8> > p;
	if (p.degree() != 0) errorOut_("ModPoly def ctor deg not 0",0);
	if (p.getCoef(0).toInt() != 0) errorOut_("ModPoly def ctor coef not 0",0);

	passOut_("Tested ModPolyDefCtor");
}

void ModPolyTester::testModPolyValueCtor () {
	funcname_ = "ModPolyTester::testModPolyValueCtor";

	vector< int > w{1,1,0,2,0,7,0};
	Polynomial< IntMod<8> > p({1,9,8,10,0,-1,-8});
	if (p.degree() != 6) errorOut_("ModPoly value ctor deg not correct",0);
	for(int i=0;i<7;i++)
		if (p.getCoef(i).toInt() != w[6-i])
			errorOut_("ModPoly value ctor coef not correct",0);

	passOut_("Tested ModPolyValueCtor");
}

void ModPolyTester::testModPolyAdd () {
	funcname_ = "ModPolyTester::testModPolyAdd";

	Polynomial< IntMod<8> > p({2,3,5, 7,0,1, 4,6});
	Polynomial< IntMod<8> > q({    3,-1,1,3,-5,1});
	Polynomial< IntMod<8> > sum = p + q;
	vector< int > res{2,3,0,6,1,4,7,7};
	if (sum.degree() != 7) errorOut_("ModPoly add deg not correct",0);
	for(int i=0;i<8;i++)
		if (sum.getCoef(i).toInt() != res[7-i]) errorOut_("ModPoly add coef not correct",1);

	// test trim
	sum = sum + Polynomial< IntMod<8> >({6,5,0,2,0,0,0,0});
	res = {0,0,0,0,1,4,7,7};
	if (sum.degree() != 3) errorOut_("ModPoly add deg not correct",2);
	for(int i=0;i<8;i++)
		if (sum.getCoef(i).toInt() != res[7-i]) errorOut_("ModPoly add coef not correct",3);

	passOut_("Tested ModPolyAdd");
}

void ModPolyTester::testModPolyPrint () {
	funcname_ = "ModPolyTester::testModPolyPrint";

	cout << "------------ Program should print: ------------" << endl;
	string ans = "3x^6 + 2x^5 + 1x^4 + 0x^3 + 7x^2 + 6x^1 + 5x^0";
	cout << ans << endl;

	cout << "-------------- Program printed:  --------------" << endl;
	stringstream ss;
	vector< IntMod<8> > u = {3,2,1,0,-1,-2,-3};
	Polynomial < IntMod<8> > p{u};
	ss << p;
	cout << ss.str() << endl;

	if (ans != ss.str()) errorOut_("ModPoly print not correct",0);
	else passOut_("Tested ModPolyPrint");
}

void ModPolyTester::testPrintPretty() {
	funcname_ = "ModPolyTester::testPrintPretty";

	stringstream ss;
	string res, ans;

	// x^1 and x^0 without exponents
	Polynomial<int> p({2,3,4,5});
	cout << "------------ Program should print: ------------" << endl;
	ans = "2x^3 + 3x^2 + 4x + 5";
	cout << ans << endl;
	ss << p;
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("x^1 and x^0 not handled",1);

	stringstream().swap(ss);

	// skip terms with zero coefficients
	// no leading zeros even as result of calculations
	p = Polynomial<int>({ 2,0, 3,0, 4,0, 5,0});
	Polynomial<int> p2 ({-2,0,-3,0, 0,0, 0,0});
	Polynomial<int> p3 ({ 0,0, 0,0,-4,0,-5,0});
	cout << "------------ Program should print: ------------" << endl;
	ans = "2x^7 + 3x^5 + 4x^3 + 5x\n4x^3 + 5x\n0";
	cout << ans << endl;
	ss << p << endl << (p+p2) << endl << (p+p2+p3);
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("Did not skip terms with zero coefficients",2);

	stringstream().swap(ss);

	// skip plus sign for negative coefficients... but leading term is different
	p = Polynomial<int>({-2,-3,-4,-5});
	cout << "------------ Program should print: ------------" << endl;
	ans = "-2x^3 - 3x^2 - 4x - 5";
	cout << ans << endl;
	ss << p;
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("plus/minus sign not handled correctly",3);

	stringstream().swap(ss);

	// coefficient 1 not printed, except constant term
	p = Polynomial<int>({1,-1,1,-1,1});
	cout << "------------ Program should print: ------------" << endl;
	ans = "x^4 - x^3 + x^2 - x + 1\n-x^4 + x^3 - x^2 + x - 1";
	cout << ans << endl;
	ss << p << endl;
	p = Polynomial<int>({-1,1,-1,1,-1});
	ss << p;
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("coefficient 1 printed incorrectly",4);

	stringstream().swap(ss);

	// just one constant term... and this time 0 should be printed
	Polynomial<int> one({1});
	Polynomial<int> minusone({-1});
	cout << "------------ Program should print: ------------" << endl;
	ans = "0\n1\n-1\n2\n-2";
	cout << ans << endl;
	ss << (minusone + one) << endl
		<< one << endl
		<< minusone << endl
		<< (one + one) << endl
		<< (minusone + minusone);
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("constants printed incorrectly",5);

	stringstream().swap(ss);

	// x, 2x
	one = Polynomial<int>({1,0});
	minusone = Polynomial<int>({-1,0});
	cout << "------------ Program should print: ------------" << endl;
	ans = "x\n-x\n2x\n-2x";
	cout << ans << endl;
	ss << one << endl
		<< minusone << endl
		<< (one + one) << endl
		<< (minusone + minusone);
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("constants printed incorrectly",5);

	stringstream().swap(ss);

	// the "negative mod trap"
	Polynomial < IntMod<8> > q({1,8,-1,7,0});
	cout << "------------ Program should print: ------------" << endl;
	ans = "x^4 + 7x^2 + 7x\n7x^4 + x^2 + x";
	cout << ans << endl;
	ss << q << endl;
	q = Polynomial< IntMod<8> >({-1,8,1,-7,0});
	ss << q;
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("IntMod coefficients printed incorrectly",6);

	stringstream().swap(ss);

	// mod 2 and the "-1=1" trap
	Polynomial < IntMod<2> > r({1,-1,1});
	cout << "------------ Program should print: ------------" << endl;
	ans = "x^2 + x + 1\nx^2 + x + 1";
	cout << ans << endl;
	ss << r << endl;
	r = Polynomial< IntMod<2> >({-1,1,-1});
	ss << r;
	cout << "-------------- Program printed:  --------------" << endl;
	cout << ss.str() << endl;
	if (ans != ss.str()) errorOut_("IntMod coefficients printed incorrectly",6);

	passOut_("Tested PrintPretty");
}
