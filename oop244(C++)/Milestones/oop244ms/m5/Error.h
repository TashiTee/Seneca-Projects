/**********************************************************
Milestone 5 - Aid Management Application
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Error.h
**********************************************************/

#ifndef AID_ERROR_H
#define AID_ERROR_H

#include <iostream>

namespace aid
{
	class Error
	{
		char* m_message;
	public:
		explicit Error(const char* errorMessage = nullptr);
		Error(const Error& em) = delete;
		Error& operator=(const Error& em) = delete;
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& er);
}
#endif // #pragma once
