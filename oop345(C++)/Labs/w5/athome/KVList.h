/*************************************************************************
// week 5 at home
// File: KVList.h
// Version: 1.0
// Date: 03/06/2019
// Author: Tashi Tsering
// Description: class template named KVList for managing a dynamically allocated list of T objects.
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef KVLIST_H_
#define KVLIST_H_

namespace sict {

	template<class ListType>

	class KVList {

		ListType *m_list;
		size_t m_size, m_count;

	public:
		KVList() : m_list(nullptr), m_size(0), m_count(0) {}
		
		KVList(size_t size) : KVList() {
			m_size = size;
			if (size > 0) {
				m_list = new ListType[size];
			}
			else {
				throw "ERROR: The number of elements received in the constructor is not positive-valued";
			}
		}

		KVList(KVList &&list) {
			m_list = list.m_list;
			m_size = list.m_size;
			m_count = list.m_count;
			list.m_list = nullptr;
			list.m_size = list.m_count = 0;
		}

		~KVList() {
			if (m_list != nullptr) {
				delete[] m_list;
				m_list = nullptr;
				m_size = m_count = 0;
			}
		}

		const ListType &operator[](size_t index) const {
			if (index > m_size)
				throw "ERROR: The index passed to the subscripting operator is out-of-bounds";
			return m_list[index];
		}

		template<typename FUNC>
		void display(std::ostream& out, FUNC f) const {
			for (size_t i = 0; i < m_count; ++i) {
				m_list[i].display(out, f);
			}
		}

		void push_back(const ListType &element) {
			if (m_count < m_size) {
				m_list[m_count++] = element;
			}
		}

		KVList(const KVList &) = delete;
		KVList &operator=(const KVList &) = delete;
		KVList &operator=(KVList &&) = delete;

	};

}  // namespace sict

#endif  // KVLIST_H_
