#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
	
	string rev=str ;
	(rev.begin(), rev.end()) ;
	return str==rev ;
}

int main() {
	string word ;
	cout<<"Enter a word: ";
	cin>>word ;
	
	if(isPalindrome(word))
	cout<<word<<" is a palindrome. " ;
	
	else
	cout<<word<<" is not a palindrome." ;
	
	return 0 ;
}