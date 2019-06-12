/*************************************************************************
// week 1 at home
// File: w1.cpp
// Version: 1.0
// Date: 01/24/2019
// Author: Tashi Tsering
// Description: main file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <iostream>

#include "process.h"

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i];
		std::cout << " ";
		if (i == argc - 1) {
			std::cout << std::endl;
		}
	}
	for (int i = 1; i < argc; ++i) {
		sict::process(argv[i]);
	}
	return 0;
}