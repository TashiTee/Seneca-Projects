/*************************************************************************
// week 3 athome
// File: LVPair.h
// Version: 1.0
// Date: 02/12/2019
// Author: Tashi Tsering
// Description: class template named LVPair for managing lable value pair
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef LVPAIR_H_
#define LVPAIR_H_

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
		LVPair(const L &label_, const V &value_) : label(label_), value(value_) {}
		virtual void display(std::ostream &out) const {
			out << label << " : " << value << std::endl;
		}
	};


	template<>
	class LVPair<std::string, int> {
	protected:
		std::string label;
		int value;
	public:
		LVPair() : label(), value() {}
		LVPair(const std::string &label_, const int &value_) : label(label_), value(value_) {}
		LVPair(const std::string &label_) : LVPair(label_, 0) {}
		virtual void display(std::ostream &out) const {
			out << label << " : " << value << std::endl;
		}
	};


	template<>
	class LVPair<std::string, std::string> {
	protected:
		std::string label;
		std::string value;
	public:
		LVPair() : label(), value() {}
		LVPair(const std::string &label_, const std::string &value_) : label(label_), value(value_) {}
		LVPair(const std::string &label_) : LVPair(label_, "") {}
		virtual void display(std::ostream &out) const {
			out << label << " : " << value << std::endl;
		}
	};

	template<class L, class V>
	std::ostream &operator<<(std::ostream &out, const LVPair<L, V> &pair) {
		pair.display(out);
		return out;
	}


	template<class L, class V>
	class SummableLVPair : public LVPair<L, V> {
		V init_val;
		static size_t min_field_width;
	public:
		SummableLVPair() : init_val() {}
		SummableLVPair(const L &label_, const V &value_) : LVPair<L, V>(label_, value_), init_val(value_) {
			if (min_field_width < label_.size()) {
				min_field_width = label_.size();
			}
		}
		const V &getInitialValue() {
			return init_val;
		}
		V sum(const L &label_, const V &sum) const {
			return label_ == LVPair<L, V>::label ? init_val + sum : sum;
		}
		void display(std::ostream &out) const override {
			out << std::left << std::setfill(' ') << std::setw(min_field_width);
			LVPair<L, V>::display(out);
		}
	};


	template<class L, class V>
	size_t SummableLVPair<L, V>::min_field_width = 0;
	template<>
	class SummableLVPair<std::string, std::string> : public LVPair<std::string, std::string> {
		std::string init_val;
		static size_t min_field_width;
	public:
		SummableLVPair() : init_val() {}
		SummableLVPair(const std::string &label_, const std::string &value_) : LVPair<std::string, std::string>(label_, value_), init_val(value_) {
			if (min_field_width < label_.size()) {
				min_field_width = label_.size();
			}
		}
		const std::string &getInitialValue() {
			return init_val;
		}
		std::string sum(const std::string &label_, const std::string &sum) const {
			return label_ == LVPair<std::string, std::string>::label ? sum + " " + init_val : sum;
		}
		void display(std::ostream &out) const override {
			out << std::left << std::setfill(' ') << std::setw(min_field_width);
			LVPair<std::string, std::string>::display(out);
		}
	};

	size_t SummableLVPair<std::string, std::string>::min_field_width = 0;

}  // namespace sict
#endif  // LVPAIR_H_