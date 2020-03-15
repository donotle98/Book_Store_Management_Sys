#pragma once
#include "inventory.h"
#include "cashRegister.h"
#include "Books.h"
#include <iostream>
#include <string>
#include <iomanip>

class report {
private:

public:
	report() {
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
			inventoryListing();
		case 2:
			inventoryWholeSaleValue();
		case 3:
			inventoryRetailValue();
		case 4:
			listingByQuantity();
		case 5:
			listingByCost();
		case 6:
			listingByAge();
		case 7:
			returnToMainMenu();
		}
	}
	//A list of information on all books in the inventory.
	void inventoryListing() {

	}
	//A  list  of  the  wholesale  value  of  all  books  in  the  inventory and the total wholesale value of the inventory. 
	void inventoryWholeSaleValue() {

	}
	//A  list  of  the  retail  value  of  all  books  in  the  inventory  and the total retail value of the inventory. 
	void inventoryRetailValue() {

	}
	//A list of all books in the inventory sorted by quantity on hand.  The books with the greatest quantity on hand will be listed first. 
	void listingByQuantity() {

	}
	//A list of all books in the inventory, sorted by wholesale cost. The books with the greatest wholesale cost will be listed first. 
	void listingByCost() {

	}
	//A  list  of  all  books  in  the  inventory,  sorted  by  purchase  date.  The  books that have been in the inventory longest will be listed first. 
	void listingByAge() {

	}
	void returnToMainMenu() {

	}


};