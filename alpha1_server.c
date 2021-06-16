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
/*    
int otp_gen() // to generate all our random numbers
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
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name 
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

*/

