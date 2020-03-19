/*
Header files for .h
Declares the Functions here
Declares all data members within functions
*/

#include "Header.h"
#include "Books.h"
class inventory : public Books {
private:

public:
	inventory() {}
	// Function to look up a book by either its Title or ISBN
	void lookUpABook(Books library[], int bookCount, std::string title);
	// Function to add a book to the database
	void addABook(Books library[], int bookCount);
	// Function to edit a book within its database, need to ask use which of the attributes they would like to edit
	void editABooksRecord(Books library[], int bookCount, std::string title);
	// Function to delete a book from the database, including subtracting the quantity of the book from the total quantity
	void deleteABook(Books library[], int bookCount, std::string title);
};

