/*************************************************************************
// Milestone 2
// File: ItemSet.h
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: defintions of ItemSet.cpp
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H


#include"Utilities.h"

namespace sict {

	const int serialWidth = 5;
	const int quantityWidth = 3;

	class ItemSet {

		// tokens
		std::string m_name;
		std::size_t m_serial;
		std::size_t m_quantity;
		std::string m_desc;
		static std::size_t m_width;

	public:
		// constructor that extracts 4 tokens from the string
		ItemSet() : m_name{}, m_serial{ 0 }, m_quantity{ 0 }, m_desc{} {};
		ItemSet(const std::string&);
		// returns a reference to the name of the item 
		const std::string& getName() const;
		// returns the serial number of the item
		const unsigned int getSerialNumber() const;
		// returns the remaining number of items in the set
		const unsigned int getQuantity() const;
		// reduces the number of items in stock by one and increases the serial number by one. This operator returns a reference to the current 
		ItemSet& operator--();
		// display 
		void display(std::ostream& os, bool full = true) const;
	};

}

#endif