/*************************************************************************
// week 4 at home
// File: Notifications.cpp
// Version: 1.0
// Date: 02/27/2019
// Author: Tashi Tsering
// Description: implementations of notification.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include "Notifications.h"

#include <cstring>

namespace sict {

	Notifications::Notifications() : messages(nullptr), current_size(0), max_size(0) {}
	Notifications::Notifications(size_t max_size_) : Notifications() {
		if (max_size_ > 0) {
			max_size = max_size_;
			messages = new Message*[max_size_];
		}
	}
	Notifications::Notifications(const Notifications &src) : Notifications() {
		if (src.max_size > 0) {
			max_size = src.max_size;
			current_size = src.current_size;
			messages = new Message*[src.max_size];
			memcpy(messages, src.messages, src.max_size * sizeof(Message*));
		}
	}
	Notifications::Notifications(Notifications &&src) {
		messages = src.messages;
		max_size = src.max_size;
		current_size = src.current_size;
		src.messages = nullptr;
		src.max_size = src.current_size = 0;
	}
	Notifications::~Notifications() {
		if (messages != nullptr) {
			messages = { 0 };
			delete[] messages;
			messages = nullptr;
			current_size = max_size = 0;
		}
	}
	Notifications &Notifications::operator+=(const Message &msg) {
		if (msg.empty() || current_size >= max_size) {
			return *this;
		}
		messages[current_size++] = &const_cast<Message&>(msg);
		return *this;
	}
	Notifications &Notifications::operator-=(const Message &msg) {
		if (msg.empty()) {
			return *this;
		}
		for (size_t i = 0; i < current_size; ++i) {
			if (messages[i] == &msg) {
				messages[i] = nullptr;
				--current_size;
				break;
			}
		}
		return *this;
	}
	void Notifications::display(std::ostream &out) const {
		for (size_t i = 0; i < current_size; ++i) {
			if (messages[i] == nullptr || messages[i]->empty()) {
				continue;
			}
			messages[i]->display(out);
		}
	}
	size_t Notifications::size() const {
		return current_size;
	}
	std::ostream &operator<<(std::ostream &out, const Notifications &notifications) {
		notifications.display(out);
		return out;
	}

}  // namespace sict
