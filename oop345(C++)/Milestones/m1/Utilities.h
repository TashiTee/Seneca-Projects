/*************************************************************************
// Milestone 1
// File: Utilities.h
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: defintions of Utilities.cpp
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <thread>

namespace sict {

	class Utilities {
		static char m_delimeter;
		std::size_t m_width;

	public:
		// default constructor
		Utilities();
		// a modifier that receives a reference to an unmodifiable string string and a reference to a position next_position in that string. 
		const std::string extractToken(const std::string&, std::size_t&);
		// returns the delimiter character
		const char getDelimiter() const;
		// returns the field width for the current object
		std::size_t getFieldWidth() const;
		// that set the delimiter character for all object of this class
		static void setDelimiter(const char);
		// set the field width for the current object 
		void setFieldWidth(std::size_t);
	};

}

#endif // !_SICT_UTILITIES_H