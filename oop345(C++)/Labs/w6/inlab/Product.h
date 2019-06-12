/*************************************************************************
// week 6 in lab
// File: Product.h
// Version: 1.0
// Date: 03/22/2019
// Author: Tashi Tsering
// Description: defintion for product.cpp
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#ifndef _SICT_PRODUCT_H
#define _SICT_PRODUCT_H

#include "iProduct.h"

namespace sict
{
	class Product : public iProduct
	{
		int id;
		double prod_price;
	public:
		Product();
		explicit Product(int, double);
		double price() const override;
		void display(std::ostream& os) const override;
	};

	iProduct* readRecord(std::ifstream& file);
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
}
#endif // !_SICT_PRODUCT_H