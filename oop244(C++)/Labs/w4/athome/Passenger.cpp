/**********************************************************
Workshop 4 - Constructors at home
// Workshop <Workshop #4>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Passenger.cpp
**********************************************************/


// TODO: add file header comments here
#include<iostream>
#include<cstring>
#include<iomanip>
// TODO: add your headers here
#include"Passenger.h"
using namespace std;


// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_des[0] = '\0';
		m_year = 0;
		m_month = 0;
		m_day = 0;
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

			m_year = 2018;
			m_month = 10;
			m_day = 1;
		}
	}
	//implement constructer with 5 parameters
	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {
		if (name == nullptr || name[0] == '\0' || destination == nullptr || destination[0] == '\0' || year > 2020 || year < 2018 || month > 12 || month < 1
			|| day > 31 || day < 1) {
			*this = Passenger();
		}
		else {
			strncpy(m_name, name, 18);
			strncpy(m_des, destination, 18);
			m_name[18] = '\0';
			m_des[18] = '\0';

			m_year = year;
			m_month = month;
			m_day = day;
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (m_name[0] == '\0' && m_des[0] == '\0' && m_year == 0 && m_month == 0 && m_day == 0)
			return true;
		else
			return false;
	}
	// TODO: implement display query here
	void Passenger::display()const {
		if (isEmpty()) {
			cout << "No passenger!" << endl;

		}
		else {

			cout << m_name << " - " << m_des << " on " << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << setfill('0') << m_day << endl;
		}
	}
	//querry that returns the address of the name of the passenger
	const char* Passenger::name() const {
		if (isEmpty() == false)
			return m_name;

		else
			return nullptr;
	}

	// a querry that can see which passenger can travel with each other
	bool Passenger::canTravelWith(const Passenger& pass) const {
		bool day = (*this).m_day == pass.m_day;
		bool month = (*this).m_month == pass.m_month;
		bool year = (*this).m_year == pass.m_year;

		bool flag = day && month && year;

		return flag;

	}
}


