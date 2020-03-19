#include "Header.h"
#include "Books.h"
#include "cashRegister.h"
#include "reportModule.h"
#include "inventory.h"
using namespace std;

/*
-Friend functions
-Templates //done
-nonfriend operator overloading //done
-polymorhism
-inheritance //done
-classes //done
-exception handling
*/

//Main Menu functions
void mainMenu(Books library[], int bookCount);
void returnToMainMenu(Books library[], int bookCount);


//Inventory functions
void inventoryMenu(Books library[], int bookCount);


//Report functions
void reportMenu(Books library[], int bookCount);


//Cash Register functions
void CashRegister(Books library[], int bookCount);
void subtractFromStockTitle(Books library[], int bookCount, int userAmount, std::string title);
void subtractFromStockISBN(Books library[], int bookCount, int userAmount, std::string isbn);


int main() {
	static Books library[1024]; //Create array of Books
	int bookNumber = 49; //Initialize amount of book space
	mainMenu(library, bookNumber);
	cout << "End of Program" << endl;
	cout << "---------------" << endl;

	system("break");
	return 0;
}

//The first screen the user will see
void mainMenu(Books library[], int bookCount) {
	bool loop = true;
	while (loop) {
		int userMainMenuChoice;
		cout << "\t\t\t\t\tSerendipity Booksellers" << endl << "\t\t\t\t\t\tMain Menu" << endl;
		cout << "\t\t\t\t\t1. Cashier Module" << endl;
		cout << "\t\t\t\t\t2. Inventory Database Module" << endl;
		cout << "\t\t\t\t\t3. Report Module" << endl;
		cout << "\t\t\t\t\t4. Exit" << endl;
		cout << "\n\t\t\t\t\tEnter Your Choice (1, 2, 3, 4): " << endl;
		cin >> userMainMenuChoice;
		bool loop = true;

		switch (userMainMenuChoice) {
		case 1:
			CashRegister(library, bookCount);
			break;
		case 2:
			inventoryMenu(library, bookCount);
			break;
		case 3:
			reportMenu(library, bookCount);
			break;
		case 4:
			cout << "Exiting System" << endl;
			exit(0);
		default:
			std::cout << "Error in choice. Please enter one of the choices listed.\n\n" << std::endl;
			break;
		}
	}


	
}
//The inventory module screen
void inventoryMenu(Books library[], int bookCount) {
	bool loop = true;
	while (loop) {
		std::string userTitle;
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
			std::cout << "Enter the title of the book you would like to search: " << std::endl;
			std::cin.ignore();
			getline(cin, userTitle);
			for (int i = 0; i < bookCount; i++) {
				if (library[i].getTitle() != userTitle) {
					std::cout << "ERROR: You have not entered a book in the database(Capatilization and spelling are important)\n\n" << std::endl;
					break;
				}
			}
			inventory().lookUpABook(library, bookCount, userTitle);
			break;
		case 2:
			inventory().addABook(library, bookCount);
		case 3:
			std::cout << "Enter the title of the book you would like to search: " << std::endl;
			std::cin.ignore();
			getline(cin, userTitle);
			for (int i = 0; i < bookCount; i++) {
				if (library[i].getTitle() != userTitle) {
					std::cout << "ERROR: You have not entered a book in the database(Capatilization and spelling are important)\n\n" << std::endl;
					break;
				}
			}
			inventory().editABooksRecord(library, bookCount, userTitle);
			break;
		case 4:
			std::cout << "Enter the title of the book you would like to delete: " << std::endl;
			std::cin.ignore();
			getline(cin, userTitle);
			for (int i = 0; i < bookCount; i++) {
				if (library[i].getTitle() != userTitle) {
					std::cout << "ERROR: You have not entered a book in the database(Capatilization and spelling are important)\n\n" << std::endl;
					break;
				}
			}
			inventory().deleteABook(library, bookCount, userTitle);
			break;
		case 5:
			returnToMainMenu(library, bookCount);
		default:
			std::cout << "Error in choice. Please enter one of the choices listed.\n\n" << std::endl;
			break;
		}
	}
}
//The report module screen

void reportMenu(Books library[], int bookCount) {
	bool loop = true;
	while (loop) {
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
		std::cout << endl;
		switch (userChoice) {
		case 1:
			report().inventoryListing(library, bookCount);
			break;
		case 2: {
			double total = 0;
			report().inventoryWholeSaleValue(library, bookCount, total);
		}
				break;
		case 3: {
			double total = 0;
			report().inventoryRetailValue(library, bookCount, total);
		}
				break;
		case 4: {
			report().listingByQuantity(library, bookCount);
		}
				break;
		case 5:
			report().listingByCost(library, bookCount);
			break;
		case 6:
			report().listingByAge(library, bookCount);
			break;
		case 7:
			returnToMainMenu(library, bookCount);
		default:
			std::cout << "Error in choice. Please enter one of the choices listed.\n\n" << std::endl;
			break;
		}
	}
}


//Function for all modules to return to main menu
void returnToMainMenu(Books library[], int bookCount) {
	mainMenu(library, bookCount);
}
//Function to call upon the cash register
void CashRegister(Books library[], int bookCount) {
	// Display time
	time_t now = time(0);
	char* dt = ctime(&now);

	cashRegister cartCart[1024];

	std::string isbn, title;
	double price = 0;
	int userChoice;
	int quantityOfBooks;
	double taxrate = .0975;
	double totalPriceOfBooks = 0;
	char ch = 0;
	int counter = 0;
	int stockATM = 0;


	std::cout << "\n\nCash Register\n=============\n\n";

	

	bool loop = true;
	while (loop) {
		//Ask user for isbn or title
		std::cout << "Would you like to purchase a book by..." << std::endl;
		std::cout << "1.Title\n" << "2.ISBN\n" << "(enter 1 or 2)\n" << std::endl;
		std::cin >> userChoice;
		if (userChoice != 1 && userChoice != 2) {
			std::cout << "ERROR: INCORRECT INPUT" << std::endl;
			break;
		}
		std::cout << "" << std::endl;
		//If user selects title
		if (userChoice == 1) {
			std::cout << "List of books in stock" << std::endl;
			std::cout << "=============================" << std::endl;
			//Print out list of book titles
			for (int i = 0; i < bookCount; i++) {
				std::cout << library[i].getTitle() << std::endl;
			}
			std::cout << "\n\nPlease enter the Title you wish to purchase:" << std::endl;
			cin.ignore();
			getline(cin, title); //User input for title of book
			for (int i = 0; i < bookCount; i++) {
				//Grab the isbn, price, and stock
				if (library[i].getTitle() == title) {
					price = library[i].getRetail();
					isbn = library[i].getISBN();
					stockATM = library[i].getStock();
					std::cout << "Price of Book: $" << price << std::endl; //display the price
					std::cout << "Amount in Stock: " << stockATM << std::endl; //display amount of stock
				}
			}
			double subTotal = 0; //dollar amount of the book
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantityOfBooks;

			subtractFromStockTitle(library, bookCount, quantityOfBooks, title); //Function to subtract the amount the user wants from the inventory

			subTotal = quantityOfBooks * price; //grab the dollar amount of how many books user is buying
			totalPriceOfBooks += subTotal; //add subtotal to the subtotal cart amount

			cartCart[counter].setpriceOfBook(price);
			cartCart[counter].setnameOfBook(title);
			cartCart[counter].setisbnOfBook(isbn);
			cartCart[counter].setquantityOfBook(quantityOfBooks);
			cartCart[counter].setTotalPrice(totalPriceOfBooks);
			counter++;

		}
		else if(userChoice == 2){
			std::string titleOfISBN;
			std::cout << "List  of ISBN's in our database" << std::endl;
			std::cout << "===============================" << std::endl;
			//print list of isbn and titles
			for (int i = 0; i < bookCount; i++) {
				std::cout << "ISBN: " << library[i].getISBN() << std::endl;
				std::cout << "Title: " << library[i].getTitle() << std::endl;
				std::cout << "-----------------" << std::endl;
			}
			std::cout << "\n\nPlease enter the ISBN you wish to purchase:" << std::endl;
			cin.ignore();
			getline(cin, isbn); //User input for isbn of book
			for (int i = 0; i < bookCount; i++) {
				//pull from library price, title, and stock
				if (library[i].getISBN() == isbn) {
					price = library[i].getRetail();
					titleOfISBN = library[i].getTitle();
					stockATM = library[i].getStock();
					std::cout << "Title of book: " << titleOfISBN << std::endl;
					std::cout << "Price of book: $" << price << std::endl;
					std::cout << "Amount in Stock: " << stockATM << std::endl;
				}
			}
			double subTotal = 0;
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantityOfBooks;
			subTotal += (quantityOfBooks * price);

			subtractFromStockISBN(library, bookCount, quantityOfBooks, isbn); //Function to subtract the amount the user wants from the inventory

			totalPriceOfBooks += subTotal;
			cartCart[counter].setpriceOfBook(price);
			cartCart[counter].setnameOfBook(titleOfISBN);
			cartCart[counter].setisbnOfBook(isbn);
			cartCart[counter].setquantityOfBook(quantityOfBooks);
			cartCart[counter].setTotalPrice(totalPriceOfBooks);
			counter++;
		}
		std::cout << "\nWould you like to add another book? (y/n)" << std::endl;
		std::string longestTitle;
		std::cin >> ch;
		for (int i = 0; i < counter; i++) {
			for (int j = 1; j < counter + 1; j++) {
				if (cartCart[i] > cartCart[j]) {
					longestTitle = cartCart[i].getnameOfBook();
				}
				else {
					longestTitle = cartCart[j].getnameOfBook();
				}
			}
		}
		if (ch == 'n') {
			int sizeOfLT = longestTitle.length();
			double taxOfBook = taxrate * totalPriceOfBooks;
			std::cout << "\n\nSerendipity Book Sellers" << std::endl << std::endl;
			std::cout << "Date: " << dt;
			std::cout << "Qty\t";
			std::cout << std::left << std::setw(10) << "ISBN" << "\t";
			std::cout << std::left << std::setw(sizeOfLT + 15) << "Title";
			std::cout << "Price" << "\t";
			std::cout << std::left << "Total" << std::endl;
			std::cout << "--------------------------------------------------------------------------------------" << std::endl;
			for (int i = 0; i < counter; i++) {
				cartCart[i].printCart(sizeOfLT);
			}
			std::cout << "Subtotal: $";
			printf("%.2f", totalPriceOfBooks);
			std::cout << std::endl;
			std::cout << "Tax: $";
			printf("%.2f", taxOfBook);
			std::cout << std::endl;
			std::cout << "Total: $";
			printf("%.2f", totalPriceOfBooks + taxOfBook);
			std::cout << std::endl << std::endl << std::endl;
			loop = false;
		}
	}
}

void subtractFromStockTitle(Books library[], int bookCount, int userAmount, std::string title) {
	int updatedStock;
	int initStock;
	for (int i = 0; i < bookCount; i++) {
		if (library[i].getTitle() == title) {
			initStock = library[i].getStock();
			updatedStock = (initStock - userAmount);
			library[i].setStock(updatedStock);
			library[i].print();
		}
	}
}
void subtractFromStockISBN(Books library[], int bookCount, int userAmount, std::string isbn) {
	int updatedStock;
	int initStock;
	for (int i = 0; i < bookCount; i++) {
		if (library[i].getISBN() == isbn) {
			initStock = library[i].getStock();
			updatedStock = (initStock - userAmount);
			library[i].setStock(updatedStock);
			library[i].print();
		}
	}
}