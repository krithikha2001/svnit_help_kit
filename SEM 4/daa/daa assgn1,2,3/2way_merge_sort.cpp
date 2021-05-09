#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<time.h>
clock_t begin, end;
double time_;
//u19cs076
void merge(long long arr[], long long l, long long m, long long r)
{
    long long i;
	long long j;
	long long k;
    long long n1 = m - l + 1;
    long long n2 = r - m;

    long long *left;
    long long *right;
    left=(long long*)malloc(n1*(sizeof(long long)));
	right=(long long*)malloc(n2*(sizeof(long long)));

 
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
 

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    free(left);
    free(right);
}
 

void merge_sort(long long arr[], long long l, long long r)
{
    if (l < r) {

        long long m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
void merge_dec(long long arr[], long long l, long long m, long long r)
{
    long long i;
	long long j;
	long long k;
    long long n1 = m - l + 1;
    long long n2 = r - m;

    long long *left;
    long long *right;
    left=(long long*)malloc(n1*(sizeof(long long)));
	right=(long long*)malloc(n2*(sizeof(long long)));

 
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (left[i] >= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
 

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
   
void merge_sort_dec(long long arr[], long long l, long long r)
{
    if (l < r) {

        long long m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge_dec(arr, l, m, r);
    }
}
  

  
long long count(char file[])
{
	FILE *fp = fopen(file, "r");
	long long count = 0;
	char b[100];
		while(fscanf(fp, "%s\n", &b) == 1)
				count++;
	fclose(fp);
	return count;
}
  
int main()
{
	long long n;
	long long j;
	long long *arr;		//array to hold data
	int i;
	char filename[15];
	FILE *fp;
	printf("*******************TIME SUMMARY***************\n");
	for(i=0;i<10;i++)
	{
		sprintf(filename, "File %d.txt", i+1);		
		n = count(filename);
		printf("-------------------------File %d.txt-----------------------\n",i+1);
		printf("File %d has %lld elements\n",i+1,n);
		
		fp = fopen(filename, "r");
		arr=(long long*)malloc(n*((long long)sizeof(long long)));
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &arr[j]);
		}
		begin= clock();
		merge_sort(arr,0,n-1);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("AVERAGE case : %0.10lf\n", time_);
		
	
		begin = clock();
		merge_sort(arr,0,n-1);
		end = clock();
		fclose(fp);
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Best case  : %0.10lf\n",time_);
	    	
		begin = clock();
	//	bubble_sort_dec(data,n);
		merge_sort_dec(arr,0,n-1);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Worst case  %0.10lf\n\n", time_);
	
		free(arr);
		
	}
}
