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

#include <fstream>
#include <string>
#include <iomanip>
#include "Sale.h"
#include "Product.h"

extern int FW;

namespace sict
{
	Sale::Sale(const char* filename)
	{
		if (filename != nullptr && filename[0] != '\0')
		{
			std::string buffer;
			size_t count = { 0 };
			std::ifstream fs;
			fs.open(filename);
			if (fs.is_open())
			{
				while (std::getline(fs, buffer))
					count++;
				fs.clear();
				fs.seekg(0, std::ios::beg);
				for (size_t i = 0; i < count; i++)
					products.push_back(readRecord(fs));
				fs.close();
			}
			else
				throw "File cannot be opened";
		}
		else
			throw "File does not exist";
	}

	void Sale::display(std::ostream & out) const
	{
		out << "\nProduct No" << std::setw(FW) << "Cost" << std::endl;
		double total = { 0.0 };
		for (auto& i : products)
		{
			out << *i;
			out << std::fixed << std::setprecision(2);
			total += i->price();
		}
		out << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;
	}
}
