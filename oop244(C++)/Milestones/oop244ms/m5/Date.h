/**********************************************************
Milestone 5 - Aid Management Application
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Date.h
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#ifndef AMA_DATE_H
#define AMA_DATE_H

#define NO_ERROR   0  
#define CIN_FAILED 1  
#define DAY_ERROR  2  
#define MON_ERROR  3  
#define YEAR_ERROR 4  
#define PAST_ERROR 5  

namespace aid {

	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date {

	private:

		int year;
		int month;
		int days;
		int errorState;
		int comparator;

		int mdays(int, int)const;

		void errCode(int);

		bool is_empty() const;

	public:

		//Constructors
		Date();
		Date(int, int, int);

		//Queries And Modifier
		int errCode() const;
		bool bad() const;

		//Operators

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream& ostr, const Date& writeDate);
	std::istream& operator>>(std::istream& istr, Date& readDate);


}
#endif//AMA_DATE_H
