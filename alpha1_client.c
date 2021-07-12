#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"
#include <stdlib.h>

//***********************************GLOBALS***********************************************
	char name[50], cancel_choice[2], yes[2]="y";				
	int age ,rm;
	int ser,tic;
	int train_choice;

	int p1 = 0;int p2 = 0;

	//int finalprice;
	int rm,dm;
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

	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM - LOGIN/CANCEL PAGE");
	printf("\n=================================");
	mobileNumber();
	random_num();
	printf("Do you want to cancel an existing ticket ? (y/n) ");
	scanf("%c",&cancel_choice);
	if(strcmp(cancel_choice,yes) == 0)
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
	
	enterplace(p1, p2);
	train_disp();
	printf("Enter the Sl.No of the train you want: ");
	scanf("%d\n",train_choice);

  	printf("NAME: ");
  	scanf("%s",&name);
  	printf(" age:");
  	scanf("%d",&age);
  	printf(" coach class: 1.AC CHAIR  | 2.AC SLEEPER | 3.CHAIR | 4.SLEEPER \n");
  	printf("select coach class by entering the number next to it:");
  	scanf("%d",&ser);
  	printf("number of tickets:"); //t must be greater than 1
  	scanf("%d",&tic);
  
	dm = enterplace(p1,p2);
  	final_ticket(ser,tic,dm);
  	
	printf("Name : %c\n",name) ;
	printf("Age : %d\n",age);
	double mobilenum_fordisplay = mobileNumber();
  	printf("mobile phone: %lf: \n",mobilenum_fordisplay);
	printf("Date: ",__DATE__);
	printf("Time: ",__TIME__);
  	printf("booking status: BOOKED");
//   	printf ("name of the train: ");
//   	printf ("depature time:");
//   	printf ("arrival  time:");
//   	printf("car number:");
	
	cancel_end();
	
	return(0);
}
