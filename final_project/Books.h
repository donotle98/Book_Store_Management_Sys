/************************************
Extracting object data from the text file and creating a class to store all the object data to be accessed by the other classes and functions. The setters, getters, print book data function, and are stored here as well as the loop to open the text file and extract the object data.
************************************/
#ifndef books_header
#define books_header
#include "Header.h"

class Books {
private:
	int Number;
	std::string ISBN;
	std::string Title;
	std::string Author;
	std::string Publisher;
	int Date;
	int Stock;
	int Quantity;
	double Wholesale;
	double Retail;

public:
	Books();
	Books(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail);
	void setBooks(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail);

	void setNumber(int number);
	int getNumber();

	void setISBN(std::string isbn);
	std::string getISBN();

	void setTitle(std::string title);
	std::string getTitle();

	void setAuthor(std::string author);
	std::string getAuthor();

	void setPublisher(std::string publisher);
	std::string getPublisher();

	void setDate(int date);
	int getDate();

	void setStock(int stock);
	int getStock();

	void setWholesale(double wholesale);
	double getWholesale();

	void setRetail(double retail);
	double getRetail();

	void print();
	void getBookData(Books library[], int& numOfBooks);
};

#endif books_header

