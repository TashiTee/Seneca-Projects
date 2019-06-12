/**********************************************************
Workshop 8 - Virtual functions inlab
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: SavingsAccount.cpp
**********************************************************/

#include <iostream>
#include "SavingsAccount.h"

namespace sict {
	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		interestRate < 0 ? m_Interest = 0 : m_Interest = interestRate;
	}

	void SavingsAccount::monthEnd() {
		double interest = (balance() * m_Interest);
		credit(interest);
	}

	void SavingsAccount::display(std::ostream& os) const {
	
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Account type: Savings" << std::endl;
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << m_Interest * 100 << std::endl;
	}

}