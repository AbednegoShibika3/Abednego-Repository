#include <iostream>
#define PI 3.14159
using namespace std;
int main() {
	float radius;
	cout<<"Enter radius: ";
	cin>>radius;
	float volume = (4.0/3) * PI * radius * radius * radius;
	cout<<"Volume: "<<volume<<endl;
	return 0;
}