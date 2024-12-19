#include<iostream>
using namespace std;
int main()
{
	int choice, PI=3.14;
	double radius, width, length;
	
	do
	{
		cout<<"Choose the below activity\n";
		cout<<"1. Area of the rectangle\n2.Area of the circle\n3. Exit\n=";
		cin>>choice;
		
		switch (choice)
		{
			case 1:
				cout<<"Enter the length of rectangle";
				cin>>length;
				cout<<"Enter the width of rectangle";
				cin>>width;
				cout<<"The area of rectangle is "<<length*width<< endl;
				break;
				
			case 2:
				cout<<"Enter the radius of circle";
				cin>>radius;
				cout<<"The area of circle is "<< PI*radius*radius<<endl;
				break;
				
			case 3:
				cout<<"Exiting the program";
				break;
		}
	}
	while (choice != 3);
   return 0;	
}