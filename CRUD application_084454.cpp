#include <iostream> 
#include <vector>
#include <string>

using namespace std;

struct item {
int id;
string name;
double price;

void display() const{cout << "ID:" << ", Name: " << name <<", Price: $" << price << endl;
}
};

void createItem(vector<item>& items);
void readItems(const vector<item>& items);
void updateItem(vector<item>& items);
void deleteItem(vector<item>& items);

int main() {
	vector<item> items;
	int choice;
	
	do {
		cout << "\n-- CRUD operations Menu --\n";
		cout << "1. Create Item\n";
		cout << "2. Read Items\n";
		cout << "3. Update Item\n";
		cout << "4. Delete Item\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				createItem(items);
				break;
			case 2:
			    readItems(items);
				break;
			case 3:
			    updateItem(items);
				break;
			case 4:
			    deleteItem(items);
				break;
			case 5:
			    cout << "Exiting the program.\n";
				break;
			default:
			    cout << "Invalid choice. Please try again.\n";					
		}
	} while (choice != 5);
	return 0;
}

void createItem(vector<item>& items){
item newItem;

cout << "\nEnter Item ID:";
cin >> newItem.id;
cin.ignore();
cout << "Ener Item Name:";
getline(cin, newItem.name);
cout << "Enter Item Price:";
cin >> newItem.price;

items.push_back(newItem);
cout << "Item created sucessfully!\n";
}

void readItems(const vector<item>& items){
	if (items.empty()) {cout << "\nNo items found.\n";
	} else {
		cout << "\n--- Item List ---\n";
		for (const auto& item : items) {item.display();
		}
	}
}

void updateItem(vector<item>& items) {
	int id;
	cout << "\nEnter Item ID to update:";
	cin >> id;
	
	for (auto& item : items) {
		if (item.id == id) {
			cin.ignore();
			cout << "Enter new Item Name:";
			getline(cin, item.name);
			cout << "Enter new Item Price:";
			cin >> item.price;
			cout << "Item updated successfully!\n";
			return;	
		}
	}
	
	cout << "Item with ID " << id << "not found.\n";
}


void deleteItem(vector<item>& iems) {
	int id;
	cout << "\nEnter Item ID to delete:";
	cin >> id;
	
	for (auto it = iems.begin(); it != iems.end(); ++it) {
		if (it->id == id) {
			iems.erase(it);
			cout << "Item deleted successsfully!\n";
			return;
		}
	}
	
	cout << "Item with ID " << id << "not found.\n";
}