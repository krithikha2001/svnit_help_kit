#include <math.h>
#include <stdio.h>
#define ll long long
int to_int(const char* str)
{
	long long i,x;
	for(x=0,i=0;str[i];++i)
	{
		if(i==0&&str[i]=='-')
			++i;
		if(str[i]>='0'&&str[i]<='9')
			x=x*10+(str[i]-48);	//0 s ascii value is 48
		else
			break;
	}
	if(str[0]=='-')	//negetive numbers
		x=-x;
	if(x!=(int)x)
	printf("The number is out of range\n");	//int range  is till 2147483647
	else
	printf("The number is in range\n");
	
	return (int)x;
}
int main(int argc, char const *argv[])
{	
	int i,sum=0;
	int a=to_int(argv[1]);
	return 0;
	
}

