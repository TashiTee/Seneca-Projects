/*************************************************************************
// week 6 in lab
// File: Product.cpp
// Version: 1.0
// Date: 03/22/2019
// Author: Tashi Tsering
// Description: concrete class named Product implements iProduct interface
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Product.h"
// #include "TaxableProduct.h"

extern int FW;
namespace sict {

	/**
	* Product Module
	*/
	Product::Product()
		: id{ 0 }
		,prod_price{ 0.0 }
		{
		}

	Product::Product(int id_, double prod_price_)
		: id{ id_ }
		, prod_price{ prod_price_ }
	{
	}
	
	double Product::price() const
	{
		return prod_price;
	}

	void Product::display(std::ostream & os) const
	{
		os << std::setw(FW) << id << std::setw(FW) << prod_price;
	}

	
	//Taxable Product Module
	
	// 3-argument constructor that creates the object - TaxableProduct contains a Product
	TaxableProduct::TaxableProduct(int id_, double prod_price_, char tax_type_)
		: Product(id_, prod_price_)
		, tax_type(tax_type_ == 'H' ? 0.13 : 0.08)
	{
	}

	// Returns the price with tax (net price) of the product
	double TaxableProduct::price() const
	{
		return Product::price() * (1 + tax_type);
	}


	// Displays the information about the product with tax status
	void TaxableProduct::display(std::ostream & out) const
	{
		Product::display(out);

		if (tax_type == 0.13)
			out << " HST";
		else
			out << " PST";
	}

	
	std::ostream &operator<<(std::ostream &out, const iProduct &rhs) {
		rhs.display(out);
		return out;
	}
	iProduct* readRecord(std::ifstream & file)
	{
		iProduct* product = nullptr;

		std::string line = {};
		int product_number = { 0 };
		double price = { 0 };
		char tax = { '\0' };

		while (std::getline(file, line, '\n'))
		{
			size_t count = std::count(line.begin(), line.end(), ' ');		// count how many spaces in line
			std::stringstream stream(line);
			if (count == 2)
			{
				stream >> product_number >> price >> tax;
				product = new TaxableProduct(product_number, price, tax);
				break;
			}
			else
			{
				stream >> product_number >> price;
				product = new Product(product_number, price);
				break;
			}
		}

		return product;
	}

}  // namespace sict


