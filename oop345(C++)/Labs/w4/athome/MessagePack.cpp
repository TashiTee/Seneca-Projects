/*************************************************************************
// week 4 at home
// File: MessagePack.cpp
// Version: 1.0
// Date: 02/27/2019
// Author: Tashi Tsering
// Description: implementations of MessagePack.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include "MessagePack.h"

#include <cstring>

namespace sict {

	MessagePack::MessagePack() : messages(nullptr), messages_size(0) {}
	MessagePack::MessagePack(Message **messages_, size_t messages_sz_) : MessagePack() {
		if (messages_ != nullptr && messages_sz_ != 0) {
			messages_size = 0;
			messages = new Message*[messages_size];
			for (size_t i = 0; i < messages_sz_; ++i) {
				if (messages_[i] != nullptr && !messages_[i]->empty()) {
					messages[messages_size++] = messages_[i];
				}
			}
		}
	}
	MessagePack::MessagePack(const MessagePack &src) : MessagePack() {
		if (src.messages != nullptr && src.messages_size != 0) {
			messages_size = 0;
			messages = new Message*[messages_size];
			for (size_t i = 0; i < src.messages_size; ++i) {
				if (src.messages[i] != nullptr && !src.messages[i]->empty()) {
					messages[messages_size++] = src.messages[i];
				}
			}
		}
	}
	MessagePack::MessagePack(MessagePack &&src) {
		messages = src.messages;
		messages_size = src.messages_size;
		src.messages = nullptr;
		src.messages_size = 0;
	}
	MessagePack::~MessagePack() {
		if (messages != nullptr) {
			messages = nullptr;
			messages_size = 0;
		}
	}
	void MessagePack::display(std::ostream &out) const {
		for (size_t i = 0; i < messages_size; ++i) {
			if (messages[i] == nullptr || messages[i]->empty()) {
				continue;
			}
			messages[i]->display(out);
		}
	}
	size_t MessagePack::size() const {
		return messages_size;
	}
	std::ostream &operator<<(std::ostream &out, const MessagePack &pack) {
		pack.display(out);
		return out;
	}

}  // namespace sict
