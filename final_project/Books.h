#pragma once
#include <iostream>
#include <string>

using namespace std;

class Books
{
private:
	int Number;
	int ISBN;
	string Title;
	string Author;
	string Publisher;
	int Date;
	int Stock;
	double Wholesale;
	double Retail;

public:
	Books() {
		
	}
	void books() {}
	Books(int number, int isbn, string title, string author, string publisher, int date, int stock, double wholesale, double retail)
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
	void setNumber(int number)
	{
		Number = number;
	}
	int getNumber()
	{
		return Number;
	}

	void setISBN(int isbn)
	{
		ISBN = isbn;
	}
	int getISBN()
	{
		return ISBN;
	}

	void setTitle(string title)
	{
		Title = title;
	}
	string getTitle()
	{
		return Title;
	}

	void setAuthor(string author)
	{
		Author = author;
	}
	string getAuthor()
	{
		return Author;
	}

	void setPublisher(string publisher)
	{
		Publisher = publisher;
	}
	string getPublisher()
	{
		return Publisher;
	}

	void setDate(int date)
	{
		Date = date;
	}
	int getDate()
	{
		return Date;
	}

	void setStock(int stock)
	{
		Stock = stock;
	}
	int getStock()
	{
		return Stock;
	}

	void setWholesale(double wholesale)
	{
		Wholesale = wholesale;
	}
	double getWholesale()
	{
		return Wholesale;
	}

	void setRetail(double retail)
	{
		Retail = retail;
	}
	double getRetail()
	{
		return Retail;
	}
};
