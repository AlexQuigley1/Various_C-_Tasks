#include <iostream>
#include <vector>
using std::ostream;
using std::vector;
using std::cout;

// templated class for a polynomial, with coefficients of type T
// The type T is assumed to have a zero element 0
// Furthermore T is assumed to have implemented:
//   the + operator;
//   the == operator;
//   the << operator.
template<typename T>
class Polynomial {
public:

	// Default constructor. Constructs the polynomial "0"
	Polynomial() {
		//creates variable but leaves empty
	}

	// Value constructor. Constructs a polynomial based on the vector
	// of coefficients, in descending order of exponents.
	// For example, if coef contains {0,6,8,9,4}, then it constructs
	// the polynomial 6x^3 + 8x^2 + 9x + 4
	Polynomial(vector<T> other) {
		poly_ = other;
	}

	// default destructor, shallow copy constructor and copy assignment
	// should be ok

	// Return the degree of the polynomial.
	int degree() const {
		int returnValue_ = 0;

		//count 0s at start of vector
		int zeroCount_ = 0;
		for(int i = 0; i < poly_.size(); i++) {
			if(!(poly_.at(i)==0)){
				zeroCount_ = i;
				break;
			}
			else zeroCount_=poly_.size();
		}

		for (int x = (poly_.size()-1); x>zeroCount_; x--){
				returnValue_++;
			}

		return returnValue_;
	}

	// Return the coefficient of the x^i term. If i is negative or
	// larger than the degree, 0 is returned.
	T getCoef(int i) const {
	Polynomial<T> p_ (poly_);
		if(i<0 || i>p_.degree() || poly_.size()==0)return 0;
		else {
			int count_ = 0;
			for (int x = (poly_.size()-1); x>=0; x--){
				if(count_==i)return poly_.at(x);
				count_++;
			}
		}
	}

	// Addition of two polynomials. This time it is a member function
	Polynomial operator+(const Polynomial& other) const {
		Polynomial<T> temp(poly_);
		vector<T> returnValue_;

		//find same degree and add coefficients together
		//find Polynomial with larger degree
		int a = temp.poly_.size();
		int b = other.poly_.size();
		int maxSize_ = std::max(a,b);

		Polynomial <T> smaller;
		Polynomial <T> larger;
		if(a==maxSize_) {smaller = other; larger = temp;}
		else {smaller = temp; larger = other;}

		int difference = larger.poly_.size()-smaller.poly_.size();

		for (int i=0; i<difference; i++) returnValue_.push_back(larger.poly_.at(i));

		for(int i=0; i<smaller.poly_.size(); i++){
			returnValue_.push_back(larger.poly_.at(i+difference) + smaller.poly_.at(i));
		}
		
		Polynomial<T> return_(returnValue_);
		
		return return_;
	}

	// Print the polynomial, in descending order of coefficients and
	// with the usual "x^..." terms.
	// It is not necessary to print it "pretty".
	// For example, if the polynomial is 2x^4 + x^3 - 5x - 1, it is
	// sufficient to print it as 2x^4 + 1x^3 + 0x^2 + -5x^1 + -1x^0
	// Minor formatting differences will be accepted.
	// If you print it pretty you get up to 5 bonus marks (out of 100
	// for this task). See the testPrintPretty() test case.
	// (This bonus part may not be as easy as it seems...)
	friend ostream& operator<<(ostream& os, const Polynomial<T>& p) {
		for (int x = p.degree(); x>=0; x--){
			T coef_ = p.getCoef(x);

			if(!(coef_==0)){
//				if(coef_>=0){		trying to do pretty print but cant get negatives
				if(coef_==1){	
					if (x==p.degree()) os << "x^" << x;
					else if (x==0) os << " + " << coef_;
					else if (x==1) os << " + " <<"x";
					else os  << " + " << "x^" << x;
				}
				else {
					if (x==p.degree()) os << coef_ << "x^" << x;
					else if (x==0) os << " + " << coef_;
					else if (x==1) os << " + " << coef_ << "x";
					else os  << " + " << coef_ << "x^" << x;
				}
//				}
			}
			else if(coef_==0 && p.degree()==0) os << coef_;
		}
		
		return os;
	}

private:
	vector<T> poly_;

};
