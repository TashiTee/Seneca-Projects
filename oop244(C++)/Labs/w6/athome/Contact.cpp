/**********************************************************
Workshop 6 - CLass with a Resource at home
// Workshop <Workshop #6>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: contact.cpp
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Contact.h"
#include <cstring>
#include <iomanip> 

using namespace std;

namespace sict {

	void Contact::setEmptyState()
	{
		m_name[0] = '\0';
		m_phone = nullptr;
		m_size = 0;
	}
	Contact::Contact()
	{
		setEmptyState();
	}
	Contact::Contact(const char* name, const long long* phone, int size)
	{
		int validNumsSize = 0, j = 0;
		if (name != nullptr && name[0] != '\0') {
			copyName(name);
			if (size > 0) {
				for (int i = 0; i < size; i++)
				{
					if (isValid(&phone[i]))
					{
						validNumsSize++;
					}
				}
				m_phone = new long long[m_size = validNumsSize];
				for (int i = 0; i < size; i++)
				{
					if (isValid(&phone[i]))
					{
						m_phone[j] = phone[i];
						j++;
					}
				}
			}
			else
			{
				m_phone = nullptr;
				m_size = 0;
			}
		}
		else
		{
			setEmptyState();
		}
	}
	Contact::Contact(const Contact& obj)
	{
		copyName(obj.m_name);

		m_phone = new long long[m_size = obj.m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_phone[i] = obj.m_phone[i];
		}
	}
	bool Contact::isValid(const long long* phone) const
	{
		bool result = false;
		if (countryCode(phone) < 100 && countryCode(phone) != 0 && (int)(areaCode(phone) / 100) != 0 && (int)(phoneNum(phone) / 1000000) != 0)
			result = true;
		return result;
	}
	int Contact::countryCode(const long long* phone) const
	{
		return (int)(*phone / 10000000000);
	}
	int Contact::areaCode(const long long* phone) const
	{
		return (int)((*phone % 10000000000) / 10000000);
	}
	int Contact::phoneNum(const long long* phone) const
	{
		return *phone % 10000000;
	}
	Contact::~Contact()
	{
		delete[] m_phone;

	}
	bool Contact::isEmpty() const
	{
		return (m_name[0] == '\0') ? true : false;
	}
	void Contact::display() const
	{
		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_name << endl;
			for (int i = 0; i < m_size; i++)
			{
				cout << "(+" << countryCode(&m_phone[i]) << ") " << areaCode(&m_phone[i]) << " ";
				cout << (int)(phoneNum(&m_phone[i]) / 10000) << "-" << setfill('0') << std::setw(4) << phoneNum(&m_phone[i]) % 10000 << endl;
			}
		}
	}
	Contact& Contact::operator=(const Contact& obj)
	{
		if (this != &obj)
		{
			copyName(obj.m_name);
			delete[] m_phone;
			m_phone = new long long[m_size = obj.m_size];
			for (int i = 0; i < m_size; i++)
			{
				m_phone[i] = obj.m_phone[i];
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long newPhone)
	{
		if (isValid(&newPhone))
		{
			long long* temp = new long long[m_size + 1];
			int i;
			for (i = 0; i < m_size; i++)
			{
				temp[i] = m_phone[i];
			}
			m_size += 1;
			temp[i] = newPhone;
			delete[] m_phone;
			m_phone = temp;

		}
		return *this;
	}

	char* Contact::copyName(const char* right)
	{
		m_name[0] = '\0';
		strncpy(m_name, right, strlen(right));
		m_name[strlen(right)] = '\0';

		return m_name;
	}
}