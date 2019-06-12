/**********************************************************
Workshop 8 - Virtual functions at home
// Workshop <Workshop #8>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: ChequingAccount.h
**********************************************************/

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
		double m_Transaction;
		double m_MonthEnd;

	public:
		// TODO: constructor initializes account balance and transaction 
		// If the tax fee received is positive, the function stores the fee
		// If tax fee is negative, the function stores 0.0 as the fee
		ChequingAccount(double initBalance, double transactionFee, double monthEndFee);

		// TODO: credit adds amount to the balance
		// credits the balance by the passed amount, if successful return true
		bool credit(double amtToCredit);

		// TODO: debit subtracts a negative amount from the balance
		// Debits the balance with the amount that was passed, return true if successful
		bool debit(double amtToDebit);

		// TODO: month end
		// Debit the monthly fee from the account balance
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream& os) const;
	};
}
#endif
