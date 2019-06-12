/*************************************************************************
// week 3 in lab
// File: LVPair.h
// Version: 1.0
// Date: 02/07/2019
// Author: Tashi Tsering
// Description: class template named LVPair for managing a label-value pair
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef LVPAIR_H
#define LVPAIR_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sict {

	template<class L, class V>
	class LVPair {

	protected:
		L label;
		V value;
	public:
		LVPair() : label(), value() {}
		LVPair(const L & label_, const V &value_) : label(label_), value(value_) {}
		void display(std::ostream &out) const {
			out << label << " : " << value << std::endl;
		}
	};
	template<class L, class V>
	std::ostream &operator<<(std::ostream &out, const LVPair<L, V> &pair) {
		pair.display(out);
		return out;
	}
}

#endif // !
