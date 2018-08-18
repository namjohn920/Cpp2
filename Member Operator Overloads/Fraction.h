/*HyunKyu Nam
141031161
hnam7@myseneca.ca*/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H



// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
	private:
		// TODO: declare instance variables 
		int num;
		int deno;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// TODO: declare public member functions
		void display() const;
		bool isEmpty() const;
		Fraction();
		Fraction(int a, int b);

		// TODO: declare the + operator overload
		Fraction operator+ (const Fraction& a) const;
		Fraction operator* (const Fraction& b) const;
		bool operator== (const Fraction& c) const; 
		bool operator!= (const Fraction& d) const; 
		Fraction operator+= (const Fraction& e); 
	};
}

#endif 