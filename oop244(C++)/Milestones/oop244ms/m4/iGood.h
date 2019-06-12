/**********************************************************
Milestone 4 - Aid Management Application iGood interface
// Milestone <Milestone #4>
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

	
		// newLine specifies if a newline should be inserted after each iGood record
		// Insert the Product records into the file
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;

		// Extract iGood records from the file
		virtual std::fstream& load(std::fstream& file) = 0;

		// The bool argument will specify whether or not the records should be listed on a single line or on separate lines
		// insert the iGood record for the current object into the ostream object
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;

		// extract the iGood record for the current object from the istream object
		virtual std::istream& read(std::istream& is) = 0;

		// return true if the string received is identical to the stock keeping unit of an iGood record
		virtual bool operator==(const char*) const = 0;

		// return the cost of a single unit of an iGood with taxes included
		virtual double total_cost() const = 0;

		// Return the name of the iGood
		virtual const char* name() const = 0;

		// This modifier will receive an integer holding the number of units of an iGood that are currently available. This function will set the number of units available
		virtual void quantity(int) = 0;

		// Return number of units of an iGood needed
		virtual int qtyNeeded() const = 0;

		// Return number of units of iGood currently available
		virtual int quantity() const = 0;

		// Add units received to iGood and return the total
		virtual int operator+=(int) = 0;

		// return true if the current object is greater than the referenced iGood object
		virtual bool operator>(const iGood&) const = 0;

		// virtual destructor on your iGood interface
		virtual ~iGood() {}
	};

	// insert the iGood record for the referenced object into the ostream object
	std::ostream& operator<<(std::ostream&, const iGood&);

	// extract the iGood record for the referenced object from the istream object
	std::istream& operator>>(std::istream&, iGood&);

	// will add the total cost of the iGood object to the double received and return the updated value of the double
	double operator+=(double&, const iGood&);

	// Return the address of a Product object
	iGood* CreateGood();

	// return the address of a Perishable object
	iGood* CreatePerishable();
}

#endif 
