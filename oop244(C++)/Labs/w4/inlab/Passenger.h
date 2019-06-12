/**********************************************************
Workshop 4 - Constructors in lab
// Workshop <Workshop #4>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Passenger.h
**********************************************************/

// TODO: add file header comments here
// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char m_name[19];
		char m_des[19];

	public:
		Passenger(); // sets the passanger object to a safe empty state
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;

	};
}
#endif