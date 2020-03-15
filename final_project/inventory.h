#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "Books.h"

class inventory : public Books {
private:

public:
	inventory() {
		int userChoice;
		std::cout << "\t\t\t\t\tSerendipity Booksellers" << std::endl << "\t\t\t\t\tInventory Database" << std::endl;
		std::cout << "\t\t\t\t\t1. Look Up a Book" << std::endl;
		std::cout << "\t\t\t\t\t2. Add a Book" << std::endl;
		std::cout << "\t\t\t\t\t3. Edit a Book’s Record" << std::endl;
		std::cout << "\t\t\t\t\t4. Delete a Book" << std::endl;
		std::cout << "\t\t\t\t\t5. Return to Main Menu" << std::endl;
		std::cout << "\n\t\t\t\t\tEnter Your Choice: " << std::endl;
		std::cin >> userChoice;
		switch (userChoice) {
			case 1:
				lookUpABook();
			case 2:
				addABook();
			case 3:
				editABooksRecord();
			case 4:
				deleteABook();
			case 5:
				returnToMainMenu();
		}
	}
	void lookUpABook() {

	}
	void addABook() {

	}
	void editABooksRecord() {

	}
	void deleteABook() {

	}
	void returnToMainMenu() {

	}
};
