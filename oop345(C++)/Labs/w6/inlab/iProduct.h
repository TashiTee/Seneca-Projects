/*************************************************************************
// week 6 in lab
// File: iProduct.h
// Version: 1.0
// Date: 03/22/2019
// Author: Tashi Tsering
// Description: holds  data on products for sale
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#ifndef _SICT_IPRODUCT_H
#define _SICT_IPRODUCT_H

#include <iostream>

namespace sict
{
	class iProduct
	{
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& out) const = 0;
		iProduct* readRecord(std::ifstream& filename);
	};

	std::ostream& operator<<(std::ostream& out, const iProduct& p);
}

#endif // !_SICT_IPRODUCT_H