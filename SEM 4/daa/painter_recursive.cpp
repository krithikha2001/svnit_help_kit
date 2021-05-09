<<<<<<< HEAD

#include<bits/stdc++.h>
#include <time.h>
using namespace std;
clock_t begin, end;
double time_; 
int sum(int arr[], int h, int l)
{
    int tot = 0;
    for (int i = h; i <= l; i++)
        tot += arr[i];
    return tot;
}
 
int partition(int arr[], int n, int k)
{
    // base cases
    if (k == 1) // one partition
        return sum(arr, 0, n - 1);
    if (n == 1) // one board
        return arr[0];
 
    int best = INT_MAX;
 
    // partition
    for (int i = 1; i <= n; i++){
        best = min(best, max(partition(arr, i, k - 1),sum(arr, i, n - 1)));
    }
    return best;
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
	cout <<  endl<<"Minimum time to paint all boards: " << partition(arr, n, k) << endl;		
	end = clock();
	time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
			cout<<"\nTime taken :"<<time_;

	return 0;
}
=======

#include<bits/stdc++.h>
#include <time.h>
using namespace std;
clock_t begin, end;
double time_; 
int sum(int arr[], int h, int l)
{
    int tot = 0;
    for (int i = h; i <= l; i++)
        tot += arr[i];
    return tot;
}
 
int partition(int arr[], int n, int k)
{
    // base cases
    if (k == 1) // one partition
        return sum(arr, 0, n - 1);
    if (n == 1) // one board
        return arr[0];
 
    int best = INT_MAX;
 
    // partition
    for (int i = 1; i <= n; i++){
        best = min(best, max(partition(arr, i, k - 1),sum(arr, i, n - 1)));
    }
    return best;
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
	cout <<  endl<<"Minimum time to paint all boards: " << partition(arr, n, k) << endl;		
	end = clock();
	time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
			cout<<"\nTime taken :"<<time_;

	return 0;
}
>>>>>>> 4113b8d2c58f52cfdcecb384a4a40fea913e2ffe
