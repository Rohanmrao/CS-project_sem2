#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"
#include <stdlib.h>

//***********************************GLOBALS***********************************************
	char name[50], cancel_choice[2];				
	int age ,rm ;
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
	if(cancel_choice == 'y')
	{
		cancel_front();
	}
	
	printf(">> View All Available Places and Trains");
	printf("\n------------------------");
    
	places_disp();
	
	int distance_val = 0;
	printf("Enter the Sl.no of the start point: ");
	int p1 = 0;
	scanf("%d",&p1);
	printf("Enter the Sl.no of the end point: ");
	int p2 = 0;
	scanf("%d",&p2);
	
	enterplace(p1,p2,distance_val);
	train_disp();
	rates_dist(); // the first rate multiplier is generated here
	
	int ser,tic;
  	printf("NAME: ");
  	scanf("%s",&name);
  	printf(" age:");
  	scanf("%d",&age);
  	printf(" coach class: 1.AC CHAIR  | 2.AC SLEEPER | 3.CHAIR | 4.SLEEPER \n");
  	printf("select coach class by entering the number next to it:");
  	scanf("%d",&ser);
  	printf("number of tickets:"); //t must be greater than 1
  	scanf("%d",&tic);
  
  	final_ticket( ser,tic);
  	disp(name);
	
	cancel_end();
	
	return(0);
}
