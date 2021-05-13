//1
#include <stdio.h>

int main() {
	int n;
	printf("Size of int is %ld\n", sizeof(n));
	printf("Enter number to check if it lies between 1 to 100\n");
	do{
		scanf("%d", &n);
	}while(n >= 1 && n <= 100);
	printf("%d is out of range", n);
    return 0;
}
