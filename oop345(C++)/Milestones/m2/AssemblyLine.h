/*************************************************************************
// Milestone 2
// File: AssemblyLine.h
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: defintions of AssemblyLine.cpp
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_ASSEMBLY_LINE_H
#define SICT_ASSEMBLY_LINE_H

#include <iostream>
#include <vector>
#include "ItemSet.h"
#include "CustomerOrder.h"

namespace sict {
	class AssemblyLine {
		std::vector<ItemSet> inventory;
		std::vector<CustomerOrder>orders;
		const char* fInventory{ nullptr };
		const char* fOrders{ nullptr };
	public:
		AssemblyLine(char* filename[], int nfiles);
		void loadInventory(std::ostream& os);
		void loadOrders(std::ostream& os);
	};
}
#endif