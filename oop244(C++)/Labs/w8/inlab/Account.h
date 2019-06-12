/**********************************************************
Workshop 8 - Virtual functions inlab
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Account.h
**********************************************************/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {
		double m_balance;

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(); 
		// Receives either a double holding the initial account balance or nothing
		Account(double balance);

		// TODO: credit adds +ve amount to the balance 
		// if positive valued param, add param to m_balance and return true
		// If negative valued, return false
		bool credit(double addAmount);

		// TODO: debit subtracts a amount from the balance
		bool debit(double deductAmount);
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char* type, double balance);
}
#endif