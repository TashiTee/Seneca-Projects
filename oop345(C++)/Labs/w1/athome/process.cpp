/*************************************************************************
// week 1 in lab
// File: process.cpp
// Version: 1.0
// Date: 01/21/2019
// Author: Tashi Tsering
// Description: process implmentation file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <iostream>
#include "String.h"
	
namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}