#include <iostream>
#include <time.h>

using namespace std;

int wiggleMax(int arr[], int n){
	if (n<2){
		return n;
	}
	int up[n]={0}, down[n]={0};
	int i,j;
	for(i=1; i<n; i++){
		for(j=0; j<i;j++){
			if(arr[i]>arr[j]){
				up[i]=max(up[i], down[j]+1);
			}
			else if(arr[i]<arr[j]){
				down[i]=max(down[i], up[j]+1);
			}
		}
	}
	return 1+max(down[n-1], up[n-1]);
}

int main(){
	int n;
	cout<<"Enter number of elements in array: ";
	cin>>n;
	cout<<"Enter the array to find its wiggle subsequence: ";
	int i;
	int arr[n];
	for(i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<endl;
	clock_t start, end;
	double t;
	start = clock();
	cout<<"length of the longest wiggle subsequence: "<<wiggleMax(arr,n);
	end = clock();
	t=((double)(end-start)/CLOCKS_PER_SEC);
	cout<<endl<<"time taken: "<< t;
}
