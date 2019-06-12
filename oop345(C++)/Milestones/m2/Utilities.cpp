/*************************************************************************
// Milestone 2
// File: Utilities.cpp
// Version: 1
// Date: 04/12/2019
// Author: Tashi Tsering
// Description: extracts tokens from a string, which consists of a set of
fields separated by a specified delimiter and determining a field width that
is sufficiently large to accommodate the tokens for a specified field.
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include"Utilities.h"


using namespace std;
namespace sict {

	char Utilities::m_delimeter = '\n';

	Utilities::Utilities() {
		m_width = 1;

	}

	// Extracts the next token in the string starting at the position next_position
	// 

	const string Utilities::extractToken(const string& str, size_t& next_position) {

		size_t record_end = string::npos;
		string extract;
		if (next_position <= str.length()) {
			string temp = str.substr(next_position);
			size_t record_deli = temp.find(m_delimeter);
			try {

				if (record_deli != record_end) {

					extract = temp.substr(0, record_deli);
					next_position += record_deli + 1;
					if (extract.empty()) { throw("Theres no token"); }
				}
				else {
					extract = temp.substr(0, record_deli);
					if (extract.empty()) { throw("Theres no token"); }
					next_position = str.length() + 1;
				}


				if (extract.length() > m_width) { m_width = extract.length(); }

			}
			catch (const char* err) {
				cout << err << endl;
			}

		}


		return extract;
	}

	const char Utilities::getDelimiter() const {

		return m_delimeter;
	}

	size_t Utilities::getFieldWidth() const {

		return m_width;
	}

	void Utilities::setDelimiter(const char deli) {

		m_delimeter = deli;
	}

	void Utilities::setFieldWidth(size_t w) {

		m_width = w;
	}


}