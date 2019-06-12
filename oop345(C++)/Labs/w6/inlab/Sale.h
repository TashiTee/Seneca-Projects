/*************************************************************************
// week 6 in lab
// File: Sale.h
// Version: 1.0
// Date: 03/22/2019
// Author: Tashi Tsering
// Description: definition of sale.h
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#ifndef _SICT_SALE_H
#define _SICT_SALE_H

#include <vector>
#include "Product.h"

namespace sict {

	class Sale {
		std::vector<iProduct*> products;
	public:
		explicit Sale(const char*);
		void display(std::ostream& out) const;
	};
}

#endif // !_SICT_SALE_H