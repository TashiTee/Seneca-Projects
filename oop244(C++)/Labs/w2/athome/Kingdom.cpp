/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
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
// File: kingdome.cpp
**********************************************************/

// TODO: include the necessary headers
// TODO: include the necessary headers
// TODO: include the necessary headers
#include<iostream>
#include"Kingdom.h"	

using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(Kingdom& k) {
		cout << k.m_name << ", population " << k.m_population << endl;

	}
	void display(const Kingdom Arr[], int j) {
		int totPop = 0;

		for (int i = 0; i < j; i++) {
			totPop += Arr[i].m_population;
		};
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < j; i++) {
			cout << i + 1 << ". " << Arr[i].m_name << ", population " << Arr[i].m_population << endl;
		};
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totPop << endl;
		cout << "------------------------------" << endl;

	}





}