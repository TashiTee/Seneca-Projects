/*************************************************************************
// week 1 at home
// File: String.cpp
// Version: 1.0
// Date: 01/24/2019
// Author: Tashi Tsering
// Description: implemenation file that has constructor, display() and a helper non-friend operator
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

#include "String.h"

namespace sict {

	static constexpr int INITIAL = 3;
	static int newIntial = INITIAL;

	// create an object from the passed 'string' parameter

	String::String(const char *value_) : value(nullptr) {

		if (value_ != nullptr && strlen(value_) != 0) {
			value = new char[strlen(value_)]{ '\0' };
			strncpy(value, value_, strlen(value_));
		}
		else {
			value = new char[1]{ '\0' };
		}
	}
	// String destroyer delete the allocated value when the class is destroyed
	String::~String() {
		if (value != nullptr) {
			delete[] value;
			value = nullptr;
		}
	}
		void String::display(std::ostream &os) const {
			os << value;
		}
		std::ostream &operator<<(std::ostream &os, const String &s) {
			os << newIntial++ << ": ";
			s.display(os);
			return os;
		}

	} // namespace sict
