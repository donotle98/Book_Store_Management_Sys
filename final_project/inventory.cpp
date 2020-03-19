#include "Header.h"
#include "inventory.h"


void inventory::lookUpABook(Books library[], int bookCount, std::string title) {
	for (int i = 0; i < bookCount; i++) {
		if (library[i].getTitle() == title) {
			library[i].print();
		}
	}
}
// Function to add a book to the database
void inventory::addABook(Books library[], int bookCount) {

}
// Function to edit a book within its database, need to ask use which of the attributes they would like to edit
void inventory::editABooksRecord(Books library[], int bookCount, std::string title) {
	std::string userChoice;
	for (int i = 0; i < bookCount; i++) {
		if (library[i].getTitle() == title) {
			library[i].print();
		}
	}
	std::cout << "What would you like to edit?" << std::endl;
	std::cout << "(Enter ISBN, Title, Author, Publisher, Date, Stock, Quantity, Wholesale, Retail)" << std::endl;
	std::cin >> userChoice;
	if (userChoice == "Title") {
		std::string newTitle;
		std::cout << "What new title would you like to change it to?" << std::endl;
		std::cin.ignore();
		getline(std::cin, newTitle);
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setTitle(newTitle);
				library[i].print();
			}
		}
	}
	else if (userChoice == "ISBN") {
		std::string newISBN;
		std::cout << "What new ISBN would you like to change it to?" << std::endl;
		std::cin.ignore();
		getline(std::cin, newISBN);
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setISBN(newISBN);
				library[i].print();
			}
		}
	}
	else if (userChoice == "Author") {
		std::string newAuthor;
		std::cout << "What new Author would you like to change it to?" << std::endl;
		std::cin.ignore();
		getline(std::cin, newAuthor); 
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setAuthor(newAuthor);
				library[i].print();
			}
		}
	}
	else if (userChoice == "Publisher") {
		std::string newPublisher;
		std::cout << "What new Publisher would you like to change it to?" << std::endl;
		std::cin.ignore();
		getline(std::cin, newPublisher); 
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setPublisher(newPublisher);
				library[i].print();
			}
		}
	}
	else if (userChoice == "Date") {
		int newDate;
		std::cout << "What new Date would you like to change it to?" << std::endl;
		std::cin.ignore();
		std::cin >> newDate;
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setDate(newDate);
				library[i].print();
			}
		}
	}
	else if (userChoice == "Stock") {
		int newStock;
		std::cout << "What new Stock would you like to change it to?" << std::endl;
		std::cin.ignore();
		std::cin >> newStock;
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setStock(newStock);
				library[i].print();
			}
		}
	}
	else if (userChoice == "Wholesale") {
		double newWholesale;
		std::cout << "What new Wholesale would you like to change it to?" << std::endl;
		std::cin.ignore();
		std::cin >> newWholesale;
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setWholesale(newWholesale);
				library[i].print();
			}
		}
	}
	else if (userChoice == "Retail") {
		double newRetail;
		std::cout << "What new Retail would you like to change it to?" << std::endl;
		std::cin.ignore();
		std::cin >> newRetail;
		for (int i = 0; i < bookCount; i++) {
			if (library[i].getTitle() == title) {
				library[i].setRetail(newRetail);
				library[i].print();
			}
		}
	}
}
// Function to delete a book from the database, including subtracting the quantity of the book from the total quantity
void inventory::deleteABook(Books library[], int bookCount, std::string title) {

}