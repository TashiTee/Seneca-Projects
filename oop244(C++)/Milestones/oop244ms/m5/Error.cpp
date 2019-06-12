/**********************************************************
Milestone 5 - Aid Management Application
// Milestone <Milestone #5>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Error.cpp
**********************************************************/

#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;
using namespace aid;

namespace aid
{
	Error::Error(const char * errorMessage)
	{
		if (errorMessage != nullptr)
		{
			int length = strlen(errorMessage);
			m_message = new char[length];
			for (int i = 0; i < length; i++)
			{
				m_message[i] = errorMessage[i];
			}
			m_message[length] = '\0';
		}
		else
			m_message = nullptr;
	}
	Error::~Error()
	{
		delete[] m_message;
		m_message = nullptr;
	}
	void Error::clear()
	{
		delete[] m_message;
		m_message = nullptr;
	}
	bool Error::isClear() const
	{
		return (m_message == nullptr) ? true : false;
	}
	void Error::message(const char * str)
	{
		int length = strlen(str);

		delete[] m_message;
		m_message = nullptr;

		m_message = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			m_message[i] = str[i];
		}
		m_message[length] = '\0';
	}
	const char * Error::message() const
	{
		return m_message;
	}
	std::ostream & operator<<(std::ostream& os, const Error & er)
	{
		if (!er.isClear())
		{
			os << er.message();
		}
		return os;
	}
}

