
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

	class CRA_Account {

		char f_familyName[max_name_length];
		char f_givenName[max_name_length];
		int f_SIN;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif 
