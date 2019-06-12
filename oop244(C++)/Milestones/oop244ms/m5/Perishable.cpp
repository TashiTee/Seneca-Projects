/**********************************************************
Milestone 5 - Aid Management Application perishable class
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Perishable.cpp
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "Date.h"

using namespace std;

namespace aid {

	// No argument constructor
	// This default constructor passes the file record tag for perishable product ('P')
	// To the base class constructor and seeers 
	Perishable::Perishable() : Good('P')
	{
		er.clear();
	}

	// calls its base class version inserts a comma into the file record and appends the expiry date to the file record.
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Good::store(file, false);
		file << ',';
		file << m_date;
		;
		file << endl;

		return file;
	}

	// calls its base class version passing as an argument, loads the expiry date, extracts a single character from the fstream object.
	std::fstream& Perishable::load(std::fstream& file)
	{
		Good::load(file);
		file >> m_date;
		file.ignore();

		return file;
	}

	// Function does nothing if the current object is an error or safe empty state
	// else it inserts the expiry date into the ostream object if linear is true adds the expiry date.
	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		os.fill(' '); // Require ffor fill the white spaces
		Good::write(os, linear);

		if (isClear() && !isEmpty()) {

			if (linear == true)
			{
				m_date.write(os);
			}
			else
			{
				os << endl;
				os << " Expiry date: ";
				m_date.write(os);
			}
		}
		return os;
	}


	//Function validates it's base class object data and prompts for expire date to store.
	//In a temporary Date object d date object is also an eeror state it will store the appropiate
	//error message. If not in error state, function copy assigns the temp date object instance date object to  
	std::istream& Perishable::read(std::istream& is)
	{
		Date temp;
		Good::read(is);

		if (is.good())
		{
			std::cout << " Expiry date (YYYY/MM/DD): ";
			temp.read(is);

			if (temp.bad() == true)
			{
				is.setstate(std::ios::failbit);

				switch (temp.errCode())
				{
				case CIN_FAILED:
					message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					message("Invalid Day in Date Entry");
					break;
				case PAST_ERROR:
					message("Invalid Expiry in Date Entry");
				}
			}
			else
			{
				m_date = temp;
			}
		}
		return is;
	}

	//Function returns the expiry date for the perishable good.
	const Date& Perishable::expiry() const
	{
		return m_date;
	}
}
