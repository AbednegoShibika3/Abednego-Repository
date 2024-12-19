#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	
	cout<<"Enter an integer: ";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	sum += i;
	
	cout<<"Sum from 1 to "<<n<<": "<<sum;
	return 0;
}