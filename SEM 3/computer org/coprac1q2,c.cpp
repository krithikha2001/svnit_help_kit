

#include <stdio.h>
#include <math.h>
int main()
{   long b;
    int x,y,i=0,s=0;
    printf("Enter binary number:");
    scanf("%ld",&b);
    while(b)
    {
        x=b%10;
        y=pow(2,i);
        s+=(x*y);
        i++;
        b/=10;
    }
    printf("Decimal number is %d",s);
    return 0;
}



