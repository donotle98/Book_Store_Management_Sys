#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Books.h"
#include "cashRegister.h"
#include "inventory.h"
#include "reportModule.h"
using namespace std;

void mainMenu(Books library[], int bookCount);
void inventoryMenu(Books library[], int bookCount);
void reportMenu(Books library[], int bookCount);
void returnToMainMenu(Books library[], int bookCount);

void CashRegister();
//void lookUpByISBN(std::string isbn, int bookCount, Books listOfBooks[], int& location);
//void lookUpByTitle(std::string title, int bookCount, Books listOfBooks[], int& location);
//void calculateSubtotal(double priceOfBook[], int numberOfBooksinCart);
//void calculateTax(double subtotal);
//void calculateTotal(double taxOfBook, double subtotal);
//void addToQuantity(int n);


int main() {
	static Books library[1024];
	int bookNumber = 51;
	Books().getBookData(library, bookNumber);
	std::string bookTitle = "Rick Riordan";
	for (int i = 0; i < bookNumber; i++) {
		if (library[i].getAuthor() == bookTitle) {
			library[i].print();
		}
	}
	mainMenu(library, bookNumber);
	cout << "End of Program" << endl;
	cout << "---------------" << endl;

	system("break");
	return 0;
}

//The first screen the user will see
void mainMenu(Books library[], int bookCount) {
	int userMainMenuChoice;
	cout << "\t\t\t\t\tSerendipity Booksellers" << endl << "\t\t\t\t\t\tMain Menu" << endl;
	cout << "\t\t\t\t\t1. Cashier Module" << endl;
	cout << "\t\t\t\t\t2. Inventory Database Module" << endl;
	cout << "\t\t\t\t\t3. Report Module" << endl;
	cout << "\t\t\t\t\t4. Exit" << endl;
	cout << "\n\t\t\t\t\tEnter Your Choice (1, 2, 3, 4): " << endl;
	cin >> userMainMenuChoice;
	do {
		switch (userMainMenuChoice) {
		case 1:
			CashRegister();
			exit(0);
		case 2:
			inventoryMenu(library, bookCount);
			exit(0);
		case 3:
			report();
			exit(0);
		case 4:
			cout << "Exiting System" << endl;
			exit(0);
		default:
			std::cout << "Error in choice. Please enter one of the choices listed." << std::endl;
			break;
		}
	} while (userMainMenuChoice != 4);
}
//The inventory module screen
void inventoryMenu(Books library[], int bookCount) {
	int userChoice;
	std::cout << "\t\t\t\t\tSerendipity Booksellers" << std::endl << "\t\t\t\t\tInventory Database" << std::endl;
	std::cout << "\t\t\t\t\t1. Look Up a Book" << std::endl;
	std::cout << "\t\t\t\t\t2. Add a Book" << std::endl;
	std::cout << "\t\t\t\t\t3. Edit a Book's Record" << std::endl;
	std::cout << "\t\t\t\t\t4. Delete a Book" << std::endl;
	std::cout << "\t\t\t\t\t5. Return to Main Menu" << std::endl;
	std::cout << "\n\t\t\t\t\tEnter Your Choice: " << std::endl;
	std::cin >> userChoice;
	switch (userChoice) {
	case 1:
		inventory().lookUpABook();
		break;
	case 2:
		inventory().addABook();
		break;
	case 3:
		inventory().editABooksRecord();
		break;
	case 4:
		inventory().deleteABook();
		break;
	case 5:
		returnToMainMenu(library, bookCount);
	}
}
//The report module screen
void reportMenu(Books library[], int bookCount) {
	int userChoice;
	std::cout << "\t\t\t\t\tSerendipity Booksellers" << std::endl << "\t\t\t\t\t\tReports" << std::endl;
	std::cout << "\t\t\t\t\t1. Inventory Listing" << std::endl;
	std::cout << "\t\t\t\t\t2. Inventory Wholesale Value" << std::endl;
	std::cout << "\t\t\t\t\t3. Inventory Retail Value" << std::endl;
	std::cout << "\t\t\t\t\t4. Listing by Quantity" << std::endl;
	std::cout << "\t\t\t\t\t5. Listing by Cost" << std::endl;
	std::cout << "\t\t\t\t\t6. Listing by Age" << std::endl;
	std::cout << "\t\t\t\t\t7. Return to Main Menu" << std::endl;
	std::cout << "\n\t\t\t\t\tEnter Your Choice: " << std::endl;
	std::cin >> userChoice;
	switch (userChoice) {
	case 1:
		report().inventoryListing();
		break;
	case 2:
		report().inventoryWholeSaleValue();
		break;
	case 3:
		report().inventoryRetailValue();
		break;
	case 4:
		report().listingByQuantity();
		break;
	case 5:
		report().listingByCost();
		break;
	case 6:
		report().listingByAge();
		break;
	case 7:
		returnToMainMenu(library, bookCount);
	}
}
//Function for all modules to return to main menu
void returnToMainMenu(Books library[], int bookCount) {
	mainMenu(library, bookCount);
}
void CashRegister() {
	// Display time
	time_t now = time(0);
	char* dt = ctime(&now);

	std::string isbn, title, userChoice;
	//int quantity;
	bool loop = true;
	std::cout << "\n\nCash Register\n=============\n\n";
		// screen output
		std::cout << "Serendipity Book Sellers" << std::endl << std::endl;
		std::cout << "Date: " << dt << std::endl << std::endl;
		std::cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal" << std::endl;
		std::cout << "-----------------------------------------------------------------------------" << std::endl;
		//std::cout << quantity << "\t"; //display quantity
		std::cout << left << setw(10) << isbn << "\t"; //display ISBN
		std::cout << left << setw(20) << title << "\t"; //display title
		std::cout << std::endl << "Would you like to add another book? (y/n)" << std::endl; // Ask user if they want to continue adding books
		std::cin >> userChoice;
		if (userChoice == "n") {
			loop = false;
		}
}

//// Looking up a book by ISBN
//void lookUpByISBN(std::string isbn, int bookCount, Books listOfBooks[], int& location) {
//	location = -1;
//	for (int i = 0; i < bookCount; i++) {
//		if (listOfBooks[i].isISBN(isbn)) {
//			location = i;
//		}
//	}
//}
//// Looking up a book by Title
//void lookUpByTitle(std::string title, int bookCount, Books listOfBooks[], int& location) {
//	location = -1;
//	for (int i = 0; i < bookCount; i++) {
//		if (listOfBooks[i].isTITLE(title)) {
//			location = i;
//		}
//	}
//}
//// Calculates the sub total of the cart
//// First need to get the prices of all books into an array
//// which can be displayed in the screen
//void calculateSubtotal(double priceOfBook[], int numberOfBooksinCart) {
//	double st;
//	for (int i = 0; i < numberOfBooksinCart; i++) {
//		st += priceOfBook[i];
//		i++;
//	}
//	cashRegister().setSubTotal(st);
//}
//// Calculates the tax of the subtotal of the cart
//void calculateTax(double subtotal) {
//	double taxOfBook, taxRate;
//	taxOfBook = subtotal * taxRate;
//	cashRegister().setTaxofBook(taxOfBook);
//}
//// Calculates the total of the cart (tax + subtotal)
//void calculateTotal(double taxOfBook, double subtotal) {
//	double totalPriceOfBook;
//	totalPriceOfBook = taxOfBook + subtotal;
//	cashRegister().setTotalPrice(totalPriceOfBook);
//}
//// This function needs to be able add the quantity the user enters into the cart
//void addToQuantity(int n) {
//	int numberOfBooksinCart = 0;
//	numberOfBooksinCart += n;
//	cashRegister().setNumberofBooksinCart(numberOfBooksinCart);
//}