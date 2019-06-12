/*************************************************************************
// Milestone 2
// File: CustomerOrder.h
// Version: 1
// Date: 04/11/2019
// Author: Tashi Tsering
// Description: contains all the functionality for handling customer orders 
as they move along the assembly line
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/

#ifndef CUSTOMER_ORDER_H_
#define CUSTOMER_ORDER_H_

#include <iostream>
#include "ItemSet.h"

namespace sict {

	class ItemOrder {
	
	public:

		std::string name;
		unsigned int serial_num;
		bool fulfilled;
		bool operator==(const ItemOrder &);
		bool operator!=(const ItemOrder &);
		bool operator==(const ItemSet &);
		bool operator!=(const ItemSet &);
	};

	class CustomerOrder {
		std::string cust_name;
		std::string prod_name;
		ItemOrder *item_orders;
		size_t item_orders_size;

	public:

		CustomerOrder();
		CustomerOrder(const std::string &);
		CustomerOrder(const CustomerOrder &) = delete;
		CustomerOrder(CustomerOrder &&);
		~CustomerOrder();
		void fillItem(ItemSet &, std::ostream &);
		bool isFilled() const;
		bool isItemFilled(const std::string &) const;
		std::string getNameProduct();
		void display(std::ostream &, bool = false);
		CustomerOrder &operator=(const CustomerOrder &) = delete;
		CustomerOrder &operator=(CustomerOrder &&);
	};

}  // namespace sict

#endif  // CUSTOMER_ORDER_H_
