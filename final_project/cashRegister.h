#pragma once
#include "Books.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

class cashRegister {
private:
	double priceOfBook;
	std::string nameOfBook;
	int numberOfBooksinCart;
	int numberIDofBook;
	double taxRate;
	double taxOfBook;
	double subtotal;
	double totalPriceOfBook;
public:
	cashRegister() {}

	//Accessors
	void setSubTotal(double st);
	double getSubTotal();
	void setTaxofBook(double tofb);
	double getTaxofBook();
	void setTotalPrice(double price);
	double getTotalPrice();
	void setNumberofBooksinCart(int n);
	int getNumberofBooksinCart();

};