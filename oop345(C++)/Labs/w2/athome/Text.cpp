/*************************************************************************
// week 2 at home
// File: Text.cpp
// Version: 1.0
// Date: 02/05/2019
// Author: Tashi Tsering
// Description: implementations of Text.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include "Text.h"
#include <fstream>
#include <iostream>
#include <string>

namespace sict {

	Text::Text() : strings(nullptr), strings_size(0) {}
	Text::Text(const char *filename) : Text() {
		std::ifstream file(filename);
		while (file.good()) {
			std::string line;
			std::getline(file, line);
			++strings_size;
		}
		--strings_size;
		strings = new std::string[strings_size];
		file = std::ifstream(filename);
		size_t string_count = 0;
		while (file.good() && string_count < strings_size - 1) {
			std::string line;
			std::getline(file, line);
			strings[string_count++] = line;
		}
	}
	Text::Text(const Text &src) {
		strings = new std::string[src.strings_size];
		for (size_t i = 0; i < src.strings_size; ++i) {
			strings[i] = src.strings[i];
		}
		strings_size = src.strings_size;
	}
	Text::~Text() {
		if (strings != nullptr) {
			delete[] strings;
			strings = nullptr;
			strings_size = 0;
		}
	}
	Text &Text::operator=(const Text &src) {
		if (this != &src) {
			strings = new std::string[src.strings_size];
			for (size_t i = 0; i < src.strings_size; ++i) {
				strings[i] = src.strings[i];
			}
			strings_size = src.strings_size;
		}
		return *this;
	}
	size_t Text::size() const {
		return strings_size;
	}

}  // namespace sict
