#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[])
{
    double a,b;
    if( argc == 3 )
    {
       a=atoi(argv[1]);
    b=atoi(argv[2]);
    printf("Addition is: %lf\n",(a+b));
    printf("subtraction is: %lf\n",(a-b));
    printf("multiplication is: %lf\n",(a*b));
    printf("division is: %lf\n",(a/b));

    }
    else
    {
        printf("argument list is not proper .\n");
    }
    return 0;
}

