#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"
#include <time.h>

// creating all the functions that will land on the opening page  

void train_disp()
{
   printf("Here are the available trains to your destination...\n");
    printf("___(The deprature timings are mentioned below the train names)___ \n");

        char *train_db[25] = {"MatsyagandhaExpress","MangalaLakshadweepExpress","PrashantiExpress",
                            "SharavatiExpress","WaingangaSuperfastExpress","KondaveeduExpress"
                            ,"RaniChennammaExpress","JanShatabdiExpress","RajyaRaniExpress"
                            ,"SiddagangaIntercity","VishwamanavaExpress","ChamundiExpress"
                            ,"KaveriExpress","BasavaExpress","GolGumbazExpress","TippuSuperfastExpress"    
                            ,"DurontoExpress","GaribRathExpress","MalgudiExpress","GomateshwaraExpress"
                           ,"KarnatakaSamparkKrantiExpress","AiravathaExpress"
						   ,"Speed1Express","Speed2Express","Speed3Express"
                        };   // database of trains 
						
		int time_hr[25] = {1,2,3,4,5,6,7,8,9,10,11,12,11,10,9,8,7,6,5,4,3,2,1,4,5};
		int time_min[25] = {10,15,20,30,35,40,45,50,40,35,30,25,20,15,10,10,15,20,25,30,30,30,30,45,45};   // database of times 

		int l = 0, u = 26, ind1,ind2;
		srand(time(0)); 
	
        for(int i = 0; i < 5; i++)
        {
            ind1 = (rand() % (u - l + 1)) + l;
			int hr = time_hr[ind1];
			int min = time_min[ind1];
            printf("%d. ",i+1);
            printf("%s ",train_db[ind1]);
            if(i%2 == 0)
            {
                printf(" %d:%d AM\n",hr,min);
            }
            else if( i%2 != 0)
            {
                printf(" %d:%d PM\n",hr,min);
            }
        }
    }

void places_disp()
{
	// this is the function that will show all the available places 

	printf("Here are the available stations:\n");
	FILE* places_disp;
    int display;
 
    // Creates a file "demo_file"
    // with file acccess as read mode
    places_disp = fopen("places.txt", "r");
 
    // loop to extract every characters
    while (1) {
        // reading file
        display = fgetc(places_disp);
 
        // end of file indicator
        if (feof(places_disp))
            break;
 
        // displaying every characters
        printf("%c", display);
    }
}
int enterplace()
{
	int distance_val = 0;
	printf("Enter the Sl.no of the start point: ");
	int p1 = 0;
	scanf("%d",&p1);
	printf("Enter the Sl.no of the end point: ");
	int p2 = 0;
	scanf("%d",&p2);

	if(p2 > p1){
		distance_val = p2-p1;
	}
	else if (p1 >p2){
		distance_val = p1-p2;
	}
	else {
		distance_val = 0;
	}

	if((p1 >15 && p2 >15) || (p2 <=0 && p1 <=0))
	{
		printf("Invalid inputs..");
	}
	return distance_val;
}

int rates_dist()
{
	int dist = enterplace();
	int dist_multiplier;
	if(dist >= 1 && dist <=5)
	{
		dist_multiplier = 2;
	}
	else if(dist >=6 && dist <=10)
	{
		dist_multiplier = 3;
	}
	else if(dist >=11 && dist <15)
	{
		dist_multiplier = 4;
	}
	return dist_multiplier ; // Poorna use this to multiply with reservation multiplier and
							// number of tickets to get final ticket price 

}
