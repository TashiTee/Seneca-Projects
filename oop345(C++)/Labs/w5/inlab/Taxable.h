/*************************************************************************
// week 5 in lab
// File: Taxable.h
// Version: 1.0
// Date: 02/22/2019
// Author: Tashi Tsering
// Description: a functor (function object) named Taxable that receives a m_val and returns the sum of the m_val with the tax on it
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef TAXABLE_H_
#define TAXABLE_H_

namespace sict {

	class Taxable {
		float tax_rate;
	public:

		Taxable(float tax_rate_) : tax_rate(tax_rate_) {}

		float operator()(float price) {
			return price * (1.00f + tax_rate);
		}
	};

}  // namespace sict

#endif  // TAXABLE_H_
