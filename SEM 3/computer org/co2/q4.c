#include <math.h>
#include <stdio.h>
#define ll long long

int main(int argc, char const *argv[])
{	float f;
	if(argc==1)
	 printf("Enter 1 number");
	else
	f=atof(argv[1]);

	printf("\nnumber is %f\n",f);
	printf("---printing in different formats---\n",f);

	printf("%.1f\n",f);
	printf("%.2f\n",f);
	printf("%g\n",f);
	printf("%lf\n",f);
	printf("%Lf\n",f);
	printf("%.9f\n",f);
	printf("%e\n",f);
	return 0;

	
}

