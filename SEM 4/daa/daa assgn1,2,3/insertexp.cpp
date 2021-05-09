#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

clock_t begin, end;
double time_;

void insertion_sort(long long data[], long long count)  
{  
    long long i, v, j;  
    for (i = 1; i < count; i++) 
    {  
        v = data[i];  //key element to be inserted at right place
        j = i-1; 
        while (j>=0 && data[j]>v) //all elements t left of v
        {  
            data[j+1] = data[j];  
            j = j-1;  
        }  
        data[j+1] = v;  
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

void insertion_sort_desc(long long data[], long long count)  
{  
    long long i, v, j;  
    for (i = 1; i < count; i++) 
    {  
        v = data[i];  
        j = i-1; 
        while (j>=0 && data[j]<v) 
        {  
            data[j+1] = data[j];  
            j = j-1;  
        }  
        data[j+1] = v;  
    }  
}  
int main()
{

	long long n;
	long long j;
	long long *data;		//array to hold data
	int i;
	char filename[15];
	FILE *fp;
	printf("*******************TIME SUMMARY***************\n");
	for(i=4;i<6;i++)
	{
		sprintf(filename, "File %d.txt", i+1);		
		n = count(filename);
		printf("-------------------------File %d.txt-----------------------\n",i+1);
		printf("File %d has %lld elements\n",i+1,n);
		
		fp = fopen(filename, "r");
		data=(long long*)malloc(n*((long long)sizeof(long long)));
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &data[j]);
		}
		begin= clock();
		insertion_sort(data, n);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Average case : %0.10lf\n", time_);
		
		sprintf(filename, "File %d_asc.txt", i+1);
		fp = fopen(filename, "r");
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &data[j]);
		}
		begin = clock();
		insertion_sort(data, n);			
		end = clock();
		fclose(fp);
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Best case  : %lf\n",time_);
	    
		
		begin = clock();
		insertion_sort_desc(data, n);
		end = clock();
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Worst case  %0.10lf\n\n", time_);
		free(data);
	}
}
