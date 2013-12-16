#include<iostream>

using namespace std;


void display(int** arr, int n) {
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}


void rotate(int** arr, int n) {
	int nlayers = (n<=3)?1:(n-2);
	cout<<"nlayers"<<nlayers<<endl;
	int temp;
	for(int k =0;k<nlayers;k++) {
		// Step1 Swap top with right
		for(int i=n-k- 1;i>=k;i--) {
			temp = arr[i][n-k-1];
			arr[i][n-k-1] = arr[k][i];
			arr[k][i] = temp;
		}
		// step 2 right to bot 
		for(int i=k+1;i<n-k-1;i++) {
			temp = arr[n-k-1][i];
			arr[n-k-1][i] = arr[k][n-i-1];
			arr[k][n-i-1] = temp;
		}
		// one time swap of first elements 
		temp = arr[n-k-1][k];
		arr[n-k-1][k] = arr[k][k];
		arr[k][k] = temp;

		// step 3
		for(int i=k+1;i<n-k-1;i++) {
			temp = arr[i][k];
			arr[i][k] = arr[k][n-i-1];
			arr[k][n-i-1] = temp;
		}

	}
}


int main() {	
	int n;
	cout<<"Enter n";
	cin>>n;
	int **mat;
	mat = new int*[n];
	for(int i=0;i<n;i++) {
		mat[i] = new int[n];
	}
	cout<<"Enter elements of mat row wise"<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>mat[i][j];
		}
	}


	display(mat,n);

	rotate(mat, n);

	display(mat, n);


}