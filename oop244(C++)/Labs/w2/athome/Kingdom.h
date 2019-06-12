/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
/**********************************************************
Workshop 2 - Dynamic Memory At Home
// Workshop <Workshop #2>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: kingdome.h
**********************************************************/
// TODO: header safeguards
// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


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
	void display(const Kingdom Arr[], int j);



}
#endif
