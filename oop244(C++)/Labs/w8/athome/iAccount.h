/**********************************************************
Workshop 8 - Virtual functions inlab
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: iAccount.h
**********************************************************/

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {
	public:
		// TODO: credit adds amount to the balance
		virtual bool credit(double) = 0;

		// TODO: debit subtracts a amount from the balance
		virtual bool debit(double) = 0;

		// TODO: month end adds month end costs
		virtual void monthEnd() = 0;

		// TODO: display inserts the account information into an ostream
		virtual void display(std::ostream&) const = 0;
		// TODO: declares a public empty virtual destructor
		virtual ~iAccount() {}

	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char* type, double balance);
}
#endif