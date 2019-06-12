/*************************************************************************
// Milestone 1
// File: project.cpp
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: main file
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <iostream>
#include "Utilities.h"
#include "AssemblyLine.h"
//#define OUTPUT_TO_FILE
using namespace sict;

int main(int argc, char *argv[])
{
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << '\n' << std::endl;

	Utilities::setDelimiter('|');

#ifdef OUTPUT_TO_FILE
	std::ofstream os("Output.txt");
	if (!ofs) {
		std::cerr << "ERROR:  Failed to create output.txt file";
		exit(1);
	}
#else
	std::ostream& os = std::cout;
#endif

	try {
		AssemblyLine a(&argv[1], argc - 1);
		if (argc == 2) {
			os << "Inventory Assembly\n";
			os << "==================\n";
			os << std::endl;
			a.loadInventory(os);
			os << "\nInventory Assembly Complete\n";
		}
		else {
			os << "Customer Order Assembly\n";
			os << "=======================\n";
			os << std::endl;
			a.loadOrders(os);
			os << "\nCustomer Order Assembly Complete\n";
		}
	}
	catch (const std::string& str) {
		std::cerr << str << std::endl;
	}

#ifdef OUTPUT_TO_FILE
	os.close();
#endif

	return 0;
}
