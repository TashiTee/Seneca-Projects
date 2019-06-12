/*************************************************************************
// week 4 in lab
// File: Message.h
// Version: 1.0
// Date: 02/21/2019
// Author: Tashi Tsering
// Description: class template named Message for managing a single message between users
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <iostream>

namespace sict {

	class Message {
		std::string tweet_user, reply_user, tweet_txt;

	public:

		Message();
		Message(const std::string &);
		bool empty() const;
		void display(std::ostream &) const;
	};

}  // namespace sict

#endif  // MESSAGE_H_

