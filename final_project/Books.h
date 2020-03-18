#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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
	Books() {
		
	}
	void books() {}
	Books(int number, std::string isbn, std::string title, std::string author, std::string publisher, int date, int stock, double wholesale, double retail)
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

	//compare isbn
	bool isISBN(std::string s) const
	{
		return(ISBN == s);
	}
	//compare title
	bool isTITLE(std::string s) const
	{
		return(Title == s);
	}


	std::string getISBN()
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
	void print()
	{
		std::cout << Number << " " << std::endl;
		std::cout << ISBN << " " << std::endl;
		std::cout << Title << " " << std::endl;
		std::cout << Author << " " << std::endl;
		std::cout << Publisher << " " << std::endl;
		std::cout << Date << " " << std::endl;
		std::cout << Stock << " " << std::endl;
		std::cout << Wholesale << " " << std::endl;
		std::cout << Retail << " " << std::endl;
		std::cout << std::endl;
	}
};
int main2()
{
	int number;
	std::string isbn{};
	std::string title;
	std::string author;
	std::string publisher;
	int date{};
	int stock{};
	double wholesale{};
	double retail{};
	std::vector<Books> library;
	std::string line;


	std::ifstream infile;
	infile.open("Booklist_Final.txt");

	// Check for successful file open
	if (!infile.is_open()) {
		std::cout << "Error" << std::endl;
		system("pause");
		exit(0);
	}
	while (!infile.eof())
	{
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
		Books a = Books(number, isbn, title, author, publisher, date, stock, wholesale, retail);
		library.push_back(a);

	}
	infile.close();
	return 0;
}
