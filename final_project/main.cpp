#include "Header.h"
#include "Books.h"
#include "cashRegister.h"
#include "reportModule.h"
#include "inventory.h"
using namespace std;

void mainMenu(Books library[], int bookCount);

//Inventory functions
void inventoryMenu(Books library[], int bookCount);
void lookUpABook(Books library[], int bookCount);


//Report functions
void reportMenu(Books library[], int bookCount);
void returnToMainMenu(Books library[], int bookCount);


//Cash Register functions
void CashRegister(Books library[], int bookCount);
void cart(vector<cashRegister> cartBooks, double price, std::string isbn, std::string title, int quantity);


int main() {
	static Books library[1024];
	int bookNumber = 51;
	Books().getBookData(library, bookNumber);
	for (int i = 0; i < bookNumber; i++) {
		library[i].print();
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
			CashRegister(library, bookCount);
			exit(0);
		case 2:
			inventoryMenu(library, bookCount);
			exit(0);
		case 3:
			reportMenu(library, bookCount);
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
		lookUpABook(library, bookCount);
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


//Function to call upon the cash register
void CashRegister(Books library[], int bookCount) {
	// Display time
	time_t now = time(0);
	char* dt = ctime(&now);

	vector<cashRegister> cartBooks;

	std::string isbn, title;
	double price = 0;
	int userChoice;
	int quantityOfBooks;
	double taxrate = .0975;
	double totalPriceOfBooks = 0;
	char ch = 0;
	int counter = 0;


	std::cout << "\n\nCash Register\n=============\n\n";


	//std::cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal" << std::endl;
	//std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	bool loop = true;
	while (loop) {
		std::cout << "Would you like to purchase a book by..." << std::endl;
		std::cout << "1.Title\n" << "2.ISBN\n" << "(enter 1 or 2)\n" << std::endl;
		std::cin >> userChoice;
		std::cout << "" << std::endl;
		if (userChoice == 1) {
			std::cout << "List of books in stock" << std::endl;
			std::cout << "=============================" << std::endl;
			for (int i = 0; i < bookCount; i++) {
				std::cout << library[i].getTitle() << std::endl;
			}
			std::cout << "\n\nPlease enter the Title you wish to purchase:" << std::endl;
			cin.ignore();
			getline(cin, title);
			for (int i = 0; i < bookCount; i++) {
				if (library[i].getTitle() == title) {
					price = library[i].getRetail();
					isbn = library[i].getISBN();
					std::cout << "Price of Book: $" << price << std::endl;
				}
			}
			double subTotal = 0;
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantityOfBooks;
			subTotal = quantityOfBooks * price;
			totalPriceOfBooks += subTotal;
			//std::cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal" << std::endl;
			//std::cout << "-----------------------------------------------------------------------------" << std::endl;
			cashRegister a = cashRegister(price, title, isbn, quantityOfBooks, subTotal);
			cartBooks.push_back(a);

		}
		else if(userChoice == 2){
			std::string titleOfISBN;
			std::cout << "List  of ISBN's in our database" << std::endl;
			std::cout << "===============================" << std::endl;
			for (int i = 0; i < bookCount; i++) {
				std::cout << "ISBN: " << library[i].getISBN() << std::endl;
				std::cout << "Title: " << library[i].getTitle() << std::endl;
				std::cout << "-----------------" << std::endl;
			}
			std::cout << "\n\nPlease enter the ISBN you wish to purchase:" << std::endl;
			cin.ignore();
			getline(cin, isbn);
			for (int i = 0; i < bookCount; i++) {
				if (library[i].getISBN() == isbn) {
					price = library[i].getRetail();
					titleOfISBN = library[i].getTitle();
					std::cout << "Title of book: " << titleOfISBN << std::endl;
					std::cout << "Price of book: $" << price << std::endl;
				}
			}
			double subTotal = 0;
			std::cout << "How many would you like to purchase?" << std::endl;
			std::cin >> quantityOfBooks;
			subTotal += (quantityOfBooks * price);
			totalPriceOfBooks += subTotal;
			cashRegister a = cashRegister(price, titleOfISBN, isbn, quantityOfBooks, subTotal);
			cartBooks.push_back(a);
		}
		std::cout << "\nWould you like to add another book? (y/n)" << std::endl;
		std::cin >> ch;
		if (ch == 'n') {
			double taxOfBook = taxrate * totalPriceOfBooks;
			std::cout << "Serendipity Book Sellers" << std::endl << std::endl;
			std::cout << "Date: " << dt << std::endl << std::endl;
			std::cout << "\n\nQty\tISBN\t\tTitle\t\t\t\t\tPrice\t\t\t\Total" << std::endl;
			std::cout << "--------------------------------------------------------------------------------------" << std::endl;
			for (int i = 0; i < cartBooks.size(); i++) {
				cartBooks[i].printCart();
				std::cout << "" << std::endl;
			}
			std::cout << "Subtotal: $" << setprecision(7) << totalPriceOfBooks << std::endl;
			std::cout << "Tax: $" << setprecision(7) << taxOfBook << std::endl;
			std::cout << "Total: $" << setprecision(9) << totalPriceOfBooks + taxOfBook << std::endl;
			loop = false;
		}
		else {
			counter++;
		}

	}


}
//Function for cash register cart
//void cart(vector<cashRegister> cartBooks, double price, std::string isbn, std::string title, int quantity) {
//	cashRegister a = cashRegister(price, title, isbn, quantity);
//	cartBooks.push_back(a);
//}


void lookUpABook(Books library[], int bookCount) {
	std::string userTitle;
	std::cout << "Enter the title of the book you would like to search: " << std::endl;
	cin.ignore();
	getline(cin, userTitle);
	for (int i = 0; i < bookCount; i++) {
		if (library[i].getTitle() == userTitle) {
			library[i].print();
		}
	}
}