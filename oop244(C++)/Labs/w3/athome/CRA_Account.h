/**********************************************************
Workshop 3 - Classes and Privacy in lab
// Workshop <Workshop #3>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: CRA_Account.h
**********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H



namespace sict {

	const int max_name_length = 41;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {

		char m_familyName[max_name_length];
		char m_givenName[max_name_length];
		int m_SIN;
		int m_yearOfReturn[max_yrs];
		double m_balance[max_yrs];
		int m_noYears;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int years, double balance);
	};


}
#endif 
