/**********************************************************
Milestone 5 - Aid Management Application perishable class
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Perishable.h
**********************************************************/

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include <iostream>
#include "Good.h"
#include "Date.h"

#endif // !AID_PERISHABLE_H

namespace aid {

	class Perishable : public Good
	{
		//private data member
	private:

		Date m_date;

		//public data member
	public:

		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}


