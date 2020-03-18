#pragma once
#include "Books.h"
#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>

class cashRegister {
private:
	double priceOfBook;
	std::string nameOfBook;
	int numberOfBooksinCart;
	int numberIDofBook;
	double taxRate;
	double taxOfBook;
	double subtotal;
	double totalPriceOfBook;
public:
	cashRegister() {
		// Display time
		time_t now = time(0);
		char* dt = ctime(&now);

		std::string isbn, title, userChoice;
		int quantity;
		bool loop = true;

		//Start of the users cart loop
		while (loop) {
			int choice;
			std::cout << "Would you like to look up a book by:" << std::endl << "\t1.Title " << std::endl << "\t2.ISBN\n(Enter 1 or 2): " << std::endl;
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "Enter the ISBN: " << std::endl;
				std::cin >> isbn;

				// Need function to look up book by ISBN and add to the cart
				

				std::cout << "Quantity: " << std::endl;
				std::cin >> quantity;
				addToQuantity(quantity); // Add the amount of books to the cart
			}
			else if (choice == 2) {
				std::cout << "Enter the Title: " << std::endl;
				std::cin >> title;

				// Need function to look up book by Title and add to the cart


				std::cout << "Quantity: " << std::endl;
				std::cin >> quantity;
				addToQuantity(quantity); // Add the amount of books to the cart
			}

			// screen output
			std::cout << "Serendipity Book Sellers" << std::endl << std::endl;
			std::cout << "Date: " << dt << std::endl << std::endl;
			std::cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal" << std::endl;
			std::cout << "-----------------------------------------------------------------------------" << std::endl;
			std::cout << quantity << "\t"; //display quantity
			std::cout << left << setw(10) << isbn << "\t"; //display ISBN
			std::cout << left << setw(20) << title << "\t"; //display title
			std::cout << std::endl <<"Would you like to add another book? (y/n)" << std::endl; // Ask user if they want to continue adding books
			std::cin >> userChoice;
			if (userChoice == "n") {
				loop = false;
			}
		}
		std::cout << std::endl << "\t\tSubtotal: " << getSubTotal() << std::endl;
		std::cout << "\t\tTax: " << getTaxofBook() << std::endl;
		std::cout << "\t\tTotal: " << getTotalPrice() << std::endl;

	}

	//Accessors
	void setSubTotal(double st) {
		subtotal = st;
	}
	double getSubTotal() {
		return subtotal;
	}
	void setTaxofBook(double tofb) {
		taxOfBook = tofb;
	}
	double getTaxofBook() {
		return taxOfBook;
	}
	void setTotalPrice(double price) {
		totalPriceOfBook = price;
	}
	double getTotalPrice() {
		return totalPriceOfBook;
	}
	void setNumberofBooksinCart(int n) {
		numberOfBooksinCart = n;
	}
	int getNumberofBooksinCart() {
		return numberOfBooksinCart;
	}


	// Calculates the sub total of the cart
	// First need to get the prices of all books into an array
	// which can be displayed in the screen
	void calculateSubtotal(double priceOfBook[], int numberOfBooksinCart) {
		double st;
		for (int i = 0; i < numberOfBooksinCart; i++) {
			st += priceOfBook[i];
			i++;
		}
		setSubTotal(st);
	}
	// Calculates the tax of the subtotal of the cart
	void calculateTax(double subtotal) {
		taxOfBook = subtotal * taxRate;
		setTaxofBook(taxOfBook);
	}
	// Calculates the total of the cart (tax + subtotal)
	void calculateTotal(double taxOfBook, double subtotal) {
		totalPriceOfBook = taxOfBook + subtotal;
		setTotalPrice(totalPriceOfBook);
	}
	// This function needs to be able add the quantity the user enters into the cart
	void addToQuantity(int n) {
		numberOfBooksinCart += n;
		setNumberofBooksinCart(numberOfBooksinCart);
	}
	// Looking up a book by ISBN
	void lookUpByISBN(std::string isbn, int bookCount, Books listOfBooks[], int& location) {
		location = -1;
		for (int i = 0; i < bookCount; i++) {
			if (listOfBooks[i].isISBN(isbn)) {
				location = i;
			}
		}
	}
	// Looking up a book by Title
	void lookUpByTitle(std::string title, int bookCount, Books listOfBooks[], int& location) {
		location = -1;
		for (int i = 0; i < bookCount; i++) {
			if (listOfBooks[i].isTITLE(title)) {
				location = i;
			}
		}
	}
};