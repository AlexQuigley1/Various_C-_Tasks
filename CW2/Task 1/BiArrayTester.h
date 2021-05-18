#ifndef BIARRAYTESTER_H_
#define BIARRAYTESTER_H_

#include "TesterBase.h"

class BiArrayTester : public TesterBase {
public:
	BiArrayTester();
	~BiArrayTester();

	// Please note that, despite their names, these test functions do not
	// just test the corresponding method; there are dependencies on 
	// other methods. For example to pass testDefCtor() you will need to
	// implement getSize() correctly as well, and to pass testGetSize() 
	// you will need to implement the default constructor correctly.

	void testDefCtor(); // 1 mark
	void testValueCtor(); // 2 marks
	void testCopyCtor(); // 2 marks
	void testMoveCtor(); // 2 marks
	void testCopyAsg(); // 2 marks
	void testMoveAsg(); // 2 marks

	void testGet();	// 1.5 marks
	void testSet();	// 1.5 marks
	void testOperatorBracketConst(); // 1.5 marks
	void testOperatorBracket(); // 1.5 marks

	void testGetSize(); // 1 mark
	void testPrint(); // 1 mark

	void testPushBack(); // 1.5 marks
	void testPopBack(); // 1.5 marks
	void testPushFront(); // 1.5 marks
	void testPopFront(); // 1.5 marks
	void testResizing(); // 2 marks

	void testOperatorEqual(); // 2 marks for one of these
	void testOperatorUnequal(); // and 1 mark for the other

};

#endif /* BIARRAYTESTER_H_ */
