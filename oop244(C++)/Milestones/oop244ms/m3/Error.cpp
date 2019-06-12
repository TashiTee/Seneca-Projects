/**********************************************************
Milestone 3 - Aid Management Application Good class
// Milestone <Milestone #3>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: Error.cpp
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Error.h"

using namespace std;

namespace aid {

	Error::Error(const char* errorMessage)
	{
		if (errorMessage == nullptr || errorMessage[0] == '\0')
		{
			m_MessageAddress = nullptr;
		}

		else
		{
			m_MessageAddress = new char[strlen(errorMessage) + 1];
			strcpy(m_MessageAddress, errorMessage);
		}
	}

	Error::~Error()
	{
		delete[] m_MessageAddress;
		m_MessageAddress = nullptr;
	}

	void Error::clear()
	{
		delete[] this->m_MessageAddress;
		m_MessageAddress = nullptr;
	}

	bool Error::isClear() const
	{
		return (m_MessageAddress == nullptr || m_MessageAddress[0] == '\0') ? true : false;
	}

	void Error::message(const char* str)
	{
		delete[] m_MessageAddress;
		m_MessageAddress = new char[strlen(str) + 1];
		strcpy(m_MessageAddress, str);
	}

	const char* Error::message() const
	{
		return m_MessageAddress;
	}

	std::ostream& operator<<(std::ostream& os, const Error& em)
	{
		if (!em.isClear())
		{
			os << em.message();
		}
		return os;
	}
}