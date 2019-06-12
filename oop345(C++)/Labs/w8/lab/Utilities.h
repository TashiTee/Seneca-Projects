/*************************************************************************
// week 8 in lab
// File: Utilities.h
// Version: 1.0
// Date: 04/5/2019
// Author: Tashi Tsering
// Description: header file for utilities.cpp
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include "List.h"
#include "Element.h"

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif