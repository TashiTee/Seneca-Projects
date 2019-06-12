/**********************************************************
Milestone 5 - Aid Management Application
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: ms5_Allocator.cpp
**********************************************************/

#include "Good.h"
#include "Perishable.h"

namespace aid {
		// TODO: insert return statement here
	
	// creates an empty good
	//
	iGood* CreateGood() {
		return new Good();
	}

	// creates an empty perishable good
	//
	iGood* CreatePerishable() {
		return new Perishable();
	}
}
