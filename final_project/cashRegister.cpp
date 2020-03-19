#include "Header.h"
#include <iomanip>
#include "cashRegister.h"

cashRegister::cashRegister() {

}
cashRegister::cashRegister(double price, std::string title, std::string isbn, int quantity, double t) {
	priceOfBook = price;
	nameOfBook = title;
	isbnOfBook = isbn;
	quantityOfBook = quantity;
	totalPriceOfBooks = t;
}
void cashRegister::setpriceOfBook(double price) {
	priceOfBook = price;
}
void cashRegister::setnameOfBook(std::string name) {
	nameOfBook = name;
}
void cashRegister::setisbnOfBook(std::string isbn) {
	isbnOfBook = isbn;
}
void cashRegister::setquantityOfBook(int quantity) {
	quantityOfBook = quantity;
}
double cashRegister::getpriceOfBook() {
	return priceOfBook;
}
std::string cashRegister::getnameOfBook() {
	return nameOfBook;
}
std::string cashRegister::getisbnOfBook() {
	return isbnOfBook;
}
int cashRegister::getquantityOfBook() {
	return quantityOfBook;
}
void cashRegister::setTaxRate(double t) {
	taxRate = t;
}
double cashRegister::getTaxRate() {
	return taxRate;
}
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
	totalPriceOfBooks = price;
}
double cashRegister::getTotalPrice() {
	return totalPriceOfBooks;
}
void cashRegister::setNumberofBooksinCart(int n) {
	quantityOfBook = n;
}
int cashRegister::getNumberofBooksinCart() {
	return quantityOfBook;
}

//Operator overloading < >
bool cashRegister::operator < (const cashRegister &str)
{
	std::string title1 = this->nameOfBook;
	std::string title2 = str.nameOfBook;
	if (title1.length() < title2.length())
		return true;
	else
		return false;
}
bool cashRegister::operator > (const cashRegister &str)
{
	std::string title1 = this->nameOfBook;
	std::string title2 = str.nameOfBook;
	if (title1.length() > title2.length())
		return true;
	else
		return false;
}

void cashRegister::setCart(double price, std::string title, std::string isbn, int quantity, double total) {
	priceOfBook = price;
	nameOfBook = title;
	isbnOfBook = isbn;
	quantityOfBook = quantity;
	totalPriceOfBooks = total;
}
void cashRegister::printCart(int longest) {
	std::cout << quantityOfBook << "\t"; //display quantity
	std::cout << isbnOfBook << "\t"; //display ISBN //left << setw(10) << 
	std::cout << std::setw(longest + 15) << nameOfBook; //display title //left << setw(20) << 
	std::cout << priceOfBook << "\t"; //display price //left << setw(30) << 
	//std::cout << totalPriceOfBooks << std::endl;
	printf("%.2f", totalPriceOfBooks);
	std::cout << std::endl;
}