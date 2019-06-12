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
#include <iomanip>
#include "Product.h"

extern int FW;

namespace sict
{
	Product::Product()
		: id{ 0 }
		, prod_price{ 0.0 }
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
	void Product::display(std::ostream & out) const
	{
		out << std::setw(FW) << id << std::setw(FW) << prod_price << std::endl;
	}
	iProduct * readRecord(std::ifstream & filename)
	{
		iProduct* product = nullptr;
		int product_number = { 0 };
		double prod_price_ = { 0 };
		filename >> product_number >> prod_price_;
		product = new Product(product_number, prod_price_);
		return product;
	}
	std::ostream & operator<<(std::ostream & out, const iProduct & rhs)
	{
		rhs.display(out);
		return out;
	}
}