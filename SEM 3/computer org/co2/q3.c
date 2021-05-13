#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{	
	int i,sum=0;
	const int a=atoi(argv[1]);
	const int b=atoi(argv[2]);
	printf("The Sum is %d\n",a+b);
	printf("The Subtraction is %d\n",a-b);
	printf("The Multiplication is %d\n",a*b);
	if(b!=0)
	printf("The Division is %f\n",(float)a/(float)b);
	else
	printf("Runtime Error\n");
	return 0;	
	
}

