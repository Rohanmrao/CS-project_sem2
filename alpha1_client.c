#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"

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
	// roshan's cancel function comes here

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
	
	// Poorna's bio data and ticket book function comes here
	
	cancel_end();
	
	return(0);
}
