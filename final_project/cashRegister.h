#include "Header.h"

class cashRegister {
private:
	double priceOfBook;
	std::string nameOfBook;
	std::string isbnOfBook;
	int quantityOfBook;
	int numberIDofBook;
	double taxRate;
	double taxOfBook;
	double subtotal;
	double totalPriceOfBooks;
public:
	cashRegister() {}
	cashRegister(double price, std::string title, std::string isbn, int quantity, double totalPriceOfBooks);
	void setCart(double price, std::string title, std::string isbn, int quantity, double t);
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
	void printCart();
};