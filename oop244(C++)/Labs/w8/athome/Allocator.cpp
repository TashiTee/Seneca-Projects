/**********************************************************
Workshop 8 - Virtual functions athome
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Allocator.cpp
**********************************************************/

#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	const double interest = 0.05;
	const double transaction = 0.50;
	const double monthly = 2.00;

	// TODO: Allocator function
	// Receives the type of account to be created and the initial balance in the account
	// Returns the address to the calling function
	// If the initial character of the string is 'S', the function creates a savings account in dynamic memory
	// If the string does not identify a type that is available, the function returns nullptr

	iAccount* CreateAccount(const char* type, double interestRate) {
		iAccount *p = nullptr;

		if (type[0] == 'S') {
			p = new SavingsAccount(interestRate, interest);
		}
		else if (type[0] == 'C') {
			p = new ChequingAccount(interestRate, transaction, monthly);
		}
		return p;
	}
}
