/*************************************************************************
// week 2 in lab
// File: Text.h
// Version: 1.0
// Date: 02/01/2019
// Author: Tashi Tsering
// Description: defintions of text.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <string>

namespace sict {

	class Text {
		std::string *strings;
		size_t strings_size;
	public:
		Text();
		Text(const char *);
		Text(const Text &);
		~Text();
		Text &operator=(const Text &);
		size_t size() const;
	};

}  // namespace sict
#endif

