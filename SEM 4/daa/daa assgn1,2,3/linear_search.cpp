#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
clock_t begin, end;
double time_;

int linear_search(long long data[],long long count,long long val)
{
	long long i;
	for (i = 0; i<count; i++)
	{
		if(data[i]==val)
		{
			return i;
		}
	}
	return -1;	//if element not found
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
	long long ele;
	long long n;
	long long j;
	long long pos;
	long long *data;		//array to hold data
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
		data=(long long*)malloc(n*((long long)sizeof(long long)));
 		fscanf(fp, "%lld", &ele);			//first element taken for best case
		fseek(fp,0,SEEK_SET);				//returns pointer to start
		for(j=0; j<n; j++)
		{
			fscanf(fp, "%lld", &data[j]);
		}
		begin= clock();
		pos=linear_search(data,n,ele);
		end = clock();
		fclose(fp);
		time_ = ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Best case : %lf\n", time_);
		
	
		begin = clock();
		pos=linear_search(data,n,-1);
		end = clock();
		fclose(fp);
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Worst case  : %lf\n",time_);
		
		/*
		begin = clock();
		pos=linear_search(data,n,38495);		//random element
		end = clock();
		fclose(fp);
		time_= ((double)(end-begin)) / CLOCKS_PER_SEC;
		printf("Average case  : %0.10lf\n",time_);*/
		
		free(data);
	}
}
