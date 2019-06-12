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
		int sumeven = 0;
		int sumodd = 0;
		int check = 0;
		int checkMultipleTen = 0;
		bool valid = false;

		for (int i = 1; i < 9; ++i)
		{
			//cycle through int starting from the second last
			//acheived this by initializing i to 1
			check = (sin / (int)pow(10, i) % 10);
			//if index modeulos two is not equal to zero
			//example, when first index is accessed, second last digit of int
			//i = 1 equals index 8
			if (i % 2 != 0)
			{
				//adding first set of alternates to themselves
				check *= 2;
				//if first set of alternates are higher then 9
				if (check > 9)
				{
					//seperate them each into one
					//example 18 would be 1+8
					check = (int)((check / 10) % 10) + (int)(check % 10);
				}
				//add digits
				sumeven += check;
			}
			else
			{
				//adding second alternates
				sumodd += check;
			}

		}
		//total of both alternates
		check = sumodd + sumeven;
		//rounding total to nearest multiple of 10
		if (((int)(check % 10)) > 0 || ((int)(check % 10)) <= 9)
		{
			checkMultipleTen = (((int)check / 10) * 10) + 10;
		}

		//validating the check digit of sin with remainder of checkMultipleTen and check
		if ((checkMultipleTen - check) == sin % 10)
		{
			valid = true;
		}



		if ((sin < min_sin || sin > max_sin) || valid == false) {
			m_SIN = 0;
			m_familyName[0] = '\0';
			m_givenName[0] = '\0';
		}
		else {

			strncpy(m_familyName, familyName, max_name_length);
			strncpy(m_givenName, givenName, max_name_length);
			m_SIN = sin;
			m_noYears = 0;
			for (int i = 0; i > max_name_length; ++i)
			{
				if (m_familyName[i] > max_name_length)
				{
					m_familyName[i - 1] = '\0';
				}
			}

		}
	}

	bool CRA_Account::isEmpty() const {
		if (m_SIN < min_sin || m_SIN > max_sin || m_familyName[0] == '\0' || m_givenName[0] == '\0') {

			return true;
		}
		else {

			return false;
		}

	}
	void CRA_Account::display() const {
		if (isEmpty() == true) {
			cout << "Account object is empty!" << endl;
		}
		else {

			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_SIN << endl;
			for (int i = 0; i < max_yrs; ++i)
			{
				if (m_balance[i] > 2)
				{

					cout << "Year (" << m_yearOfReturn[i] << ") balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < -2)
				{

					cout << "Year (" << m_yearOfReturn[i] << ") refund due: ";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << m_balance[i] * -1 << endl;
					cout.unsetf(ios::fixed);
				}
				else
				{

					cout << "Year (" << m_yearOfReturn[i] << ") No balance owing or refund due!" << endl;
				}
			}

		}

	}
	void CRA_Account::set(int years, double balance) {



		if (isEmpty() == false && m_SIN != 0)
		{


			m_yearOfReturn[m_noYears] = years;
			m_balance[m_noYears] = balance;
			++m_noYears;
		}
		else {
			//exit
		}

	}
}