#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
void bookInfoScreen();

int main() {
	int userMainMenuChoice;
	// I realize there is a crap ton of tabs, but this is just for now.....
	cout << "\t\t\t\t\tSerendipity Booksellers" << endl << "\t\t\t\t\t\tMain Menu" << endl;
	cout << "\t\t\t\t\t1. Cashier Module" << endl;
	cout << "\t\t\t\t\t2. Inventory Database Module" << endl;
	cout << "\t\t\t\t\t3. Report Module" << endl;
	cout << "\t\t\t\t\t4. Exit" << endl;
	cout << "\n\t\t\t\t\tEnter Your Choice: " << endl;
	cin >> userMainMenuChoice;

	switch (userMainMenuChoice) {
	case 1:
		cout << "\n\n\nCashier Screen" << endl;
		bookInfoScreen();
		exit(0);
	case 2:
		cout << "Inventory Main Screen" << endl;
		exit(0);
	case 3:
		cout << "Book Information Screen" << endl;
		exit(0);
	case 4:
		cout << "Exiting System" << endl;
		exit(0);
	}

	system("break");
	return 0;
}

void bookInfoScreen() {
	cout << "\t\t\t\t\tSerendipity Booksellers" << endl;
	cout << "\t\t\t\t\tBook Information" << endl;
	cout << "\t\t\t\tISBN: " << endl;
	cout << "\t\t\t\tTitle: " << endl;
	cout << "\t\t\t\tAuthor: " << endl;
	cout << "\t\t\t\tPublisher: " << endl;
	cout << "\t\t\t\tDate Added: " << endl;
	cout << "\t\t\t\tQuantity-On-Hand: " << endl;
	cout << "\t\t\t\tWholesale Cost: " << endl;
	cout << "\t\t\t\tRetail Price: " << endl;
}