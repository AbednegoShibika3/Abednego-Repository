#include <iostream>
#include <vector>
using namespace std;

class Contact {
	public:
		string name;
		string phoneNumber;
		
		Contact(string n, string p) : name(n), phoneNumber(p) {}
};

class AddressBook {
	private:
		vector<Contact> contacts;
		
	public:
		void addContact(string name, string phoneNumber) {
			contacts.push_back(Contact(name, phoneNumber));
		}
		
		void displayContacts() const {
			cout << "Address Book:\n";
			for (const auto& contact : contacts) {
				cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << endl;
			}
		}
};

int main() {
	AddressBook myAddressBook;
	
	myAddressBook.addContact("Abednego Amos", "255_709_456_567");
	myAddressBook.addContact("Ada Moses", "255_618_562_931");
	
	myAddressBook.displayContacts();
	
	return 0;
}