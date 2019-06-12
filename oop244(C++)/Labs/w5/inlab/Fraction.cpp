/**********************************************************
Workshop 5 - Member Operator Overloads in lab
// Workshop <Workshop #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Fraction.cpp
**********************************************************/

// TODO: insert header files
#include"Fraction.h"
#include<iostream>


using namespace std;
// TODO: continue the namespace


namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int nu, int de) {

		if (nu >= 0 && de > 0) {
			numerator = nu;
			denominator = de;
		}
		else {
			*this = Fraction();
		}
		reduce();
	}

	// TODO: implement the max query
	int Fraction::max() const {

		if (numerator > denominator) {
			return numerator;
		}
		else {
			return denominator;
		}
	}

	// TODO: implement the min query
	int Fraction::min() const {
		if (denominator < numerator) {
			return denominator;
		}
		else {
			return numerator;
		}
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

		int g_cd = gcd();			// give  g_cd the value of gcd from gcd function();
		numerator /= g_cd;			// divide numerator by the gcd
		denominator /= g_cd;		// divide denominator by gcd

	}
	// TODO: implement the display query
	void Fraction::display() const {

		if (isEmpty() == false && denominator == 1) {
			cout << numerator;

		} 
		else if (isEmpty() == true) {
			cout << "no fraction stored";
		}
		else {
			cout << numerator << "/" << denominator; 
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {

		if (numerator == 0 && denominator == 0) {
			return true;
		}
		else {
			return false;
		}
	}

// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction current;
		current = *this;
		Fraction result;

		if (current.isEmpty() == false && rhs.isEmpty() == false) {
			result.numerator = (current.numerator * rhs.denominator) + (current.denominator * rhs.numerator);
			result.denominator = current.denominator*rhs.denominator;

			return result;
		}
		else {
			return Fraction();
		}

	}
}


