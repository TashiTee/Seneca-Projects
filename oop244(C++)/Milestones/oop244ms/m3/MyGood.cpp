/**********************************************************
Milestone 3 - Aid Management Application Good class
// Milestone <Milestone #3>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: MyGood.cpp
**********************************************************/
#include <iomanip>
#include <fstream>
#include <cstring>
#include "MyGood.h"
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
using namespace std;

namespace aid {
	MyGood::MyGood() : Good("", "", "") {}
	MyGood::MyGood(const char* sku, const char* name, const char* unit, int qty,
		bool isTaxed, double price, int qtyNeeded) :
		Good(sku, name, unit, qty, isTaxed, price, qtyNeeded) {}
	const char* MyGood::sku() const { return Good::sku(); }
	const char* MyGood::name() const { return Good::name(); }
	const char* MyGood::unit() const { return Good::unit(); }
	bool MyGood::taxed() const { return Good::taxed(); }
	double MyGood::price() const { return Good::itemPrice(); }
	double MyGood::cost() const { return Good::itemCost(); }

	Test::Test(const char* file) : filename(file) { }
	Test::Test(const char* file, const char* theSku, const char* theName) :
		Good(theSku, theName, ""), filename(file) { }
	std::fstream& Test::store(std::fstream& file, bool addNewLine) const {
		if (!Good.isEmpty()) {
			file.open(filename, ios::out | ios::app);
			file << Good.sku() << TAB << Good.name() << TAB << Good.unit() << TAB <<
				(Good.taxed() ? 1 : 0) << TAB << Good.price() << TAB << Good.quantity() << TAB <<
				Good.qtyNeeded() << endl;
			file.clear();
			file.close();
		}
		return file;
	}
	std::fstream& Test::load(std::fstream& file) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		char taxed_;
		file.open(filename, ios::in);
		file >> sku_;
		file >> name;
		file >> unit;
		file >> taxed_;
		file >> price_;
		file >> quantity;
		file >> qtyNeeded;
		file.clear();
		file.close();
		Good = MyGood(sku_, name, unit, quantity, taxed_ != 0, price_, qtyNeeded);
		return file;
	}
	std::ostream& Test::write(std::ostream& os, bool linear) const {
		return Good.isEmpty() ? os : (os << Good.sku() << ": " << Good.name() << ", quantity: "
			<< Good.quantity() << ", quantity needed:" << Good.qtyNeeded()
			<< ", Cost: " << fixed << setprecision(2) << Good.cost());
	}
	std::istream& Test::read(std::istream& is) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		char taxed_;
		cout << " Sku: ";
		is >> sku_;
		cout << " Name (no spaces): ";
		is >> name;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> taxed_;
		cout << " Price: ";
		is >> price_;
		cout << " Quantity On hand: ";
		is >> quantity;
		cout << " Quantity Needed: ";
		is >> qtyNeeded;
		Good = MyGood(sku_, name, unit, quantity, taxed_ != 0, price_, qtyNeeded);
		return is;
	}
	int Test::operator+=(int value) {
		Good.quantity(Good += value);
		return Good.quantity();
	}
	bool Test::operator==(const char* sku) const {
		return !std::strcmp(Good.sku(), sku);
	}
	std::ostream& operator<<(std::ostream& os, const Test& test) {
		return test.Good.write(os, true);
	}
	double operator+=(double& d, const Test& test) {
		return d += test.Good.total_cost();
	}
	std::istream& operator>>(std::istream& is, Test& test) {
		return test.Good.read(is);
	}
}
