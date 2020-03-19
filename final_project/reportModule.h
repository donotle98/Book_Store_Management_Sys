#include "Header.h"
#include "Books.h"
class report : public Books {
private:

public:
	report() {}
	void inventoryListing(Books library[], int bookCount);
	void inventoryWholeSaleValue(Books library[], int bookCount, double total);
	void inventoryRetailValue(Books library[], int bookCount, double total);
	void listingByQuantity(Books library[], int bookCount);
	void listingByCost(Books library[], int bookCount);
	void listingByAge(Books library[], int bookCount);
	//template
	template<class T>
	void selection(T a[], int n, int func)
	{
		if (func == 1) {
			int j, i;
			for (j = 0; j < n - 1; j++) {
				int iMin = j;
				for (i = j + 1; i < n; i++) {
					if (a[i].getStock() > a[iMin].getStock()) {
						iMin = i;
					}
				}
				if (iMin != j) {
					std::swap(a[j], a[iMin]);
				}
			}
		}
		if (func == 2) {
			int j, i;
			for (j = 0; j < n - 1; j++) {
				int iMin = j;
				for (i = j + 1; i < n; i++) {
					if (a[i].getWholesale() > a[iMin].getWholesale()) {
						iMin = i;
					}
				}
				if (iMin != j) {
					std::swap(a[j], a[iMin]);
				}
			}
		}
		if (func == 3) {
			int j, i;
			for (j = 0; j < n - 1; j++) {
				int iMin = j;
				for (i = j + 1; i < n; i++) {
					if (a[i].getDate() < a[iMin].getDate()) {
						iMin = i;
					}
				}
				if (iMin != j) {
					std::swap(a[j], a[iMin]);
				}
			}
		}

	}
};


