#include <string>
#include <iostream>
#include <iomanip>
#include "Books.h"
#include "cashRegister.h"
#include "inventory.h"
#include "reportModule.h"
using namespace std;

void mainMenu();

int main() {
	mainMenu();

	cout << "End of Program" << endl;
	cout << "---------------" << endl;
	system("break");
	return 0;
}

void mainMenu() {
	int userMainMenuChoice;
	cout << "\t\t\t\t\tSerendipity Booksellers" << endl << "\t\t\t\t\t\tMain Menu" << endl;
	cout << "\t\t\t\t\t1. Cashier Module" << endl;
	cout << "\t\t\t\t\t2. Inventory Database Module" << endl;
	cout << "\t\t\t\t\t3. Report Module" << endl;
	cout << "\t\t\t\t\t4. Exit" << endl;
	cout << "\n\t\t\t\t\tEnter Your Choice: " << endl;
	cin >> userMainMenuChoice;

	switch (userMainMenuChoice) {
	case 1:
		cashRegister();
		exit(0);
	case 2:
		inventory();
		exit(0);
	case 3:
		report();
		exit(0);
	case 4:
		cout << "Exiting System" << endl;
		exit(0);
	}

}

