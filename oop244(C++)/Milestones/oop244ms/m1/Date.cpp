/**********************************************************
Milestone 1 - Aid Management Application Date Module
// Milestone <Milestone #1>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Date.cpp
**********************************************************/
#include <fstream>
#include <cstring>
#include "Date.h"
#include <iomanip> 

namespace aid {

	//provided function
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

	}

	//sets an object to an empty state

	void Date::setEmpty()
	{
		m_year = 0;
		m_month = 0;
		m_days = 0;
		errCode(0);
		comparator = 0;
	}
	
	//default constructor, sets to emty state
	Date::Date()
	{
		setEmpty();
	}

	//returns true if object is empty
	bool Date::isEmpty() const
	{
		return (m_year == 0 && m_month == 0 && m_days == 0);
	}

	//three parameters constructor

	Date::Date(int year, int month, int day) {

		if (year < min_year || year > max_year) {
			errCode(4);
			
		}
		else if (month < 1 || month> 12) {
			errCode(3);
		
		}
		else if (day < 1 || day > mdays(month, year)) {
			errCode(2);
			
		}

		else if (comparator <= min_date) {
			errCode(5);
			
		}

		if (((year > min_year && year < max_year) && (month > 1 && month < 12) && (day > 1 && day < mdays(month, year)))) {
			m_year = year;
			m_month = month;
			m_days = day;
			comparator = m_year * 372 + m_month * 31 + m_days;
			errCode(0);
		}
		else {
			*this = Date();
			comparator = 0;
		}
		
	}
	// destructor
	Date::~Date() {
	}

	// assigns the error code

	void Date::errCode(int errorCode) {
		errorState = errorCode;
		//	errCode();
	}
	int Date::errCode() const {
		return errorState;

	}

	bool Date::operator==(const Date& rhs) const {
		if (comparator != 0) {
			return this->comparator == rhs.comparator;
		}
		else {
			return false;
		}
	}
	bool Date::operator!=(const Date& rhs) const {
		if (comparator != 0) {
			return this->comparator != rhs.comparator;
		}
		else {
			return false;
		}
	}
	bool Date::operator<(const Date& rhs) const {

		if (comparator != 0) {
			return this->comparator < rhs.comparator;
		}
		else {
			return false;
		}
	}
	bool Date::operator>(const Date& rhs) const {


		if (comparator != 0) {
			return this->comparator > rhs.comparator;
		}
		else {
			return false;
		}
	}
	bool Date::operator<=(const Date& rhs) const {

		if (comparator != 0) {
			return this->comparator <= rhs.comparator;
		}
		else {
			return false;
		}
	}
	bool Date::operator>=(const Date& rhs) const {
		if (comparator != 0) {
			return this->comparator >= rhs.comparator;
		}
		else {
			return false;
		}
	}


	//return true if there is an error
	bool Date::bad() const {

		return errorState != 0;

	}

	//stores the date and validate it
	std::istream& Date::read(std::istream& istr)
	{
		char del;
		
		istr >> m_year >> del >> m_month >> del >> m_days;
		comparator = m_year * 372 + m_month * 31 + m_days;

		if (istr.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
			return istr;
		}

		if (m_year < min_year || m_year > max_year)
		{
			*this = Date();
			errCode(YEAR_ERROR);

		}
		else if (m_month < 1 || m_month> 12)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (1 > m_days || m_days > mdays(m_month, m_year)) {
			*this = Date();
			errCode(DAY_ERROR);

		}
		else if (comparator <= min_date) {

			*this = Date();
			errCode(PAST_ERROR);

		}	

		return istr;
	}

	//format the date
		std::ostream& Date::write(std::ostream& ostr) const {

			// ostr << m_year << '/' << std::setfill('0') << std::setw(2) << m_month << '/' << std::setfill('0') << std::setw(2) << m_days;
			ostr << m_year << '/';
			// sets the format for MM/DD
			ostr.fill('0');
			ostr.width(2);
			// writes MM/DD
			ostr << m_month << '/';
			ostr.width(2);
			ostr << m_days;
			
		return ostr;
	}

		
		//">>" overload
		std::istream& operator >> (std::istream& is, Date& s) {
			s.read(is);
			return is;
		}

		//"<<" overload
		std::ostream& operator << (std::ostream& os, const Date& s) {
			s.write(os);
			return os;
		}

	}

