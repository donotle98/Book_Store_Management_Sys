/*
Functions for reportModule files
Calls upon each one in main cpp if selected
Prints out
*/

#include "Header.h"
#include "reportModule.h"
#include "Books.h"
//A list of information on all books in the inventory.
void report::inventoryListing(Books library[], int bookCount) {
	for (int i = 0; i < bookCount; i++)
		library[i].print();
}
//A  list  of  the  wholesale  value  of  all  books  in  the  inventory and the total wholesale value of the inventory. 
void report::inventoryWholeSaleValue(Books library[], int bookCount, double total) {
	double cutiepiesean = 0;
	for (int i = 0; i < bookCount; i++) {
		cutiepiesean += library[i].getWholesale();
		std::cout << library[i].getTitle() << std::endl;
		std::cout << std::right << std::setw(85) << " $" << library[i].getWholesale() << std::endl;
	}

	total = cutiepiesean;
	std::cout << std::setw(85) << "Total of Whole sale values: $" << total;
}
//A  list  of  the  retail  value  of  all  books  in  the  inventory  and the total retail value of the inventory. 
void report::inventoryRetailValue(Books library[], int bookCount, double total) {
	double sadboy = 0;
	for (int i = 0; i < bookCount; i++) {
		sadboy += library[i].getRetail();
		std::cout << library[i].getTitle() << std::endl;
		std::cout << std::right << std::setw(85) << " $" << library[i].getRetail() << std::endl;
	}

	total = sadboy;
	std::cout << std::setw(85) << "Total of Retail values: $" << total;
}
//A list of all books in the inventory sorted by quantity on hand.  The books with the greatest quantity on hand will be listed first. 
void report::listingByQuantity(Books library[], int bookCount) {
	std::cout << "Title: " << std::setw(80) << "Quantity: " << std::endl;
	selection(library, bookCount, 1);
	for (int i = 0; i < bookCount; i++)
		std::cout << library[i].getTitle() << std::endl << std::setw(80) << " " << library[i].getStock() << std::endl;

}
//A list of all books in the inventory, sorted by wholesale cost. The books with the greatest wholesale cost will be listed first. 
void report::listingByCost(Books library[], int bookCount) {
	std::cout << "Title: " << std::setw(80) << "WholeSale: " << std::endl;
	selection(library, bookCount, 2);
	for (int i = 0; i < bookCount; i++)
		std::cout << library[i].getTitle() << std::endl << std::setw(80) << " $" << library[i].getWholesale() << std::endl;
}
//A  list  of  all  books  in  the  inventory,  sorted  by  purchase  date.  The  books that have been in the inventory longest will be listed first. 
void report::listingByAge(Books library[], int bookCount) {
	std::cout << "Title: " << std::setw(80) << "Date: " << std::endl;
	selection(library, bookCount, 3);
	for (int i = 0; i < bookCount; i++)
		std::cout << library[i].getTitle() << std::endl << std::setw(80) << " " << library[i].getDate() << std::endl;
}




