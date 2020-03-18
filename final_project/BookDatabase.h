#pragma once
#include "Books.h"
class BookVector {
private:
	int capacity;
	int current;
public:
	void readText() {
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
	}
};