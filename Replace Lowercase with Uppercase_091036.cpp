#include <iostream>
#include <cctype>
using namespace std;

void replaceLowerWithUpper(string &str) {
	for (char &c : str)
	c = toupper(c);
}

int main() {
	string str;
	
	cout<<"Enter a string: ";
	getline(cin,str);
	
	replaceLowerWithUpper(str);
	
	cout<<str;
	
	return 0;
}