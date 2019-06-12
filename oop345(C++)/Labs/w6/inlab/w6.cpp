/*************************************************************************
// week 6 in lab
// File: w6.cpp
// Version: 1.0
// Date: 03/22/2019
// Author: Tashi Tsering
// Description: main filename
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#include <iostream>
#include <string>
#include "Sale.h"

int FW{ 10 }; // field width for output

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << argv[0] << ": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	try {
		sict::Sale sale(argv[1]);
		sale.display(std::cout);
	}
	catch (const std::string& msg) {
		std::cout << msg << std::endl;
		return 2;
	}
}

