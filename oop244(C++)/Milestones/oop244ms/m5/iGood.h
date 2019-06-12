/**********************************************************
Milestone 5 - Aid Management Application perishable class
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: iGood.h
**********************************************************/

#ifndef AID_I_GOOD_H
#define AID_I_GOOD_H

#include <iostream>
#include <fstream>


namespace aid
{
	class iGood
	{
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;

		virtual bool operator==(const char* str) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iGood&) const = 0;
		virtual ~iGood() {}
	};

	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);
	iGood* CreateGood();
	iGood* CreatePerishable();
}

#endif 
