/*************************************************************************
// week 5 in lab
// File: KVPair.h
// Version: 1.0
// Date: 02/22/2019
// Author: Tashi Tsering
// Description: class template named KVPair for managing a single-m_key-m_val pair
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/
#ifndef KVPAIR_H_
#define KVPAIR_H_

#include <iostream>

namespace sict {

	template<class Key, class Value>
	class KVPair {
		Key m_key;
		Value m_val;
	public:
		KVPair() : m_key(), m_val() {}
		KVPair(const Key &kk, const Value &vv) : m_key(kk), m_val(vv) {}
		template<typename FUNC>
		void display(std::ostream &out, FUNC f) const {
			out << std::setfill(' ') << std::setw(11) << std::left << m_key << std::setw(0) << ":" << std::setw(11) << std::right << m_val << std::setw(0) << " " << std::setw(9) << f(m_val) << std::setw(0) << std::endl;
		}
	};

}  // namespace sict

#endif  // KVPAIR_H_

