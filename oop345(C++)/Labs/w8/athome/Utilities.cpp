/*************************************************************************
// week 8 at home
// File: Utilities.cpp
// Version: 1.0
// Date: 04/08/2019
// Author: Tashi Tsering
// Description: use merge functions for both raw and smart pointers
// A short explanation of what the filename is about goes here!
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty filename for workshop
*************************************************************************/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t outer = 0; outer < desc.size(); ++outer) {
			for (size_t inner = 0; inner < price.size(); ++inner) {
				if (desc[outer].code == price[inner].code) {
					Product* pl = new Product(desc[outer].desc, price[inner].price);
					pl->validate();
					priceList += pl;
					//deallocating memory for pl
					delete pl;
					pl = { nullptr };
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t outer = 0; outer < desc.size(); ++outer) {
			for (size_t inner = 0; inner < price.size(); ++inner) {
				if (desc[outer].code == price[inner].code) {
					std::unique_ptr<Product> pl{ new Product(desc[outer].desc, price[inner].price) };
					pl->validate();
					priceList += pl;
				}
			}
		}
		return priceList;
	}
}
