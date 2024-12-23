#include <iostream>
using namespace std;

int main() {
	float a, b, c;
	
	cout<<"Enter lengths of three sides: ";
	cin>>a>>b>>c;
	
	if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
	cout<<"It's a right triangle.";
	
	else
	cout<<"It's not a right triangle.";
	
	return 0;
}