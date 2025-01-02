#include <iostream>
using namespace std;

int main() {
	const int rowsA = 2, colsA = 3, rowsB = colsA, colsB = 2;
	int A[rowsA][colsA] = {{1, 2, 3}, {4,5,6}};
	int B[rowsB][colsB] = {{7,8},{9,10},{11,12}};
	int C[rowsA][colsB] = {0};
	
	for(int i=0;i<rowsA;i++) {
		for(int j=0;j<colsB;j++) {
			for(int k=0;k<colsA;k++) {
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	
	for(int i=0;i<rowsA;i++) {
		for(int j=0;j<colsB;j++) {
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}