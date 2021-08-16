#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"



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

int main()

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
	
	printf("=================================\n");
	printf("    TRAIN RESERVATION SYSTEM - LOGIN/CANCEL PAGE\n");
	printf("=================================\n");
	printf("  =======================  LOGIN FORM =======================\n  ");
    printf("ENTER YOUR PHONE NUMBER: ");
	scanf("%lf",&mobileNum);
	getchar();

	mobileNumber(mobileNum);
	
	random_num(mobileNum);
	getchar();
	printf("Do you want to cancel an existing ticket ? (y/n): ");
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_front(mobileNum);
	}
	
	places_disp();
	printf("-------------------------\n");
	
	
	printf("Enter the Sl.no of the start point: ");
	scanf("%d",&p1); getchar();
	strcpy(loc.origin, places[p1 - 1]);
	printf("Enter the Sl.no of the end point: ");
	scanf("%d",&p2);getchar();
	strcpy(loc.destination, places[p2 - 1]);
	dm = enterplace(p1,p2); // dist mult generated here 

	
	train_disp();
	printf("\n");
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

	printf("-----------------------------------\n");
  	printf("NAME: ");
	fflush(stdin);
  	scanf("%s",&name);getchar();
  	printf("Age: ");
	fflush(stdin);
  	scanf("%d",&age);getchar();
  	printf("coach class: 1.AC CHAIR  | 2.AC SLEEPER | 3.CHAIR | 4.SLEEPER \n");
  	printf("select coach class by entering the number next to it: ");
  	scanf("%d",&ser);getchar();
  	printf("number of tickets:");
  	scanf("%d",&tic);getchar();
  
	payup = final_ticket(ser,tic,dm); // total amount
  	
	printf("---------- BILL ------------\n");
	puts(name);
	printf("Age : %d\n",age);
	mobilenum_fordisplay = mobileNumber(mobileNum);
  	printf("mobile phone: %lf\n",mobilenum_fordisplay);
	printf("From: %s\n", loc.origin);
	printf("To: %s\n", loc.destination);
  	printf("booking status: BOOKED\n");
	printf("Total amount: %d\n",payup);
	
	printf("Do you want to cancel the ticket you just booked ? (y/n): ");
	scanf("%s",cancel_choice);getchar();

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_end(mobileNum);
	}
	
	
	return(0);
}
