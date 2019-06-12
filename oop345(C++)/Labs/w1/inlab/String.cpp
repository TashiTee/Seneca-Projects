/*************************************************************************
// week 1 in lab
// File: String.cpp
// Version: 1.0
// Date: 01/21/2019
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
	static int current_item = INITIAL;

	String::String(const char *value_) : value{ '\0' } {
		if (value_ != nullptr && strlen(value_) != 0) {
			strncpy(value, value_, sizeof(value) - 1);
		}
	}
	void String::display(std::ostream &os) const {
		os << value;
	}
	std::ostream &operator<<(std::ostream &lhs, const String &rhs) {
		lhs << current_item++ << ": ";
		rhs.display(lhs);
		return lhs;
	}

}  // namespace sict
