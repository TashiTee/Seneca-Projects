/*************************************************************************
// week 7 in lab
// File: DataTable.h
// Version: 1.0
// Date: 03/28/2019
// Author: Tashi Tsering
// Description: holds and process statistical data
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>


// External variables coming from w7.cpp

extern int FW;
extern int ND;

namespace sict {


	template<class T>
	class DataTable {
		std::vector<std::pair<T, T>> m_data;
	private:
		
		// private method that calculates the mean of all the Y coordinates

		T mean() const {
			// T total = sum("second");
			T total = sum();
			return total / m_data.size();
		}

		/**
		* Private method that calculates the sum of the chosen coordinates (first, second)
		* by using the STL algorithm: accumulate(begin, end, initialValue, [](currentValue with init, currentValueInVector))
		*/
		// T sum(std::string& pos) {
		T sum() const {
			T total = { 0 };
			total += std::accumulate(m_data.begin(), m_data.end(), static_cast<T>(0), [](auto& a, auto& b) { return a + b.second; });;
			return total;
		}

		/**
		* Private method that returns all the y coordinates in a vector by using a range-based for loop
		*/
		std::vector<T> y_collection() const {
			std::vector<T> y;

			for (auto& i : m_data) {
				y.push_back(std::get<1>(i));
			}

			return y;
		}
		/*
		* Private method that calculates the sample standard deviation
		* To calculate the sigma:
		*/ 
		T sigma() const {
			T total = { 0 };
			auto y = y_collection();

			std::for_each(y.begin(), y.end(), [&](T& n) {
				total += std::pow(n - mean(), 2);
			});

			return std::sqrt(total / (y.size() - 1));
		}
	public:

		/**
		* One-arg constructor that reads every record from the file, data is stored in a pair then stored in an index within vector
		*/
		explicit DataTable(std::ifstream& file) {
			bool keepReading = true;
			if (file) {
				T x = { 0 };
				T y = { 0 };
				do {
					if (file >> x >> y)
						m_data.push_back(std::make_pair(x, y));
					else
						keepReading = false;
				} while (keepReading);
			}
		}

		/**
		* Query function that displays the x-y data 
		* This can be done by utilizing the FW and ND provided from the main module
		* The method iterates element by element through the vector displaying one pair at a time.
		* To access first element from a pair: std::get<0>(pair_identifer)
		*/

		void displayData(std::ostream& os) {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

			for (const auto& i : m_data)
				os << std::fixed << std::setprecision(ND) << std::setw(FW) << std::right << std::get<0>(i) << std::setprecision(ND) << std::setw(FW) << std::get<1>(i) << std::endl;
		}

		/**
		* Query that displays the statistics for the current object in the following format:
		* y mean    = 11.0000
		* y sigma   =  2.5820
		*/
		void displayStatistics(std::ostream& os) {
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y mean    =  " << mean() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y sigma   =   " << sigma() << std::endl;
		}
	};
}
#endif