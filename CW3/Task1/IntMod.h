#ifndef __INTMOD_H_
#define __INTMOD_H_

#include <iostream>
using std::ostream;
using std::cout;

// you can assume n is an integer >= 2
template<int n>
class IntMod {

public:

	// Default constructor. Should initialize value to 0
	IntMod() {
		value_ = 0;
	}

	// Value constructor. Accepts any (positive or negative) integer
	// not necessarily within [0..n-1]
	IntMod(int v) {
		value_ = v;
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Returns the value of this IntMod as an integer, in
	// the range 0..n-1
	int toInt() const {
		int returnValue_ = value_;
		if (value_>=0){
			returnValue_ = value_ % n;
		}
		else {
			//negative values
			while(returnValue_<0){
				returnValue_ += n;
			}
		}
		return returnValue_;
	}

	// Overloaded + operator for adding two IntMods.
	// The two operands must be of same type i.e. same value of n in IntMod<n>
	// otherwise would not compile.
	// For technical reasons they are defined inside the class body
	// even though they are friends; see e.g. https://en.cppreference.com/w/cpp/language/friend#Template_friend_operators
	friend IntMod operator+(const IntMod& lhs, const IntMod& rhs) {
		IntMod returnValue_ = lhs.toInt() + rhs.toInt();
		return returnValue_;
	}

	// Overloaded * operator for multiplying two IntMods.
	friend IntMod operator*(const IntMod& lhs, const IntMod& rhs) {
		IntMod returnValue_ = lhs.toInt() * rhs.toInt();
		return returnValue_;
	}

	// Overloaded == operator for comparing two IntMods.
	friend bool operator==(const IntMod& lhs, const IntMod& rhs) {
		bool returnValue_;
		if (lhs.toInt()==rhs.toInt()){
			returnValue_ = true;
		}
		else returnValue_ = false;
		
		return returnValue_;
	}

	// Return the multiplicative inverse of the current number mod n
	// (note that this is a member function).
	// An inverse of a number x, modulo n, is a number y such that
	// x*y mod n == 1.
	// It is sufficient to simply test the above condition
	// for each number in 1,2,...,n-1. You don't need to implement any
	// "better" algorithms.
	// If the inverse does not exist, throw a std::domain_error exception.
	IntMod inverse() {
		IntMod returnValue_;
		for(int x = 1; x < n; x++){
			IntMod<n> a(value_*x);
			if( a.toInt() == 1 ) return x;
		}
		throw std::domain_error ("There is no inverse");
	}

	// Overloaded << operator, printing the IntMod like an integer
	friend ostream& operator<<(ostream& os, const IntMod& p) {
		os << p.toInt();
		return os;
	}

private:
	int value_;
	
};

#endif /* __INTMOD_H_ */
