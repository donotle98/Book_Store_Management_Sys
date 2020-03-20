/*
Declarations of all functions in this
Calls upon these in main cpp
*/

#include "Header.h"

class cashRegister {
private:
	double priceOfBook = 0;
	std::string nameOfBook;
	std::string isbnOfBook;
	int quantityOfBook = 0;
	int numberIDofBook = 0;
	double taxRate = 0;
	double taxOfBook = 0;
	double subtotal = 0;
	double totalPriceOfBooks = 0;
public:
	cashRegister();
	cashRegister(double price, std::string title, std::string isbn, int quantity, double totalPriceOfBooks);
	void setCart(double price, std::string title, std::string isbn, int quantity, double total);

	//Accessors
	void setpriceOfBook(double price);
	void setnameOfBook(std::string name);
	void setisbnOfBook(std::string isbn);
	void setquantityOfBook(int quantity);
	double getpriceOfBook();
	std::string getnameOfBook();
	std::string getisbnOfBook();
	int getquantityOfBook();

	void setTaxRate(double t);
	double getTaxRate();
	void setSubTotal(double st);
	double getSubTotal();
	void setTaxofBook(double tofb);
	double getTaxofBook();
	void setTotalPrice(double price);
	double getTotalPrice();
	void setNumberofBooksinCart(int n);
	int getNumberofBooksinCart();
	void printCart(int longest);
	//Nonfriend operator overloading for the compare operator
	bool operator < (const cashRegister &);
	bool operator > (const cashRegister &);

};