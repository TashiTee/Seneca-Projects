/**********************************************************
Workshop 8 - Virtual functions at home
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Account.cpp
**********************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {

	Account::Account() {
		m_balance = 1;
	}
	// constructor with balance   
	Account::Account(double balance)
	{
		balance >= 0 ? m_balance = balance : m_balance = 1;
	}

	bool Account::credit(double addAmount) {
		if (addAmount > 0) {
			m_balance += addAmount;
			return true;
		}
		else {
			return false;
		}
	}

	bool Account::debit(double deductAmount) {
		if (deductAmount > 0) {
			m_balance -= deductAmount;
			return true;
		}
		else {
			return false;
		}
	}

	double Account::balance() const {
		return m_balance;
	}
}