/**********************************************************
Milestone 5 - Aid Management Application perishable class
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Date.cpp
**********************************************************/

#include <iostream>
#include <ostream>
#include <iomanip>
#include "Date.h"

using namespace std;
using namespace aid;


#define NO_ERROR   0  
#define CIN_FAILED 1  
#define DAY_ERROR  2  
#define MON_ERROR  3  
#define YEAR_ERROR 4  
#define PAST_ERROR 5  

namespace aid {

	// number of days in month mon and year year
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode)
	{
		this->errorState = errorCode;
	}

	bool Date::is_empty() const
	{
		if (year == 0 && month == 0 && days == 0)
		{
			return true;
		}
		return false;
	}

	Date::Date()
	{
		this->year = 0;
		this->month = 0;
		this->days = 0;
		this->errorState = NO_ERROR;
		this->comparator = 0;
	}

	Date::Date(int year, int month, int day)
	{
		if (year < min_year || year > max_year) {
			this->errCode(YEAR_ERROR);
		}
		else if (month < 1 || month > 12) {
			this->errCode(MON_ERROR);
		}
		else if (day < 1 || day > this->mdays(month, year)) {
			this->errCode(DAY_ERROR);
		}
		else if (year * 372 + month * this->mdays(month, year) + day < min_date) {
			this->errCode(PAST_ERROR);
		}
		else {
			this->year = year;
			this->month = month;
			this->days = day;
			this->errCode(NO_ERROR);
			this->comparator = year * 372 + month * this->mdays(month, year) + day;

		}

		if (this->errorState != NO_ERROR) {
			this->year = 0;
			this->month = 0;
			this->days = 0;
			this->comparator = 0;
		}

	}

	int Date::errCode() const
	{
		return this->errorState;
	}

	bool Date::bad() const
	{
		if (this->errorState != NO_ERROR) {
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Date::operator==(const Date & rhs) const
	{
		if (!this->is_empty() && !rhs.is_empty())
		{
			return this->year == rhs.year && this->month == rhs.month && this->days == rhs.days;
		}
		else
		{
			return false;
		}

	}

	bool Date::operator!=(const Date & rhs) const
	{
		if (!this->is_empty() && !rhs.is_empty())
		{
			return this->year != rhs.year || this->month != rhs.month || this->days != rhs.days;
		}
		else
		{
			return false;
		}


	}

	bool Date::operator<(const Date & rhs) const
	{

		if (!this->is_empty() && !rhs.is_empty())
		{
			return this->year < rhs.year || this->month < rhs.month || this->days < rhs.days;
		}
		else
		{
			return false;
		}

	}

	bool Date::operator>(const Date & rhs) const
	{
		if (!this->is_empty() && !rhs.is_empty())
		{
			return ((this->year > rhs.year) || (this->month || rhs.month)) && (this->days || rhs.days);
		}
		else
		{
			return false;
		}

	}

	bool Date::operator<=(const Date & rhs) const
	{
		if (!this->is_empty() && !rhs.is_empty())
		{
			return this->year <= rhs.year && this->month <= rhs.month && this->days <= rhs.days;
		}
		else
		{
			return false;
		}

	}

	bool Date::operator>=(const Date & rhs) const
	{
		if (!this->is_empty() && !rhs.is_empty())
		{
			return this->year >= rhs.year && this->month >= rhs.month && this->days >= rhs.days;
		}
		else
		{
			return false;
		}

	}

	std::istream& Date::read(std::istream & istr)
	{
		// TODO: insert return statement here
		char dash;
		int year, month, day;
		istr.clear();
		istr >> year >> dash >> month >> dash >> day;

		if (istr.fail())
		{
			errCode(CIN_FAILED);
			return istr;
		}
		else {
			*this = Date(year, month, day);
		}
		return istr;
	}

	std::ostream& Date::write(std::ostream & ostr) const
	{

		ostr << this->year << "/";
		ostr.fill('0');
		ostr.width(2);
		ostr << this->month << "/";
		ostr.width(2);
		ostr << this->days;

		return ostr;
	}

	std::ostream & operator<<(std::ostream& ostr, const Date& writeDate)
	{

		writeDate.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& readDate)
	{
		readDate.read(istr);
		return istr;
	}
}

