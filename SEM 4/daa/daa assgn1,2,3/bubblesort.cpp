#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
clock_t begin, end;
double time_;

void bubble_sort(long long data[], long long count)  
{  
    int i, j;  
    long long temp;
   // int f; 		//using flags to optimize code
    for (i = 0; i < count-1; i++) 
	{ 
	//f=0;        
    for (j = 0; j < count-i-1; j++)  
    	{
    		if (data[j] > data[j+1])  
          	  {
            	temp=data[j];
            	data[j]=data[j+1];
            	data[j+1]=data[j];
     //       	f=1;
			}
		}
	//	if(f==0)
	//	break;
	}
	
}
  
void bubble_sort_dec(long long data[], int count)  
{  
    int i, j;  
    long long temp;
    for (i = 0; i < count-1; i++) 
	{ 
    for (j = 0; j < count-i-1; j++)  
    	{
    		if (data[j] < data[j+1])  
          	  {
            	temp=data[j];
            	data[j]=data[j+1];
            	data[j+1]=data[j];
			}
		}
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
	long long *data;		//array to hold data
	int i;
	char filename[15];
	FILE *fp;
	printf("*******************TIME SUMMARY***************\n");
	for(i=4;i<10;i++)
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
		bubble_sort(data,n);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("AVERAGE case : %0.10lf\n", time_);
		
		sprintf(filename, "File %d_asc.txt", i+1);
		fp = fopen(filename, "r");
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &data[j]);
		}
		begin = clock();
		bubble_sort(data,n);
		end = clock();
		fclose(fp);
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Best case  : %0.10lf\n",time_);
	    	
 
		begin = clock();
		bubble_sort_dec(data,n);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Worst case  %0.10lf\n\n", time_);
	
		free(data);
	}
}
