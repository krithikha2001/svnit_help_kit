#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{	
	int i,sum=0;
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
 int s,d;
s=convert(n)+convert(m);
if(convert(n)>=convert(m))
	d=convert(n)-convert(m);
else
	d=convert(m)-convert(n);
printf("After adding these 2 binary numbers we get:\n binary :%llu \n and in decimal %d\n ",bin(s),s);
	printf("After subtracting these 2 binary numbers we get:\n binary: %lld \n in  decimal: %d",bin(d),d);

 return 0;
}
int convert(long long n) {
 int dec = 0, i = 0, rem;
 while (n != 0) {
 rem = n % 10;
 n /= 10;
 dec += rem * pow(2, i);
 ++i;
 }
 return dec;
}
int bin(int n) {
 long long bin = 0;
 int rem, i = 1;
 while (n != 0) {
 rem = n % 2;
 n /= 2;
 bin += rem * i;
 i *= 10;
 }
 return bin;
}
