/*************************************************************************
// Milestone 1
// File: ItemSet.cpp
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: manages stock inventory of a particular item
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#include"ItemSet.h"

using namespace std;
namespace sict {

	size_t ItemSet::m_width = 0;

	ItemSet::ItemSet(const string& string) {

		Utilities token;
		size_t position = 0;

		if (!string.empty()) {
			m_name = token.extractToken(string, position);

			if (m_width < token.getFieldWidth()) { m_width = token.getFieldWidth() + 1; }

			istringstream serial(token.extractToken(string, position));
			serial >> m_serial;
			istringstream quantity(token.extractToken(string, position));
			quantity >> m_quantity;
			m_desc = token.extractToken(string, position);

		}
	}

	const string& ItemSet::getName() const { 
		
		return m_name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
	
		return m_serial; 
	}

	const unsigned int ItemSet::getQuantity() const { 
	
		return m_quantity;
	}

	ItemSet& ItemSet::operator--() 
	{
		if (m_quantity > 0) {
			m_quantity--;
			m_serial++;
		}
		return *this;

	}

	void ItemSet::display(ostream& os, bool full) const {
		if (full == false) {
			os << setw(m_width) << left << m_name << "[" << setw(serialWidth) << setfill('0') << m_serial << "]" << endl;
		}
		else {
			os << setw(m_width) << left << m_name << "[" << setw(serialWidth) << setfill('0') << m_serial << "]" << " Quantity " << setw(quantityWidth) << setfill(' ') << m_quantity << " Description: " << m_desc << endl;
		}

	}

}

