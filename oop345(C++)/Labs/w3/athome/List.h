/*************************************************************************
// week 3 at home
// File: List.h
// Version: 1.0
// Date: 02/12/2019
// Author: Tashi Tsering
// Description: class template named List for managing an array of any datatype
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/
#ifndef LIST_H_
#define LIST_H_
namespace sict {

	template<class T, size_t N>
	class List {
		size_t elem_count;
		T *elements;
	public:
		List() : elem_count(0), elements(nullptr) {
			elements = new T[N];
		}
		~List() {
			if (elements != nullptr) {
				delete[] elements;
				elements = nullptr;
			}
			elem_count = 0;
		}
		size_t size() const {
			return elem_count;
		}
		const T &operator[](size_t index) const {
			return elements[index];
		}
		void operator+=(const T &obj) {
			if (elem_count < N) {
				elements[elem_count++] = obj;
			}
		}
	};


	template<class L, class V, size_t N>
	class LVList : public List<SummableLVPair<L, V>, N> {
	public:
		V accumulate(const L &label_) const {
			SummableLVPair<L, V> pair;
			V sum = pair.getInitialValue();
			for (size_t i = 0; i < List<SummableLVPair<L, V>, N>::size(); ++i) {
				sum = ((List<SummableLVPair<L, V>, N>&)*this)[i].sum(label_, sum);
			}
			return sum;
		}
	};

}  // namespace sict
#endif  // List_H_