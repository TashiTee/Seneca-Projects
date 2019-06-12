/*************************************************************************
// week 2 in lab
// File: Timekeeper.h
// Version: 1.0
// Date: 02/01/2019
// Author: Tashi Tsering
// Description: defintions of Timekeeper.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <chrono>
#include <iostream>

namespace sict {

	struct Record {
		char *mes;
		char *time_units;
		std::chrono::steady_clock::time_point start_time, end_time;
		std::chrono::steady_clock::duration rec_duration;
	};
	class Timekeeper {
		static constexpr size_t sMaxRecords = 10;
		Record records[sMaxRecords];
		size_t records_sz;

	public:
		Timekeeper();
		~Timekeeper();
		void start();
		void stop();
		void recordEvent(const char *);
		void report(std::ostream &);
	};

}  // namespace sict
#endif