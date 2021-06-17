#include<stdio.h>
#include<stdlib.h>  
#include<time.h>
#include<conio.h>
int random_num();                        // Generates OTP
int input_details();                    //Takes Mobile Number as input from the user
int mobileNumber();                    //Verifies whether the given mobile number is 10 digit or not
int main()
{
    input_details();                 //Function call
    printf("");
}

int input_details()
{
   
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER YOUR PHONE NUMBER: ");
    mobileNumber();              // Function call to verify the given mobile number is 10 digit or not 
    random_num();                // Function call to generate OTP
    
    
}

int mobileNumber()                                         //Function definition
{
  double mobileNumber;
    mo:
    while ( !scanf("%lf",&mobileNumber) )
    {
        fflush(stdin);
        printf("\n Invalid Number :\n\n ");
        printf("Enter Mobile No Again : ");
    }
    if (mobileNumber < 1000000000 || mobileNumber > 9999999999)
    {
        printf("\n Please enter only 10 digits... \n");
        goto mo;
    }
    return mobileNumber;
}

int random_num()
{
    int a,otp;
    int i;
    
    srand(time(NULL));
    printf("\n");
    printf("                       ONE TIME PASSWORD is : ");
    a=rand();
    printf("%d\n",a);
    printf(" \n                       ENTER ONE TIME PASSWORD: ");
    scanf("%d",&otp);
    i=0;
    
    if(a==otp)
    {
        printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	   // printf("\n\n\n\t\t\t\tPress any key to continue...");
        //getch();
        FILE *fp;
	    fp=fopen("logindetails.txt","a");
        fprintf(fp,"%d",&mobileNumber);
        fclose(fp);

    }    
    else 
    {
        printf("\n              SORRY !!!!  LOGIN IS UNSUCESSFUL");
        
        if(i<=1)
        {
            i++;
            random_num();
            
        }
        else
        {
            printf("\n       Too many attempts");
            input_details();
       
             
        }
    }
    
    
    

}
