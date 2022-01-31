#include <iostream>
#include <time.h>
using namespace std;
clock_t begin, end;
double time_;

int wiggle(int arr[],int n)
{
	if (n < 2)
            return n;
    int prevdiff = arr[1] - arr[0];
    int count ;
	if(prevdiff!= 0)
		count=2;
	else
		count=1;
	for (int i = 2; i < n; i++) 
	{
        int diff = arr[i] - arr[i - 1];
        if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) 
		{
            count++;
            prevdiff = diff;
        }
    }
    return count;
}
int main()
{
	cout<<"\t\t====GREEDY APPROACH======";
	int n;
	cout<<"\nEnter number of elements in array:";
	cin>>n;
	cout<<"\nEnter the array to find its wiggle subsequence:";
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	begin = clock();
	cout <<  endl<<"\nMaximum length of subsequence: " << wiggle(arr, n) << endl;		
	end = clock();
	time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
	cout<<"\nTime taken :"<<time_;
	return 0;
}
