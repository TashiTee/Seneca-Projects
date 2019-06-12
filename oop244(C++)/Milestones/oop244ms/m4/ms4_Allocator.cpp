/**********************************************************
Milestone 4 - Aid Management Application iGood interface
// Milestone <Milestone #4>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: ms4_Allocator.cpp
**********************************************************/

#include "ms4_MyGood.h"

namespace aid {

	iGood* CreateGood() {
		return new MyGood("Good");
	}
	iGood* CreatePerishable() {
		return new MyGood("Perishable");
	}
}