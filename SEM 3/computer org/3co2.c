#include <stdio.h>



int main(int argc,char* argv[])

{
if (argc==2){
    float a,b;

    a=atoi(argv[1]);


    printf("various precision of float number:");

    printf("%.1f\n",a);
	 printf("%.2f\n",a);
	 printf("%.3f\n",a);
	 printf("%.4f\n",a);
	 printf("%.5f\n",a);
	 printf("%f",a);
}
    else {

    printf("\n enter correct arg");

    }

    return 0;



}
