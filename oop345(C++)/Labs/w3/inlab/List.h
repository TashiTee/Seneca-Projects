/*************************************************************************
// week 3 in lab
// File: List.h
// Version: 1.0
// Date: 02/07/2019
// Author: Tashi Tsering
// Description: class template named List for managing an array of any datatype
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>


namespace sict {

	template<class T, size_t N>
	class List {
		size_t element_count;
		T *elements;

	public:
		List() : element_count(0), elements(nullptr) {
			elements = new T[N];
		}

		size_t size() const {
			return element_count;
		}
		const T &operator[](size_t index) const {
			return elements[index];
		}
		void operator+=(const T &obj) {
			if (element_count < N) {
				elements[element_count++] = obj;
			}
		}
	};
}


#endif