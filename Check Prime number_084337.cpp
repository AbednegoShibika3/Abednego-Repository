#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int number;
	
	 cout << "Enter a positive integer: ";
	 cin >> number;
	 
	 if (isPrime(number))
	    cout << number << "is prime." ;
	 else
	    cout << number << "is not prime. ";
	    
	 return 0;   
}