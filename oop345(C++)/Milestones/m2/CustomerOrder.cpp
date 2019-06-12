/*************************************************************************
// Milestone 2
// File: CustomerOrder.cpp
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: managing and processing customer orders
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#include "CustomerOrder.h"
#include <vector>
#include <iomanip>
#include "Utilities.h"

namespace sict {

	static Utilities utilit;


	//	A default constructor that sets the object to a safe empty state.
	CustomerOrder::CustomerOrder() : item_orders(nullptr), item_orders_size(0) {}


	CustomerOrder::CustomerOrder(const std::string &order_entry) : CustomerOrder() {

		utilit.setDelimiter('|');
		size_t next_position = 0;
		cust_name = utilit.extractToken(order_entry, next_position);

		if (cust_name == order_entry) {
			throw order_entry;
		}
		prod_name = utilit.extractToken(order_entry, next_position);
			if (prod_name == order_entry) {
			throw order_entry;
			}

		std::string first_item_name = utilit.extractToken(order_entry, next_position);
		if (first_item_name == order_entry) {
			throw order_entry;
		}

		std::vector<std::string> entries;
		entries.push_back(first_item_name);
		std::string token;
		
		while (next_position < order_entry.length() - 1) {
			token = utilit.extractToken(order_entry, next_position);
			entries.push_back(token);
		}
		item_orders = new ItemOrder[item_orders_size = entries.size()];
		for (size_t i = 0; i < item_orders_size; ++i) {
			item_orders[i].name = entries[i];  // Copies entries to a dynamically-allocated array, as according to the assignment specifications.
			item_orders[i].serial_num = 0;
			item_orders[i].fulfilled = false;
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder &&src) {
		item_orders = src.item_orders;
		item_orders_size = src.item_orders_size;
		cust_name = src.cust_name;
		prod_name = src.prod_name;
		src.item_orders = nullptr;
		src.item_orders_size = 0;
		src.cust_name = src.prod_name = "";
	}

	// A destructor that deallocates any memory that the object has allocated.
	CustomerOrder::~CustomerOrder() {
		if (item_orders != nullptr) {
			delete[] item_orders;
			item_orders = nullptr;
		}
		item_orders_size = 0;
	}

	/*
	This function checks each item request, fills it if the requested item 
	is available and the request has not been filled, reports the filling in 
	the format shown below and decrements the item stock by one
	*/
	void CustomerOrder::fillItem(ItemSet &item, std::ostream &out) {
		ItemOrder *order = nullptr;

		for (size_t i = 0; i < item_orders_size; ++i) {
			if (item_orders[i] == item) {
				order = &item_orders[i];
				break;
			}
		}
		if (order == nullptr) {
			return;
		}

		auto order_serial = order->serial_num == 0 ? item.getSerialNumber() : order->serial_num;  
		if (isItemFilled(item.getName())) {
			out << " Unable to fill " << cust_name << " [" << prod_name << "][" << item.getName() << "][" << order_serial << "] already filled" << std::endl;
		}
		else if (item.getQuantity() == 0) {
			out << " Unable to fill " << cust_name << " [" << prod_name << "][" << item.getName() << "][" << order_serial << "] out of stock" << std::endl;
		}
		else if (*order == item && !order->fulfilled) {
			order->fulfilled = true;
			order->serial_num = item.getSerialNumber();
			--item;
			out << " Filled " << cust_name << " [" << prod_name << "][" << item.getName() << "][" << order->serial_num << "]" << std::endl;
		}
	}

	// searches the list of items requested and returns true if all have been filled; false otherwise
	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < item_orders_size; ++i) {
			if (!item_orders[i].fulfilled) {
				return false;
			}
		}
		return true;
	}

	/* receives the name of an item, search the item request list for that item and 
	returns true if all requests for that item have been filled; false, otherwise.
	If the item is not in the request list, this function returns true. 
	*/

	bool CustomerOrder::isItemFilled(const std::string &item_name) const {
		for (size_t i = 0; i < item_orders_size; ++i) {
			if (item_orders[i].name == item_name) {
				return item_orders[i].fulfilled;
			}
		}
		return false;
	}

	std::string CustomerOrder::getNameProduct() {
		return cust_name + " [" + prod_name + "]";
	}

	/*
	receives a reference to an std::ostream object os and a Boolean showDetail
	and inserts the data for the current object into stream os
	*/
	void CustomerOrder::display(std::ostream &out, bool in_detail) {

		out << std::left << std::setw(utilit.getFieldWidth() - 4) << std::setfill(' ');
		out << cust_name << std::setw(0) << " [" << prod_name << "]" << std::endl;
		for (size_t i = 0; i < item_orders_size; ++i) {
			out << std::left << std::setw(utilit.getFieldWidth() - 3) << std::setfill(' ') << " " << std::setw(0);
			if (in_detail) {
				out << "[" << item_orders[i].serial_num << "] " << item_orders[i].name << " – " << item_orders[i].fulfilled << std::endl;
			}
			else {
				out << item_orders[i].name << std::endl;
			}
		}
	}

	CustomerOrder &CustomerOrder::operator=(CustomerOrder && src) {
		if (this != &src) {
			item_orders = src.item_orders;
			item_orders_size = src.item_orders_size;
			cust_name = src.cust_name;
			prod_name = src.prod_name;
			src.item_orders = nullptr;
			src.item_orders_size = 0;
			src.cust_name = src.prod_name = "";
		}
		return *this;
	}

	bool ItemOrder::operator==(const ItemOrder &rhs) {
		return name == rhs.name;
	}
	bool ItemOrder::operator!=(const ItemOrder &rhs) {
		return !(*this == rhs);
	}
	bool ItemOrder::operator==(const ItemSet &rhs) {
		return name == rhs.getName();
	}
	bool ItemOrder::operator!=(const ItemSet &rhs) {
		return !(*this == rhs);
	}

}  // namespace sict
