#include "Header.h"
#include "Books.h"

Books::Books(){
}
Books::Books(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail) {
	Number = number;
	ISBN = isbn;
	Title = title;
	Author = author;
	Publisher = publisher;
	Date = date;
	Stock = stock;
	Wholesale = wholesale;
	Retail = retail;
}
void Books::setBooks(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail)
{
	Number = number;
	ISBN = isbn;
	Title = title;
	Author = author;
	Publisher = publisher;
	Date = date;
	Stock = stock;
	Wholesale = wholesale;
	Retail = retail;
}
void Books::setNumber(int number)
{
	Number = number;
}
int Books::getNumber()
{
	return Number;
}
void Books::setISBN(std::string isbn)
{
	ISBN = isbn;
}
std::string Books::getISBN()
{
	return ISBN;
}
void Books::setTitle(std::string title)
{
	Title = title;
}
std::string Books::getTitle()
{
	return Title;
}

void Books::setAuthor(std::string author)
{
	Author = author;
}
std::string Books::getAuthor()
{
	return Author;
}

void Books::setPublisher(std::string publisher)
{
	Publisher = publisher;
}
std::string Books::getPublisher()
{
	return Publisher;
}

void Books::setDate(int date)
{
	Date = date;
}
int Books::getDate()
{
	return Date;
}

void Books::setStock(int stock)
{
	Stock = stock;
}
int Books::getStock()
{
	return Stock;
}

void Books::setWholesale(double wholesale)
{
	Wholesale = wholesale;
}
double Books::getWholesale()
{
	return Wholesale;
}

void Books::setRetail(double retail)
{
	Retail = retail;
}
double Books::getRetail()
{
	return Retail;
}
void print(Books)
{
	std::cout << "" << std::endl;
	std::cout << "#" << Books().getNumber() << " " << std::endl;
	std::cout << Books().getISBN() << " " << std::endl;
	std::cout << Books().getTitle() << " " << std::endl;
	std::cout << Books().getAuthor() << " " << std::endl;
	std::cout << Books().getPublisher() << " " << std::endl;
	std::cout << Books().getDate() << " " << std::endl;
	std::cout << "Current Stock: " << Books().getStock() << " " << std::endl;
	std::cout << "Wholesale Value: $" << Books().getWholesale() << " " << std::endl;
	std::cout << "Retail Value: $" << Books().getRetail() << " " << std::endl;
	std::cout << std::endl;
}
