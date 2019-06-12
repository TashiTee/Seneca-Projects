/**********************************************************
Milestone 3 - Aid Management Application Good class
// Milestone <Milestone #3>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Good.h
**********************************************************/

#ifndef AMA_GOOD_H
#define AMA_GOOD_H

#include "Error.h"

namespace aid
{
	const int MAX_CHAR_SKU = 7;					// Maximum number of characters in a sku (stock keeping unit)
	const int MAX_CHAR_UNIT = 10;				// Maximum number of characters in a sku (stock keeping unit)
	const int MAX_CHAR_NAME = 75;				// Maximum number of characters in the user�s name descriptor for a Good length
	const double TAX_RATE = 0.13;				// The current tax rate

	const int max_sku_length = MAX_CHAR_SKU;
	const int max_name_length = MAX_CHAR_NAME;
	const int max_unit_length = MAX_CHAR_UNIT;

	class Good
	{
	private:
		char mp_Pr_Type;						// A character that indicates the type of the Good � for use in the file record
		char mp_Pr_Sku[MAX_CHAR_SKU + 1];		// A character array that holds the Good�s sku (stock keeping unit) - null char
		char mp_Pr_Unit[MAX_CHAR_UNIT + 1];		// A character array that describes the Good�s units
		char* mp_Address_Pr_Name;				// A pointer that holds the address of a string in dynamic memory containing the name of the Good
		int mp_Quantity_Pr_OnHand;				// An integer that holds the quantity of the Good currently on hand; that is, the number of units currently on hand
		int mp_Quantity_Pr_Needed;				// An integer that holds the quantity of the Good needed; that is, the number of units needed
		double mp_Price_Pr_SingleBeforeTax;		// A double that holds the price of a single unit of the Good before any taxes
		bool mp_Pr_Taxable;						// A bool that identifies the taxable status of the Good; its value is true if the Good is taxable
		Error mp_Err;						// An ErrorState object that holds the error state of the Good object

	protected:
		void name(const char* nameAddress);		// This function receives the address of a C-style null-terminated string that holds the name of the Good
		const char* name() const;				// This query returns the address of the C-style string that holds the name of the Good
		const char* sku() const;				// This query returns the address of the C-style string that holds the sku of the Good
		const char* unit() const;				// This query returns the address of the C-style string that holds the unit of the Good
		bool taxed() const;						// This query returns the taxable status of the Good
		double itemPrice() const;					// This query returns the price of a single item of the Good
		double itemCost() const;					// This query returns the price of a single item of the Good plus any tax that applies to the Good
		void message(const char*);				// This function receives the address of a C-style null-terminated string holding an error message and stores that message in the ErrorState object
		bool isClear() const;					// This query returns true if the ErrorState object is clear; false otherwise
	public:
		Good(char type = 'N');				// This constructor optionally receives a character that identifies the Good type. Default is N

												// Saves the data into the object
		Good(const char* sku, const char* address, const char * unit, int onHand = 0, bool taxable = true, double beforeTax = 0.0, int needed = 0);

		Good(const Good& other);			// This constructor receives an unmodifiable reference to a Good object and copies the object referenced to the current object

		~Good();								// This function deallocates any memory that has been dynamically allocated

												// This operator receives an unmodifiable reference to a Good object and replaces the current object with a copy of the object referenced
		Good& operator=(const Good & other);

		// This query receives a reference to an fstream object and an optional bool and returns a reference to the fstream object
		std::fstream& store(std::fstream& file, bool newLine = true) const;

		std::fstream& load(std::fstream& file); // This modifier receives a reference to an fstream object and returns a reference to that fstream object

												// This query receives a reference to an ostream object and a bool and returns a reference to the ostream object
		std::ostream& write(std::ostream& os, bool linear) const;

		// This modifier receives a reference to an istream object and returns a reference to the istream object
		std::istream& read(std::istream& is);

		// This query receives the address of an unmodifiable C-style null-terminated string and returns true if the string is identical to the sku of the current object
		bool operator==(const char* address) const;

		// This query that returns the total cost of all items of the Good on hand, taxes included
		double total_cost() const;

		// This modifier that receives an integer holding the number of units of the Good that are on hand
		void quantity(int units);

		// This query returns true if the object is in a safe empty state
		bool isEmpty() const;

		// returns the number of units of the Good that are needed
		int qtyNeeded() const;

		// returns the number of units of the Good that are on hand
		int quantity() const;

		// This query receives the address of a C-style null-terminated string holding a Good sku and returns true if the sku of the current object is greater than the string stored at the received address
		bool operator>(const char* address) const;

		// This query receives an unmodifiable reference to a Good object and returns true if the name of the current object is greater than the name of the referenced Good object
		bool operator>(const Good& other) const;

		// This modifier receives an integer identifying the number of units to be added to the Good and returns the updated number of units on hand
		int operator+=(int unitsToBeAdded);

	};
	// This helper receives a reference to an ostream object and an unmodifiable reference to a Good object and returns a reference to the ostream object 
	std::ostream& operator<<(std::ostream& os, const Good& other);

	// This helper receives a reference to an istream object and a reference to a Good object and returns a reference to the istream object
	std::istream& operator>>(std::istream& is, Good& other);

	// This helper receives a reference to a double and an unmodifiable reference to a Good object and returns a double
	double operator+=(double& total, const Good& other);
}

#endif