/*************************************************************************
// week 1 at home
// File: String.h
// Version: 1.0
// Date: 01/24/2019
// Author: Tashi Tsering
// Description: defintions of string.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef STRING_H_
#define STRING_H_

#include <iostream>

namespace sict {

	class String {
		char *value;	// C-style null terminated string of any length
	public:
		String(const char *);
		~String();
		void display(std::ostream &) const;
	};

	std::ostream &operator<<(std::ostream &, const String &);

}  

#endif  // !_SICT_STRING_H