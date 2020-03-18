#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "inventory.h"
using namespace std;

class Books
{
private:
	int Number;
	std::string ISBN;
	std::string Title;
	std::string Author;
	std::string Publisher;
	int Date;
	int Stock;
	double Wholesale;
	double Retail;

public:
	Books();
	Books(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail);
	void setBooks(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail);

	void setNumber(int number);
	int getNumber();

	void setISBN(int isbn);
	std::string getISBN();

	void setTitle(string title);
	string getTitle();

	void setAuthor(string author);
	string getAuthor();

	void setPublisher(string publisher);
	string getPublisher();

	void setDate(int date);
	int getDate();

	void setStock(int stock);
	int getStock();

	void setWholesale(double wholesale);
	double getWholesale();

	void setRetail(double retail);
	double getRetail();

	bool isISBN(std::string s) const; //compare isbn
	bool isTITLE(std::string s) const; //compare title
	void print();
	void getBookData(Books library[], int& numOfBooks);
};