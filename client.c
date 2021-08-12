#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"



//***********************************GLOBALS***********************************************
	char name[50], cancel_choice[1];				
	int age ,rm;
	int ser,tic;
	int train_choice;

	int p1 = 0;int p2 = 0;

	
	int payup,dm;

	double mobileNum; double mobilenum_fordisplay;
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
	printf("    TRAIN RESERVATION SYSTEM - LOGIN/CANCEL PAGE");
	printf("=================================\n");
	printf("  =======================  LOGIN FORM  =======================\n  ");
    printf("                       ENTER YOUR PHONE NUMBER: ");
	scanf("%lf",&mobileNum);
	mobileNumber(mobileNum);

	random_num(mobileNum);

	printf("Do you want to cancel an existing ticket ? (y/n):\n");
	scanf("%s",cancel_choice);

	if(strcmp(cancel_choice,"y") == 0)
	{
		cancel_front();
	}
	
	printf(">> View All Available Places and Trains");
	printf("\n------------------------");
    
	places_disp();
	
	
	printf("Enter the Sl.no of the start point: ");
	scanf("%d",&p1);
	printf("Enter the Sl.no of the end point: ");
	scanf("%d",&p2);
	dm = enterplace(p1,p2); // dist mult generated here 

	
	train_disp();
	printf("Enter the Sl.No of the train you want: ");
	scanf("%d",train_choice);
	printf("\n");
	printf("----------------------------\n");

  	printf("NAME: ");
  	scanf("%s",&name);
  	printf(" age:");
  	scanf("%d",&age);
  	printf(" coach class: 1.AC CHAIR  | 2.AC SLEEPER | 3.CHAIR | 4.SLEEPER \n");
  	printf("select coach class by entering the number next to it:");
  	scanf("%d",&ser);
  	printf("number of tickets:"); //t must be greater than 1
  	scanf("%d",&tic);
  
	
	// printf("%d",dm);
	// payup = final_ticket(ser,tic,dm);
  	
	// printf("Name : %c\n",name) ;
	// printf("Age : %d\n",age);
	// mobilenum_fordisplay = mobileNumber(mobileNum);
  	// printf("mobile phone: %lf\n",mobilenum_fordisplay);
  	// printf("booking status: BOOKED");
	// printf("Total amount: %d",payup);
	
	// //cancel_end();
	
	
	return(0);
}
