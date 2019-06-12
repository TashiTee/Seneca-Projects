/**********************************************************
Milestone 5 - Aid Management Application perishable class
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Good.h
**********************************************************/

#ifndef AID_GOOD_H
#define AID_GOOD_H

#include <iostream>
#include "iGood.h"
#include "Error.h"

namespace aid
{
	const int MAX_CHAR_SKU = 7;
	const int MAX_CHAR_UNIT = 10;
	const int MAX_CHAR_NAME = 75;
	const double TAX_RATE = 0.13;

	const int max_sku_length = MAX_CHAR_SKU;
	const int max_name_length = MAX_CHAR_NAME;
	const int max_unit_length = MAX_CHAR_UNIT;

	class Good : public iGood
	{
		char m_type;
		char m_sku[MAX_CHAR_SKU];
		char m_unit[MAX_CHAR_UNIT];
		char* m_name;
		int m_qty;
		int m_needed;
		double m_price;
		bool m_taxable;

	protected:
		Error er;
		void name(const char* name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char* errorMessage);
		bool isClear() const;

	public:
		Good(char type = 'N');
		Good(const char* sku, const char* name, const char* unit, int quantity = 0, bool taxable = true, double price = 0.0, int needed = 0);
		Good(const Good& other);
		Good& operator=(const Good& other);
		~Good();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* rhs) const;
		double total_cost() const;
		void quantity(int quantity);
		void price(double price);
		void needed(int needed);
		bool isEmpty() const;
		char type() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* rhs) const;
		bool operator>(const iGood& rhs) const;
		int operator+=(int units);
	};

	std::ostream& operator<<(std::ostream& os, const iGood& other);
	std::istream& operator>>(std::istream& is, iGood& other);
	double operator+=(double& total, const iGood& other);
	iGood* CreateGood();
}

#endif 


