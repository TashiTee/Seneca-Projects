/**********************************************************
Milestone 4 - Aid Management Application iGood interface
// Milestone <Milestone #4>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: ms4_MyGood.h
**********************************************************/ 

#ifndef AID_MY_GOOD_H
#define AID_MY_GOOD_H
#include "iGood.h"
#include "iGood.h"
#include "iGood.h" // Good.h is included three times on purpose.

namespace aid {
  class MyGood : public iGood {
    char text_[10000];
	char sku[4];
	char name_[20];
	int value;
  public:
    MyGood(const char* name);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
	bool operator==(const char*) const;
	double total_cost() const;
	const char* name() const;
	void quantity(int);
	int qtyNeeded() const;
	int quantity() const;
	int operator+=(int);
	bool operator>(const iGood&) const;
  };
}
#endif