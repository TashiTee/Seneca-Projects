/*************************************************************************
// week 2 at home
// File: Timekeeper.cpp
// Version: 1.0
// Date: 02/05/2019
// Author: Tashi Tsering
// Description: implementations Timekeeper.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#define _CRT_SECURE_NO_WARNINGS

#include "Timekeeper.h"

#include <iostream>
#include <cstring>

namespace sict {

	Timekeeper::Timekeeper() : records_sz(0) {
		const char *time_units_ = "seconds";
		for (size_t i = 0; i < Timekeeper::sMaxRecords; ++i) {
			records[i].mes = nullptr;
			records[i].time_units = new char[strlen(time_units_) + 1]{ '\0' };
			strcpy(records[i].time_units, time_units_);
		}

	}
	Timekeeper::~Timekeeper() {
		for (size_t i = 0; i < Timekeeper::sMaxRecords; ++i) {
			if (records[i].mes != nullptr) {
				delete[] records[i].mes;
				records[i].mes = nullptr;
			}
			if (records[i].time_units != nullptr) {
				delete[] records[i].time_units;
				records[i].time_units = nullptr;
			}
		}
	}
	void Timekeeper::start() {
		records[records_sz].start_time = std::chrono::steady_clock::now();
	}
	void Timekeeper::stop() {
		records[records_sz].end_time = std::chrono::steady_clock::now();
	}
	void Timekeeper::recordEvent(const char *desc) {
		if (records_sz < sMaxRecords) {
			if (records[records_sz].mes != nullptr) {
				delete[] records[records_sz].mes;
				records[records_sz].mes = nullptr;
			}
			records[records_sz].mes = new char[strlen(desc) + 1]{ '\0' };
			strcpy(records[records_sz].mes, desc);
			std::chrono::duration<long> time_span = std::chrono::duration_cast<std::chrono::duration<long>>(records[records_sz].end_time - records[records_sz].start_time);
			records[records_sz].rec_duration = time_span;
			++records_sz;
		}
	}
	void Timekeeper::report(std::ostream &out) {
		std::cout << std::endl << "Execution Times:" << std::endl;
		for (size_t i = 0; i < records_sz; ++i) {
			Record record = records[i];
			std::cout << record.mes << "\t" << (record.rec_duration.count() / 1000000000) << " " << record.time_units << std::endl;
		}
	}

}  // namespace sict
