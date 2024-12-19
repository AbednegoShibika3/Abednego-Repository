#include <iostream>
using namespace std;

 double calculateAreaofcircle(double radius)
 {
 	double PI = 3.14;
	return PI * radius;
 }

 double calculateCircumferenceofCircle(double radius)
 {
 	double PI = 3.14;
	return 2 * PI * radius;
 }

 double calculateVolumeofCylinder(double radius, double height)
{
	double PI = 3.14;
	return PI * radius * radius * height;
}
int main()
{
	int choice;
	cout<<"Welcome to a simple calculator, choose activity\n";
	cout<<"1. Calculate the area of circle\n2. Calculate the circumference of circle\n3. Calculate of the volumem of the cylinder\n";
	cout<<"=";
	cin>>choice;
	
	if (choice == 1)
	{
		double radius;
		cout<<"Enter the radius of circle";
		cin>>radius;
		double area = calculateAreaofcircle(radius);
		cout<< "The area of circle  is"<< area<< endl;
	}
	
	else if (choice == 2)
	{
		double radius;
		cout<<"Enter the radius of the radius of the circle";
		cin>>radius;
		double circumference = calculateCircumferenceofCircle(radius);
		cout<<"The circumference of circle is"<<circumference<< endl;
	}
	
	else if (choice == 3)
	{
		double radius;
		cout<<"Enter the radius of the cylinder";
		cin>>radius;
		
		double height;
		cout<<"Enter the height of the cylinder";
		cin>>height;
		double volume = calculateVolumeofCylinder(radius, height);
		cout<<"The volume of cylinder is "<< volume<< endl;
    }
}
