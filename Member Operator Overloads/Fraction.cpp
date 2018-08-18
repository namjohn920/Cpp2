/*HyunKyu Nam
141031161
hnam7@myseneca.ca*/


// TODO: insert header files
#include"Fraction.h"
#include <iostream>
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		num = 0;
		deno = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int a, int b) {

		if (a >= 0 && b > 0) {
			num = a;
			deno = b;
			
		}
		else {
			num = 0;
			deno = 0;
		}

		reduce();

	}


	// TODO: implement the max query
	int Fraction::max() const {
		int a = num > deno ? num : deno;

		return a;

	}

	// TODO: implement the min query
	int Fraction::min() const {
		int a = num < deno ? num : deno;

		return a;

	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int a = gcd();
		
		num = num / a;
		deno = deno / a;	

	}

	// TODO: implement the display query
	void Fraction::display() const {
		

		if (num >= 0 && deno > 1) {
			cout << num << "/" << deno;

		}
		else if (num >= 0 && deno == 1) {
			cout << num;
		}
		else cout << "no fraction stored";


	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {

		if (num == 0 && deno == 0) return true;
		else return false;

	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& a) const {
		
		if (this->isEmpty() && !a.isEmpty()) {

			return *this;

		}
		else if (!this->isEmpty() && a.isEmpty()){

			return a;
			

		}
		else if (this->isEmpty() && a.isEmpty()) return a;

		else {

			int deno = this->deno * a.deno;

			int num = (this->num * a.deno) + (a.num * this->deno);

			return Fraction(num, deno);
			
		}

	}

	Fraction Fraction::operator* (const Fraction& b) const {
		
		if (this->isEmpty() && !b.isEmpty()) {

			return *this;

		}
		else if (!this->isEmpty() && b.isEmpty()) {

			return b;


		}else if (this->isEmpty() && b.isEmpty()) return b;
		else {

			int deno = this->deno * b.deno;

			int num = this->num * b.num * this->deno;

			return Fraction(num, deno);

		}

	};


	bool Fraction::operator== (const Fraction& c) const {
		
		if (!this->isEmpty() && !c.isEmpty() && (this->num / this->deno) == (c.num) / (c.deno)) {

			return true;
		}
		else return false;
			
	}


	bool Fraction::operator!= (const Fraction& d) const {

		if (!this->isEmpty() && !d.isEmpty() && (this->num / this->deno) != (d.num) / (d.deno)) {

			return true;
		}
		else return false;

	}

	/*If either operand is in a safe empty state, 
	your function stores a safe empty Fraction object in the current object 
	and returns a reference to the current object.*/

	Fraction Fraction::operator+= (const Fraction& e) {

		if (this->isEmpty() && !e.isEmpty()) {

			return *this;

		}
		else if (!this->isEmpty() && e.isEmpty()) {

			return e;


		}
		else if (this->isEmpty() && e.isEmpty()) return e;

		else {

			int deno = this->deno * e.deno;

			int num = (this->num * e.deno) + (e.num * this->deno);

			this->deno = deno;
			this->num = num;

			this->reduce();

			return Fraction(num, deno);

		}
		
		

			}


}