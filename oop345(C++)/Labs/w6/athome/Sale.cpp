/*************************************************************************
// week 6 in lab
// File: Sale.cpp
// Version: 1.0
// Date: 03/22/2019
// Author: Tashi Tsering
// Description: managing a sequence of iProduct objects
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#include "Sale.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "Product.h"

extern int FW;

namespace sict {

	Sale::Sale(const char *filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::ostringstream err_stream;
			err_stream << "Failed to open file: " << filename;
			throw err_stream.str();
		}
		while (file.good()) {
			iProduct *product = readRecord(file);
			if (product != nullptr) {
				products.push_back(product);
			}
		}
	}
	
	void Sale::display(std::ostream &out) const {
		out << "\nProduct No" << std::setw(FW) << "Cost" << ' ' << "Taxable" << std::endl;

		double total = { 0.0 };
		for (auto& i : products)
		{
			out << *i;
			out << std::fixed << std::setprecision(2);
			total += i->price();
			out << std::endl;
		}
		out << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;
	}

}  // namespace sict

