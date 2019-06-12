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
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {
		char m_name[19];
		char m_des[19];
		int m_year;
		int m_month;
		int m_day;

	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif // !PASSENGER_H