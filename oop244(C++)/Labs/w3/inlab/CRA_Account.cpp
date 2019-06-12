/**********************************************************
Workshop 3 - Classes and Privacy in lab
// Workshop <Workshop #3>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: CRA_Account.cpp
**********************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		
		if (sin < min_sin || sin > max_sin) {
			f_SIN = 1;
		}
		else {
			strncpy(f_familyName, familyName, max_name_length + 1);
			strncpy(f_givenName, givenName, max_name_length + 1);
			f_SIN = sin;
		}
	}

	bool CRA_Account::isEmpty() const {

		if (f_SIN == 1) {

			return true;
		}
		else 
			return false;
		
	}

	void CRA_Account::display() const {
		if (isEmpty() == true) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << f_familyName << endl;
			cout << "Given Name : " << f_givenName << endl;
			cout << "CRA Account: " << f_SIN << endl;
		}
	}
}