#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Books.h"

Books::Books(){}
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
//Print function to print contents of Book Arrays
void Books::print()
{
	std::cout << "" << std::endl;
	std::cout << "#" << Number << " " << std::endl;
	std::cout << ISBN << " " << std::endl;
	std::cout << Title << " " << std::endl;
	std::cout << Author << " " << std::endl;
	std::cout << Publisher << " " << std::endl;
	std::cout << Date << " " << std::endl;
	std::cout << "Current Stock: " << Stock << " " << std::endl;
	std::cout << "Wholesale Value: $" << Wholesale << " " << std::endl;
	std::cout << "Retail Value: $" << Retail << " " << std::endl;
	std::cout << std::endl;
}
void Books::print(Books library[], int bookCount, std::string title) {
	for (int i = 0; i < bookCount; i++) {
		if (library[i].getTitle() == title) {
			library[i].print();
		}
	}
}

//Function to read book text file into an array of books
void getBookData(Books library[], int& numOfBooks) {
	std::string isbn{};
	std::string title;
	std::string author;
	std::string publisher;
	int date{};
	int stock{};
	double wholesale{};
	double retail{};
	std::string line;
	int number;
	int i = 0;

	std::ifstream infile;
	infile.open("Booklist_Final.txt");

	// Check for successful file open
	if (!infile.is_open()) {
		std::cout << "Error" << std::endl;
		system("pause");
		exit(0);
	}
	while (!infile.eof()) {
		//Exception handling Try catch file read
		//If there is an exception with reading in lines
		try {
			getline(infile, line);
			number = std::stoi(line);
			getline(infile, line);
			isbn = line;
			getline(infile, line);
			title = line;
			getline(infile, line);
			author = line;
			getline(infile, line);
			publisher = line;
			getline(infile, line);
			date = std::stoi(line);
			getline(infile, line);
			stock = std::stoi(line);
			getline(infile, line);
			wholesale = std::stod(line);
			getline(infile, line);
			retail = std::stod(line);
			getline(infile, line);
			library[i].setBooks(number, isbn, title, author, publisher, date, stock, wholesale, retail);
			i++;
		}
		catch (const std::invalid_argument) {
			std::cout << "Reading exception thrown\n";
		}

	}
	infile.close();
}

