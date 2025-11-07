#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Product {
	string name;
	float price;
	int quantity;
	int numSold;
};

// TODO: Declare all function prototypes
void viewInventory(const vector<Product>& itemList);
void displayMenu();
void addProduct(vector<Product>&);
void removeProduct(vector<Product>&);
void restockProduct(vector<Product>&, float& storeBal);
void handlePurchase(vector<Product>&, float& storeBal, float& revenue);
void endOfDayReport(const vector<Product>&, float storeBal, float revenue);

int main() {
	// TODO: Declare variables for manager name, store name, and store balance
	string managerName, storeName;
	float storeBal;
	float revenue = 0.00;



	// TODO: Get input and print welcome message
	cout << "Hello and welcome to Market Manager Pro!" << endl;
	cout << "Enter Manager Name: ";
	cin >> managerName;
	cout << "Enter Store Name: ";
	cin >> storeName;
	cout << "Enter Opening Balance: ";
	cin >> storeBal;

	cout << managerName << ", welcome to " << storeName << "!" << endl;
	// TODO: Initialize vector<Product> with some starting items
	vector<Product> itemList = {{"Apple", 3.00, 3, 0}, {"Pear", 4.50, 5, 0}, {"Honey", 7.00, 5, 0}};
	// struct Product apple = {"Apple", 3.00, 3};
	// struct Product pear = {"Pear", 4.50, 5};
	// struct Product honey = {"Honey", 7.00, 5};

	srand(time(0));
	int choice;

	do {
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			viewInventory(itemList);
			break;
		case 2:
			addProduct(itemList);
			break;
		case 3:
			removeProduct(itemList);
			break;
		case 4:
			restockProduct(itemList, storeBal);
			break;
		case 5:
			handlePurchase(itemList, storeBal, revenue);
			break;
		case 6:
			endOfDayReport(itemList, storeBal, revenue);
			break;
		}

		for (auto& p : itemList) {
			if (p.quantity < 5) {
				cout << "Low stock alert!" << endl;
			}
		}
		if (storeBal < 100) {
			cout << "Low funds warning!" << endl;
		}


	} while (choice != 7);

	return 0;
}

// TODO: Implement all the following functions step by step:
// 1. displayMenu()
void displayMenu() {
	cout << "~~~~~~~~~~ MARKET MANAGER MENU ~~~~~~~~~~~" << endl;
	cout << "1. View Inventory" << endl;
	cout << "2. Add Product" << endl;
	cout << "3. Remove Product" << endl;
	cout << "4. Restock Product" << endl;
	cout << "5. Handle Customer Purchase" << endl;
	cout << "6. End Day Report" << endl;
	cout << "7. Exit" << endl;
}
// 2. viewInventory()
void viewInventory(const vector<Product>& itemList) {
	for (auto& p : itemList) {
		cout << "Name: " << p.name << ", Price: $" << p.price << ", Quantity " << p.quantity << endl;
	}
}
// 3. addProduct()
void addProduct(vector<Product>& itemList) {
	struct Product temp;
	cout << "Enter product name: ";
	cin >> temp.name;
	cout << "Enter price: ";
	cin >> temp.price;
	cout << "Enter quantity: ";
	cin >> temp.quantity;
	temp.numSold = 0;
	itemList.push_back(temp);
}
// 4. removeProduct()
void removeProduct(vector<Product>& itemList) {
	string temp;
	cout << "Type name of item you wish to remove (case sensitive): ";
	cin >> temp;
	for (int i = 0; i < itemList.size(); i++) {
		for (auto& p : itemList) {
			if (p.name == temp) {
				itemList.erase(itemList.begin() + i);
			}
		}
	} //NOTE: THIS IS BROKEN. IT DOES NOT WORK CORRECTLY. I AM CALLING MYSELF OUT THE REMOVE PRODUCT IS NOT WORKING.


}
// 5. restockProduct()
void restockProduct(vector<Product>& itemList, float& storeBal) {
	string temp;
	int temp2;
	cout << "Type name of product you wish to restock (case sensitive): ";
	cin >> temp;
	cout << "How many would you like to stock: ";
	cin >> temp2;
	for (auto& p : itemList) {
		if (p.name == temp && p.price * temp2 < storeBal) {
			p.quantity += temp2;
			storeBal -= p.price * temp2;
		}
		else {
			cout << "This is not possible.";
		}
	}
}
// 6. handlePurchase()
void handlePurchase(vector<Product>& itemList, float& storeBal, float& revenue) {
	int randomNum = rand() % 2;
	int randomNum2 = rand() % 7;
	string temp;
	cout << "A guest wants to buy ";
	for (auto& p : itemList) {
		if (randomNum == 1) {
			cout << randomNum2 << " apples.";
			cout << endl << "Would you like to accept their purchase (y/n): ";
			cin >> temp;
			if (temp == "y" && p.name == "Apple" && randomNum2 <= p.quantity) {
				p.quantity -= randomNum2;
				storeBal += p.price * randomNum2;
				p.numSold += randomNum2;
				revenue += p.price * randomNum2;
				break;
			}
			else {
				cout << "This is not possible." << endl;
				break;
			}
		}

		else if (randomNum == 2) {
			cout << randomNum2 << " pears.";
			cout << endl << "Would you like to accept their purchase (y/n): ";
			cin >> temp;
			if (temp == "y" && p.name == "Pear" && randomNum2 <= p.quantity) {
				p.quantity -= randomNum2;
				storeBal += p.price * randomNum2;
				p.numSold += randomNum2;
				revenue += p.price * randomNum2;
				break;
			}
			else {
				cout << "This is not possible." << endl;
				break;
			}
		}
		else {
			cout << randomNum2 << " honey.";
			cout << endl << "Would you like to accept their purchase (y/n): ";
			cin >> temp;
			if (temp == "y" && p.name == "Honey" && randomNum2 <= p.quantity) {
				p.quantity -= randomNum2;
				storeBal += p.price * randomNum2;
				p.numSold += randomNum2;
				revenue += p.price * randomNum2;
				break;
			}
			else {
				cout << "This is not possible." << endl;
				break;
			}

		}
	}




}
// 7. endOfDayReport()
void endOfDayReport(const vector<Product>& itemList, float storeBalance, float revenue) {
	cout << "====== END OF DAY REPORT ======" << endl;
	for (auto& p : itemList) {
		cout << "Name: " << p.name << ", Number Sold: " << p.numSold << ", Quantity " << p.quantity << endl;
	}
	cout << "Revenue: " << revenue << endl << "Store Balance: " << storeBalance << endl;
}