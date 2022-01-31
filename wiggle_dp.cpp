#include <iostream>
#include <time.h>
using namespace std;
clock_t begin, end;
double time_;

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
	
	cout<<endl<<"length of the longest wiggle subsequence: ";
	//double t;
	//begin = clock();
	//cout<<wiggleMax(arr,n);
	//end = clock();
	//t=(double)((end-begin)/CLOCKS_PER_SEC);
	//cout<<endl<<"time taken: "<< t;
	begin = clock();
	cout <<  endl<<"\nMaximum length of subsequence: " << wiggleMax(arr, n) << endl;		
	end = clock();
	time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
	cout<<"\nTime taken :"<<time_;
	return 0;
}
