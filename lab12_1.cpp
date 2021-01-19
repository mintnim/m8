#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[] , int N , double B[]){
	for(int i = 1 ; i <= N ; i++){
		B[0] += A[i - 1];
	}
	B[0] = B[0] / N;
	
	for(int j = 1 ; j <= N ; j++){
		B[1] += pow(A[j - 1],2);
	}
	B[1] = sqrt((B[1] / N) - pow(B[0],2));
	
	B[2] = 1;
	for(int k = 1 ; k <= N ; k++){
		B[2] *= A[k - 1];
	}
	B[2] = pow(B[2] , 1.0 / N);
	
	for(int l = 1 ; l <= N ; l++){
		B[3] += 1.0 / A[l - 1];
	}
	B[3] = N / B[3];
	
	B[4] = A[0];
	B[5] = A[0];
	for(int m = 1 ; m <= N ; m++){
		if(A[m - 1] > B[4]){
			B[4] = A[m - 1];
		}
		if(A[m - 1] < B[5]){
			B[5] = A[m - 1];
		}
	}
}

