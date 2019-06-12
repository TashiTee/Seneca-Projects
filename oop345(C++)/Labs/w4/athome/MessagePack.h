/*************************************************************************
// week 4 at home
// File: MessagePack.h
// Version: 1.0
// Date: 02/27/2019
// Author: Tashi Tsering
// Description: defintions of messagepack.cpp file
// A short explanation of what the file is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef MESSAGE_PACK_H_
#define MESSAGE_PACK_H_

#include <iostream>

#include "Message.h"

namespace sict {

	class MessagePack {
		Message **messages;
		size_t messages_size;
	public:
		MessagePack();
		MessagePack(Message **, size_t);
		MessagePack(const MessagePack &);
		MessagePack(MessagePack &&);
		~MessagePack();
		void display(std::ostream &out) const;
		size_t size() const;
	};

	std::ostream &operator<<(std::ostream &, const MessagePack &);

}  // namespace sict

#endif  // MESSAGE_PACK_H_
