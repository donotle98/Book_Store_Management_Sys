#include "Header.h"
class inventory{
private:

public:
	inventory() {}
	// Function to look up a book by either its Title or ISBN
	void lookUpABook();
	// Function to add a book to the database
	void addABook();
	// Function to edit a book within its database, need to ask use which of the attributes they would like to edit
	void editABooksRecord();
	// Function to delete a book from the database, including subtracting the quantity of the book from the total quantity
	void deleteABook();
};