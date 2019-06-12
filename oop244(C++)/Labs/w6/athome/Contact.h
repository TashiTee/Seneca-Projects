/**********************************************************
Workshop 6 - CLass with a Resource at home
// Workshop <Workshop #6>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: contact.h
**********************************************************/

#ifndef SICT_CONTACT_H__
#define SICT_CONTACT_H__


namespace sict {

	const int MAX_CHAR = 20; // array size 20 + 1 for null terminator

	class Contact {
	private:
		char m_name[MAX_CHAR];
		long long *m_phone;
		int m_size;
		void setEmptyState();
		char* copyName(const char* right);
	public:
		Contact();
		Contact(const char* name, const long long* phone, int size);
		Contact(const Contact& obj);
		bool isValid(const long long* phone) const;
		int countryCode(const long long* phone) const;
		int areaCode(const long long* phone) const;
		int phoneNum(const long long* phone) const;
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator=(const Contact& obj);
		Contact& operator+=(long long newPhone);
	};


}
#endif