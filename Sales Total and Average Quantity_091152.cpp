#include <iostream>
using namespace std;

int main() {
	float totalSales=0,sale=0,count=5,i=1;
	
	while(i<=count) {
		cout<<"Enter sales amount for item "<<i<<": ";
		cin>>sale;
		totalSales+=sale;
		i++;
	}
	
	float averageSales=totalSales/count;
	
	cout<<"Total Sales: "
	<<totalSales<<endl<<"Average Sales: "
	<<averageSales<<endl;
	
	return 0;
}