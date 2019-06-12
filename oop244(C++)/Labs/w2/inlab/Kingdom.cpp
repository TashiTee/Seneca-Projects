// Workshop <Workshop #2>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Kingdom.cpp

// TODO: include the necessary headers
#include<iostream>
#include "Kingdom.h"

// TODO: the sict namespace
using namespace std;
namespace sict {

	// TODO:definition for display(...)
	void display(Kingdom& k) { 

		// KINGDOM_NAME, population POPULATION<ENDL>

		cout << k.m_name << ", population " << k.m_population << endl;
	}
}