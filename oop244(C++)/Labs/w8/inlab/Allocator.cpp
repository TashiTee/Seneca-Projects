/**********************************************************
Workshop 8 - Virtual functions inlab
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Allocator.cpp
**********************************************************/

#include "SavingsAccount.h" 
#include "iAccount.h" 

namespace sict {

	// define interest rate
	const double interest = 0.05;

	// TODO: Allocator function
	// Receives the type of account to be created and the initial balance in the account
	// Returns the address to the calling function
	// If the initial character of the string is 'S', the function creates a savings account in dynamic memory
	// If the string does not identify a type that is available, the function returns nullptr
	iAccount* CreateAccount(const char* type, double interestRate) {
		iAccount *p = nullptr;

		if (type[0] == 'S') p = new SavingsAccount(interestRate, interest);
		return p;
	}
}