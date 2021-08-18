#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"
#include <time.h>


//***********************************GLOBALS***********************************************
	char name[50], cancel_choice[1];				
	int age ,rm;
	int ser,tic;
	int train_choice, choice_flag = 1;

	int p1 = 0;int p2 = 0;

	int payup,dm;

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
	random_num(mobileNum);							//random_num() is called to generate the random four digit number
	//getchar();

	printf("\n");
	printf("Do you want to cancel an existing ticket ? (y/n): ");
	scanf("%s",cancel_choice);getchar();


	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_front(mobileNum);                    //cancel_front() is called if the user wants to cancel the previously booked tickets
	}
	printf("\n");
	places_disp();
	printf("\n");
	printf("-------------------------\n");
	
	printf("\n");
	printf("Enter the Sl.no of the start point: ");  // User enters the starting point
	scanf("%d",&p1); getchar();
	strcpy(loc.origin, places[p1 - 1]);
	printf("\n");
	printf("Enter the Sl.no of the end point: ");    // User enters the end point 
	scanf("%d",&p2);getchar();
	strcpy(loc.destination, places[p2 - 1]);
	printf("\n");
	dm = enterplace(p1,p2);                          // enterplace() is called to verify whether the entered places are valid or not  

	
	train_disp();                                   // train_disp() displays the trains availabel
	printf("\n");
	printf("You have been allotted train number %d... \n",choice_flag);
	printf("\n");
	printf("Type 1 to accept... 2 to reject :");
	scanf("%d",&train_choice); getchar();
	choice_flag=2;

	if(train_choice == 2 && choice_flag>=2)        // Loop for realloting the train
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

	printf("\n");
	printf("-----------------------------------\n");
	printf("\n");
  	printf("NAME: ");                              // User enters the details,the required type of seat and number of seats
	fflush(stdin);
  	scanf("%s",&name);getchar();
  	printf("Age: ");
	fflush(stdin);
  	scanf("%d",&age);getchar();
  	printf("Coach class: 1.AC CHAIR  | 2.AC SLEEPER | 3.CHAIR | 4.SLEEPER \n");
  	printf("Select coach class by entering the number next to it: ");
  	scanf("%d",&ser);getchar();
  	printf("Number of tickets:");
  	scanf("%d",&tic);getchar();
  
	payup = final_ticket(ser,tic,dm);              // final_ticket() is called to calculate the final amount 
  	
	printf("\n");
	printf("---------- BILL ------------\n");
	printf("\n");
	puts(name);
	printf("Age : %d\n",age);
	mobilenum_fordisplay = mobileNumber(mobileNum);
  	printf("mobile phone: %.0f\n",mobilenum_fordisplay);
	printf("From: %s\n", loc.origin);
	printf("To: %s\n", loc.destination);
  	printf("booking status: BOOKED\n");
	printf("Total amount: %d\n",payup);
	
	printf("Do you want to cancel the ticket you just booked ? (y/n): ");   // User is asked for final Confirmation of tickek to be booked 
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_end(mobileNum);
	}
	else
	{
		printf("\n");
		printf("Thank You");
	}	
	
	return(0);
}
