
 
#include <iostream>
#include <bits/stdc++.h> 
#include <time.h>
using namespace std;
clock_t begin, end;
double time_;

int getMax(int arr[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int getSum(int arr[], int n)
{
	int sum= 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

int painter_count(int arr[], int n, int l) // find minimum required painters for given maximim length l
{
	int total = 0, num = 1;
	for (int i = 0; i < n; i++)
	{
		total += arr[i];
		if (total > l) 
		{
			total = arr[i];
			num++;
		}
	}
	return num;
}

int partition_range(int arr[], int n, int k)
{
	int low = getMax(arr, n);
	int high = getSum(arr, n);

	while (low < high) {
		int mid = low + (high - low) / 2;
		int req = painter_count(arr, n, mid);//required painter for the given minimum time stored in req
		if (req <= k)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main()
{
	int n, k, i;
	int *arr;
	cout << "Enter the number of boards of varying length to be painted: ";
    cin>>n;
    cout<<"Enter the number of painters available: ";
    cin>>k;
    cout<<"Enter the lengths of "<<n<<" partitions : ";
    arr=(int*)malloc(n*(sizeof(int)));
    for(i=0; i<n; i++){
    	cin>>arr[i];
	}
	cout<<"--------------------------------------------------";
	begin = clock();
	cout <<  endl<<"Minimum time to paint all boards: " << partition_range(arr, n, k) << endl;		
	end = clock();
	time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
	cout<<"\nTime taken :"<<time_;

	return 0;
}
