/**********************************************************
Workshop 5 - Member Operator Overloads in lab
// Workshop <Workshop #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Fraction.h
**********************************************************/


// TODO: header file guard
#ifndef FRACTION_H
#define FRACTION_H


// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		
		// TODO: declare private member functions

	public:
		// TODO: declare public member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		Fraction();
		Fraction(int nu, int de);
		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction& rhs) const;
	
	};
}
#endif // !FRACTION_H
