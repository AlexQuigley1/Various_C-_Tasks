#ifndef BIARRAYTESTER_H_
#define BIARRAYTESTER_H_

#include "TesterBase.h"

class ModPolyTester : public TesterBase {
public:
	ModPolyTester();
	~ModPolyTester();

	// Please note that, despite their names, these test functions do not
	// just test the corresponding function; there are dependencies on
	// other functions.
	// Getters like toInt(), degree() and getCoef() are not tested
	// separately as other test cases rely on them already

	// These only need IntMod
	void testIntModDefCtor(); // 1 mark
	void testIntModValueCtor(); // 2 marks
	void testIntModAdd(); // 2 marks
	void testIntModMultiply(); // 2 marks
	void testIntModInverse(); // 3 marks
	void testIntModEquality(); // 2 marks
	void testIntModPrint(); // 2 marks

	// These only need Poly
	void testPolyDefCtor(); // 2 marks
	void testPolyValueCtor(); // 3 marks
	void testPolyAdd(); // 4 marks
	void testPolyPrint(); // 3 marks

	// IntMod + Poly
	// theoretically, no extra work is needed to pass these test cases
	void testModPolyDefCtor(); // 1 mark
	void testModPolyValueCtor(); // 1 mark
	void testModPolyAdd(); // 1 mark
	void testModPolyPrint(); // 1 mark

	// passing this automatically gets the marks for PolyPrint and
	// ModPolyPrint as well
	void testPrintPretty(); // up to 5 bonus marks
};

#endif /* BIARRAYTESTER_H_ */
