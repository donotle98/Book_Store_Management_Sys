#include "cashRegister.h"

void cashRegister::setSubTotal(double st) {
	subtotal = st;
}
double cashRegister::getSubTotal() {
	return subtotal;
}
void cashRegister::setTaxofBook(double tofb) {
	taxOfBook = tofb;
}
double cashRegister::getTaxofBook() {
	return taxOfBook;
}
void cashRegister::setTotalPrice(double price) {
	totalPriceOfBook = price;
}
double cashRegister::getTotalPrice() {
	return totalPriceOfBook;
}
void cashRegister::setNumberofBooksinCart(int n) {
	numberOfBooksinCart = n;
}
int cashRegister::getNumberofBooksinCart() {
	return numberOfBooksinCart;
}