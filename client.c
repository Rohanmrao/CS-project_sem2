#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"
#include <time.h>


//***********************************GLOBALS***********************************************
	char name[50], cancel_choice[1];	// name : stores the name of the user 			
	int age ,rm;                        // rm :resvervation multiplier
	int ser,tic;                        //ser : serial number of the coach class ; tic: number of tickets to be booked
	int train_choice, choice_flag = 1;  // train_choice: displays the train alloted 

	int p1 = 0;int p2 = 0;              //p1: starting station serial number ; p2 : destination serial number 
    
	
    int dd, mm, yy;                     // day, month, year 
	int flag = 0,cout,a;                //flag and cout are counting variables , a stores value of check function


	
	int payup,dm;                       //payup:stores final cost of ticket  ; dm : distance mutliplier

	double mobileNum; double mobilenum_fordisplay;

	location loc;

	char *places[50] = {"BangaloreCity", "MumbaiCST", "NewDelhi", "Bijapur", "Kolhapur", "Mysore", "Badami", "ChennaiCentral", "Secunderabad", "Hubli", "Hospet", "Jaipur", "Lucknow", "Solapur", "Mangalore"};
//*******************************************************************************************

int main()                                            //Main Function

{ 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|     --------------------------------          |\n");
	printf("\t\t|     TRAIN TICKET RERSERVATION SYSTEM          |\n");
	printf("\t\t|     --------------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|      ______SEMESTER 2 PROJECT______           |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	
    printf("========================================================\n");
	printf("    TRAIN RESERVATION SYSTEM - LOGIN/CANCEL PAGE\n");
	printf("========================================================\n");
	printf("\n");
	printf("======================= LOGIN FORM =====================\n  ");
	printf("\n");
    printf("ENTER YOUR PHONE NUMBER: ");              //User enters the mobile number
	scanf("%lf",&mobileNum);
	getchar();

	mobileNumber(mobileNum);                         //mobilenumber() is called to verify whether the entered number is 10 digit or not
	random_num(mobileNum);                           //random_num() is called to generate the random four digit number
	//getchar();

	printf("\n");
	printf("Do you want to cancel an existing ticket ? (y/n): ");
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_front(mobileNum);                      //cancel_front() is called if the user wants to cancel the previously booked tickets
	}
	printf("\n");
	places_disp();
	printf("\n");
	printf("\n-------------------------\n");
	
	printf("\n");
	printf("Enter the Sl.no of the start point: ");    // User enters the starting point
	scanf("%d",&p1); getchar();  
	strcpy(loc.origin, places[p1 - 1]);
	printf("\n");
	printf("Enter the Sl.no of the end point: ");      // User enters the end point 
	scanf("%d",&p2);getchar();
	strcpy(loc.destination, places[p2 - 1]);
	printf("\n");
	dm = enterplace(p1,p2);                           // distance  multiplier generated here 
	                                                 // enterplace() is called to verify whether the entered places are valid or not 
    
	
	printf(" \n ---------------------DATES AVAILABLE WITHIN 1 YEAR PERIOD  -------------------------\n ");
	printf("\n");
	printf("\n----------NOTE : booking date and travelling dates must have  minimum of 1 day gap------------- \n ");
	printf("\n");
	printf("Enter the  booking date  (DD/MM/YYYY) : ");         
	scanf("%d/%d/%d",&dd,&mm,&yy);getchar();
	a=check(dd,mm ,yy);
	while(flag==0)                                     // executed only if the entered date is invalid 
    {
        printf("Please enter a valid date (DD/MM/YYYY format): ");
        scanf("%d/%d/%d",&dd,&mm,&yy);
		fflush(stdin);
        check(dd,mm ,yy);                             // re-checking if the entered date is valid 
    }    
	fflush(stdin);
	
	

	printf("\n");
	train_disp();
	printf("You have been allotted train number %d... \n",choice_flag);
	printf("Type 1 to accept... 2 to reject :");
	scanf("%d",&train_choice); getchar();
	choice_flag=2;

	if(train_choice == 2 && choice_flag>=2)
	{
		printf("------------------------------\n");
		printf("Reallotting...\n");
		printf("You have been allotted train number %d... \n",choice_flag);
		printf("Type 1 to accept... 2 to reject :");
		scanf("%d",&train_choice); getchar();
		choice_flag=3;
	}

	if(train_choice == 2 && choice_flag>=2)
	{
		printf("------------------------------\n");
		printf("Reallotting...\n");
		printf("You have been allotted train number %d... \n",choice_flag);
		printf("Type 1 to accept... 2 to reject :");
		scanf("%d",&train_choice); getchar();
		choice_flag=4;
	}

	if(train_choice == 2 && choice_flag>=2)
	{
		printf("------------------------------\n");
		printf("Reallotting...\n");
		printf("You have been allotted train number %d... \n",choice_flag);
		printf("Type 1 to accept... 2 to reject :");
		scanf("%d",&train_choice); getchar();
		choice_flag=5;
	}

	
	// accepting user details
	printf("\n");
	printf("-----------------------------------\n");
	printf("\n");
  	printf("Enter you Name: ");
	fflush(stdin);
  	scanf("%s",&name);getchar();
  	printf("Enter your Age: ");
	fflush(stdin);
  	scanf("%d",&age);getchar();  	
	printf("Coach Class: 1.AC CHAIR  | 2.AC SLEEPER | 3.CHAIR | 4.SLEEPER \n"); // selection of coach class 
  	printf("Select coach class by entering the number next to it: ");
  	scanf("%d",&ser);getchar();
  	printf("Number of Tickets:");
  	scanf("%d",&tic);getchar();
	payup = final_ticket(ser,tic,dm);                   // final_ticket() is called to calculate the final amount 
  	
	while(cout==0)
	{
       printf("Select coach class by entering the number next to it: ");
  	   scanf("%d",&ser);getchar();
  	   printf("Number of Tickets:");
  	   scanf("%d",&tic);getchar();
  
	   payup = final_ticket(ser,tic,dm);    
	}
	
	
	
	fflush(stdin);
	
	// bill displaying data based on info collected from user
	printf("\n");
	printf("\n---------- BILL ------------\n");
	printf("\n");
	printf("Name:");
	puts(name);
	printf("Age : %d\n",age);
	mobilenum_fordisplay = mobileNumber(mobileNum);
  	printf("Ticket(s) booked for : %d/%d/%d\n",dd,mm,yy);
	printf("Mobile Fhone: %.0f\n",mobilenum_fordisplay);
	printf("From: %s\n", loc.origin);
	printf("To: %s\n", loc.destination);
	printf("Train number: %d\n",choice_flag-1);
  	printf("Booking Status: BOOKED\n");
	printf("Total Amount: %d\n",payup);
	booked_on();
    printf("\n-------------------------------------------------");



	printf("\n Do you want to cancel the ticket you just booked ? (y/n): ");
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_end(mobileNum);
	}
	else
	{
		printf("\n");
		printf("Thank You");
		printf("\n");
	}
	
	
	return(0);
}
