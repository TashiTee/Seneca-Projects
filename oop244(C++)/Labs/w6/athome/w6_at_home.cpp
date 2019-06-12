/**********************************************************
Workshop 6 - CLass with a Resource at home
// Workshop <Workshop #6>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: contact.h
**********************************************************/

#include <iostream>
#include "Contact.h"

using namespace std;
using namespace sict;

int main() {
	cout << "----------------------------------------" << endl;
	cout << "Maximum no of characters in a name: " << sict::MAX_CHAR << endl;
	sict::Contact theContact("John Doe", nullptr, 0); // sict:: intentional
    theContact.display();
    theContact += 14161234567LL;
    theContact += 14162345678LL;
    theContact += 14163456789LL;
    theContact += 114164567890LL;
    theContact.display();

    cout << endl << "Testing! Please wait:" << endl;

    for (int i = 1; i <= 5000000; i++)
    {
        Contact temp = theContact;
        theContact = temp;
        theContact = theContact;
        if (!(i % 10000))
            cout << ".";
        if (!(i % 500000))
            cout << endl;
    }
    cout << endl;
    theContact.display();

	theContact = Contact("", nullptr, 0);
	theContact += 14161230002LL;
	theContact.display();

    return 0;
}
