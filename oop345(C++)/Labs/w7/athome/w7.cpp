/*************************************************************************
// week 7 at home
// File: w7.cpp
// Version: 1.0
// Date: 04/01/2019
// Author: Tashi Tsering
// Description: main file
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "DataTable.h"
#include "DataTable.h" // this is intentional
using namespace std;
int FW = 8; // field width
int ND = 4; // precision for numbers

// Reports the Statistics for file named pFileName
//
void processFile(const char* pFileName) {

	cout << endl;
	cout << "****************************************" << endl;
	cout << "*** Processing file [" << pFileName << "]" << endl;
	cout << "****************************************" << endl;

	std::ifstream dataFile(pFileName);
	if (!dataFile) {
		cerr << endl << "***Failed to open file " << pFileName << "***" << endl;
		return;
	}

	try {
		sict::DataTable<float> data(dataFile);
		cout << endl;
		data.displayData(cout);
		data.displayStatistics(cout);
	}
	catch (std::string& msg) {
		cout << "ERROR: " << msg << endl;
	}
}

int main(int argc, char** argv) {
#ifndef SICT_DATA_TABLE_H
	cout << "Improper header guard for DataTable.h! Follow the convention "
		<< "SICT_DATA_TABLE_H when defining a header guard.\n";
#endif

	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl;
	if (argc < 2) {
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	for (int i = 1; i < argc; ++i)
		processFile(argv[i]);
}
