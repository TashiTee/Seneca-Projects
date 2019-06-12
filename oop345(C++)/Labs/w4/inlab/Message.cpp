/*************************************************************************
// week 4 in lab
// File: Message.cpp
// Version: 1.0
// Date: 02/21/2019
// Author: Tashi Tsering
// Description: implementation of message.h file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include "Message.h"

#include <iomanip>

namespace sict {

	Message::Message() : tweet_user(""), reply_user(""), tweet_txt("") {}

	Message::Message(const std::string &message) : Message() {

		size_t spaced_index = message.find_first_of(" ");

		if (spaced_index != std::string::npos) {
			tweet_user = message.substr(0, spaced_index - 0);
		}
		size_t at_symbol_index = message.find_first_of("@");

		if (at_symbol_index != std::string::npos) {
			size_t i = message.substr(at_symbol_index + 1).find_first_of(" ");

			if (i != std::string::npos) {
				size_t next_spaced_index = i + (at_symbol_index + 1);
				reply_user = message.substr(at_symbol_index + 1, next_spaced_index - (at_symbol_index + 1));
				spaced_index = next_spaced_index;
			}
			else {
				spaced_index = i + (at_symbol_index + 1);
			}
		}

		if (spaced_index != std::string::npos) {
			tweet_txt = message.substr(spaced_index + 1);
		}
	}
	bool Message::empty() const {
		return tweet_user.empty() || tweet_txt.empty();
	}
	void Message::display(std::ostream &out) const {

		if (empty()) {
			return;
		}
		std::cout << std::setfill(' ') << std::setw(7) << std::left << ">User" << std::setw(0) << ": " << tweet_user << std::endl;
		
		if (!reply_user.empty()) {
			std::cout << std::setfill(' ') << std::setw(7) << " Reply" << std::setw(0) << ": " << reply_user << std::endl;
		}
		std::cout << std::setfill(' ') << std::setw(7) << " Tweet" << std::setw(0) << ": " << tweet_txt << '\r' << std::endl;  // Eric McDonald: The assignment requires a carriage return to be here for some reason...
	}

}  // namespace sict
