/**********************************************************
Milestone 1 - Aid Management Application Date Module
// Milestone <Milestone #1>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Date.h
**********************************************************/

#ifndef AID_DATE_H
#define AID_DATE_H

// error handeling constants 
#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3 
#define YEAR_ERROR 4
#define PAST_ERROR 5

namespace aid {
	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;

	class Date
	{
		int m_year;
		int m_month;
		int m_days;
		float comparator;// = m_year * 372 + m_month * 31 + m_days;
		int errorState;  // holds an error code 

	public:
		
		Date();
		Date(int year, int month, int day);
		~Date();

		void setEmpty();
		bool isEmpty() const;

		void errCode(int errorCode);
		int errCode()const;
		int mdays(int mon, int year)const;

		// operator overloading 
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		bool bad() const;
			
		// IO member functions 
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;


	};
	
	// helper stream
	// ostream << Date
	std::istream& operator >> (std::istream& is, Date& s);

	// istream >> Date
	std::ostream& operator << (std::ostream& os, const Date& s);
}
#endif // !AMA_DATE_H
