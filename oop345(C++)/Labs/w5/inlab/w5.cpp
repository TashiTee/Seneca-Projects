/*************************************************************************
// week 5 in lab
// File: w5.cpp
// Version: 1.0
// Date: 02/22/2019
// Author: Tashi Tsering
// Description: a main file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// check for command line errors
	if (argc != 2) exit(1);

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);

	// process price list file
	KVList<KVPair<std::string, float>> priceList = createList< 
		KVList<KVPair<std::string, float>>, 
		KVPair<std::string, float>, 
		std::string, 
		float>
		(argv[1]);
	std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
	std::cout << "Description:      Price Price+Tax\n";
	priceList.display(std::cout, Taxable(HST));
}