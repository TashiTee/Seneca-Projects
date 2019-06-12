/**********************************************************
Workshop 4 - Constructors in lab
// Workshop <Workshop #4>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Passenger.cpp
**********************************************************/

// TODO: add file header comments here
#include<iostream>
#include<cstring>

// TODO: add your headers here
#include"Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_des[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == nullptr || destination == nullptr) {
			*this = Passenger(); 
		}
		else {
			strncpy(m_name, name, 18);
			strncpy(m_des, destination, 18);
			m_name[18] = '\0';
			m_des[18] = '\0';
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool valid = strlen(m_name) > 0 && strlen(m_des) > 0;
		return !valid;

	}

	// TODO: implement display query here
	void Passenger::display() const {
		if (m_name[0] == '\0' || m_des[0] == '\0') {
			cout << "No passenger!" << endl;
		}
		else {
			cout << m_name << " - " << m_des << endl;
		}	

	}
}


