#pragma once
#include "inventory.h"
#include "cashRegister.h"
#include "Books.h"
#include <iostream>
#include <string>
#include <iomanip>

class report{
private:

public:
	report() {}
	void inventoryListing();
	void inventoryWholeSaleValue();
	void inventoryRetailValue();
	void listingByQuantity();
	void listingByCost();
	void listingByAge();
};