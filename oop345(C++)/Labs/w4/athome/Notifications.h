/*************************************************************************
// week 4 at home
// File: Notifications.h
// Version: 1.0
// Date: 02/27/2019
// Author: Tashi Tsering
// Description: defintions of notification.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef NOTIFICATIONS_H_
#define NOTIFICATIONS_H_

#include <iostream>

#include "Message.h"

namespace sict {

	class Notifications {
		Message **messages;
		size_t current_size, max_size;
	public:
		Notifications();
		Notifications(size_t);
		Notifications(const Notifications &);
		Notifications(Notifications &&);
		~Notifications();
		Notifications &operator+=(const Message &);
		Notifications &operator-=(const Message &);
		void display(std::ostream &out) const;
		size_t size() const;
	};

	std::ostream &operator<<(std::ostream &, const Notifications &);

}  // namespace sict

#endif  // NOTIFICATIONS_H_
