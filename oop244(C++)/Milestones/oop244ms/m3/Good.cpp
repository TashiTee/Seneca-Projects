/**********************************************************
Milestone 3 - Aid Management Application Good class
// Milestone <Milestone #3>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Good.cpp
**********************************************************/

// Description: Implementation for Good Module
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <iomanip>
#include "Good.h"
#include "Error.h"
using namespace std;
using namespace aid;

namespace aid
{
	Good::Good(char type)
	{
		mp_Pr_Type = type;
		mp_Pr_Sku[0] = '\0';
		mp_Pr_Unit[0] = '\0';
		mp_Address_Pr_Name = nullptr;
		mp_Quantity_Pr_OnHand = 0;
		mp_Quantity_Pr_Needed = 0;
		mp_Price_Pr_SingleBeforeTax = 0.0;
		mp_Pr_Taxable = false;
	}
	Good::Good(const char *sku, const char *address, const char *unit, int onHand, bool taxable, double beforeTax, int needed)
	{
		name(address);
		strncpy(mp_Pr_Sku, sku, max_sku_length);
		mp_Pr_Sku[max_sku_length] = '\0';

		strncpy(mp_Pr_Unit, unit, max_unit_length);
		mp_Pr_Unit[max_unit_length] = '\0';

		mp_Quantity_Pr_OnHand = onHand;
		mp_Quantity_Pr_Needed = needed;
		mp_Price_Pr_SingleBeforeTax = beforeTax;
		mp_Pr_Taxable = taxable;
	}
	Good::~Good()
	{
		delete[] mp_Address_Pr_Name;
	}
	Good::Good(const Good &other)
	{
		int length = strlen(other.mp_Address_Pr_Name);

		mp_Pr_Type = other.mp_Pr_Type;

		strncpy(mp_Pr_Sku, other.mp_Pr_Sku, max_sku_length);
		mp_Pr_Sku[max_sku_length] = '\0';

		strncpy(mp_Pr_Unit, other.mp_Pr_Unit, max_unit_length);
		mp_Pr_Unit[max_unit_length] = '\0';

		mp_Quantity_Pr_OnHand = other.mp_Quantity_Pr_OnHand;
		mp_Quantity_Pr_Needed = other.mp_Quantity_Pr_Needed;
		mp_Price_Pr_SingleBeforeTax = other.mp_Price_Pr_SingleBeforeTax;
		mp_Pr_Taxable = other.mp_Pr_Taxable;

		if (other.mp_Address_Pr_Name != nullptr)
		{
			mp_Address_Pr_Name = nullptr;
			mp_Address_Pr_Name = new char[length];

			for (int i = 0; i < length; ++i)
			{
				mp_Address_Pr_Name[i] = other.mp_Address_Pr_Name[i];
			}
			mp_Address_Pr_Name[length] = '\0';
		}
		else
		{
			mp_Address_Pr_Name = nullptr;
		}
	}

	void Good::name(const char *nameAddress)
	{
		if (nameAddress != nullptr)
		{
			int length = strlen(nameAddress);

			mp_Address_Pr_Name = new char[length];
			for (int i = 0; i < length; ++i)
			{
				mp_Address_Pr_Name[i] = nameAddress[i];
			}

			mp_Address_Pr_Name[length] = '\0';
		}
	}
	const char *Good::name() const
	{
		return (mp_Address_Pr_Name[0] == '\0') ? nullptr : mp_Address_Pr_Name;
	}
	const char *Good::sku() const
	{
		return mp_Pr_Sku;
	}
	const char *Good::unit() const
	{
		return mp_Pr_Unit;
	}
	bool Good::taxed() const
	{
		return mp_Pr_Taxable;
	}
	double Good::itemPrice() const
	{
		return mp_Price_Pr_SingleBeforeTax;
	}
	double Good::itemCost() const
	{
		return (mp_Pr_Taxable) ? itemPrice() * (TAX_RATE + 1) : itemPrice();
	}
	void Good::message(const char *addressError)
	{
		mp_Err.message(addressError);
	}
	bool Good::isClear() const
	{
		return mp_Err.isClear();
	}
	Good &Good::operator=(const Good &other)
	{
		if (this != &other)
		{
			mp_Pr_Type = other.mp_Pr_Type;

			strncpy(mp_Pr_Sku, other.sku(), max_sku_length);

			strncpy(mp_Pr_Unit, other.unit(), max_unit_length);

			mp_Quantity_Pr_OnHand = other.mp_Quantity_Pr_OnHand;
			mp_Quantity_Pr_Needed = other.mp_Quantity_Pr_Needed;
			mp_Price_Pr_SingleBeforeTax = other.mp_Price_Pr_SingleBeforeTax;
			mp_Pr_Taxable = other.mp_Pr_Taxable;

			delete[] mp_Address_Pr_Name;
			if (other.mp_Address_Pr_Name != nullptr)
			{
				int length = strlen(other.mp_Address_Pr_Name);

				mp_Address_Pr_Name = new char[length];
				for (int i = 0; i < length; ++i)
				{
					mp_Address_Pr_Name[i] = other.mp_Address_Pr_Name[i];
				}
				mp_Address_Pr_Name[length] = '\0';
			}
			else
			{
				mp_Address_Pr_Name = nullptr;
			}
		}

		return *this;
	}

	std::fstream &Good::store(std::fstream &file, bool newLine) const
	{
		file << mp_Pr_Type << ',' << mp_Pr_Sku << ',' << mp_Pr_Unit << ',' << mp_Address_Pr_Name << ',' << mp_Quantity_Pr_OnHand << "," << mp_Pr_Taxable << "," << mp_Price_Pr_SingleBeforeTax << "," << mp_Quantity_Pr_Needed;
		if (newLine)
			file << endl;
		return file;
	}
	std::fstream &Good::load(std::fstream &file)
	{
		Good temp;

		temp.mp_Address_Pr_Name = new char[MAX_CHAR_NAME + 1];

		if (file.is_open())
		{
			file >> temp.mp_Pr_Type >> temp.mp_Pr_Sku >> temp.mp_Pr_Unit >> temp.mp_Address_Pr_Name >> temp.mp_Quantity_Pr_OnHand >> temp.mp_Pr_Taxable >> temp.mp_Price_Pr_SingleBeforeTax >> temp.mp_Quantity_Pr_Needed;
			*this = temp;
		}

		delete[] temp.mp_Address_Pr_Name;
		temp.mp_Address_Pr_Name = nullptr;

		return file;
	}
	std::ostream &Good::write(std::ostream &os, bool linear) const
	{
		// inserts the data fields for the current object into the ostream object in the following order and separates them by a vertical bar character (�|�)
		// If the bool parameter is true, the output is on a single line with the field widths as shown below in parentheses
		if (linear)
		{

			os << setw(MAX_CHAR_SKU) << left << mp_Pr_Sku << '|'
				<< setw(20) << left << mp_Address_Pr_Name << '|'
				<< setw(7) << right << fixed << setprecision(2) << itemCost() << '|'
				<< setw(4) << right << mp_Quantity_Pr_OnHand << '|'
				<< setw(10) << left << mp_Pr_Unit << '|'
				<< setw(4) << right << mp_Quantity_Pr_Needed << '|';
		}
		else
		{
			os << "Sku: " << mp_Pr_Sku << "|" << endl
				<< "Name: " << mp_Address_Pr_Name << "|" << endl
				<< "Price: " << mp_Price_Pr_SingleBeforeTax << "|" << endl;
			if (mp_Pr_Taxable)
			{
				os << "Price after tax: " << itemCost() << "|" << endl;
			}
			else
			{
				os << "N/A"
					<< "|" << endl;
			}

			os << "Quantity On hand: " << mp_Quantity_Pr_OnHand << "|" << endl
				<< "Quantity needeed: " << mp_Quantity_Pr_Needed << "|" << endl;
		}
		return os;
	}
	std::istream &Good::read(std::istream &is)
	{
		char sku[MAX_CHAR_SKU + 1];
		char *address = new char[MAX_CHAR_NAME + 1];
		char unit[MAX_CHAR_UNIT + 1];
		int onHand;
		int needed;
		double beforeTax;
		char tax;
		bool taxable;
		Error error;

		cout << " Sku: ";
		is >> sku;

		cout << " Name (no spaces): ";
		is >> address;

		cout << " Unit: ";
		is >> unit;

		cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'Y' || tax == 'y')
		{
			taxable = true;
		}
		else if (tax == 'N' || tax == 'n')
		{
			taxable = false;
		}
		else
		{
			is.setstate(std::ios::failbit);
			error.message("Only(Y)es or (N)o are acceptable");
		}

		if (!is.fail())
		{
			cout << " Price: ";
			is >> beforeTax;
			if (is.fail())
				error.message("Invalid Price Entry");
		}

		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> onHand;
			if (is.fail())
				error.message("Invalid Quantity Entry");
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> needed;
			if (is.fail())
				error.message("Invalid Quantity Needed Entry");
		}

		// Check if there are no error messages - If the istream object has accepted all input successfully
		// stores the input values accepted in a temporary object and copy assigns it to the current object
		if (!is.fail())
		{
			Good temp = Good(sku, address, unit, onHand, taxable, beforeTax, needed);
			*this = temp;
		}

		delete[] address;
		address = nullptr;
		return is;
	}

	// Checks if the parameter == the sku of the current object
	bool Good::operator==(const char *address) const
	{
		return strcmp(address, this->mp_Pr_Sku) == 0;
	}
	double Good::total_cost() const
	{
		double taxed = mp_Price_Pr_SingleBeforeTax * TAX_RATE;
		double withTax = mp_Price_Pr_SingleBeforeTax + taxed;

		return static_cast<double>(mp_Quantity_Pr_OnHand * withTax);
	}
	void Good::quantity(int units)
	{
		mp_Quantity_Pr_OnHand = units;
	}
	bool Good::isEmpty() const
	{
		return (mp_Address_Pr_Name == nullptr) ? true : false;
	}
	int Good::qtyNeeded() const
	{
		return mp_Quantity_Pr_Needed;
	}
	int Good::quantity() const
	{
		return mp_Quantity_Pr_OnHand;
	}
	bool Good::operator>(const char *address) const
	{
		return (strcmp(mp_Pr_Sku, address) > 0) ? true : false;
	}
	bool Good::operator>(const Good &other) const
	{
		return (strcmp(mp_Address_Pr_Name, other.mp_Address_Pr_Name) > 0) ? true : false;
	}
	int Good::operator+=(int unitsToBeAdded)
	{
		if (unitsToBeAdded > 0)
		{
			mp_Quantity_Pr_OnHand += unitsToBeAdded;
			return mp_Quantity_Pr_OnHand;
		}
		else
			return mp_Quantity_Pr_OnHand;
	}
	std::ostream &operator<<(std::ostream &os, const Good &other)
	{
		return other.write(os, true);
	}
	std::istream &operator>>(std::istream &is, Good &other)
	{
		other.read(is);
		return is;
	}
	double operator+=(double &total, const Good &other)
	{
		return total + other.total_cost();
	}
}