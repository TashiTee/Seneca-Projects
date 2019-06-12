// Workshop <Workshop #2>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Kingdom.h

// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H

// TODO: sict namespace
namespace sict {
	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

// TODO: declare the function display(...),
//         also in the sict namespace
	void display(Kingdom& k);
}
#endif
