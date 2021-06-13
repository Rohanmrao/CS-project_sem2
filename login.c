#include<stdio.h>
#include<stdlib.h>  
#include<time.h>
int random_num();
int main()
{
    char phone_no;
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER YOUR PHONE NUMBER:-");
    scanf("%s",&phone_no);
    random_num();
    printf("");
}
int random_num()
{
    int a,otp,i;
    srand(time(NULL));
    printf("                       ONE TIME PASSWORD is :-");
    a=rand();
    printf("%d\n",a);
    printf(" \n                       ENTER ONE TIME PASSWORD:-");
    scanf("%d",otp);
    if(a==otp)
    {
        printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	    printf("\n\n\n\t\t\t\tPress any key to continue...");
    }
    else
    {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		system("cls");
        i++;
    }
}