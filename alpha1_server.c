#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"
#include <time.h>

// creating all the functions that will land on the opening page  

void train_disp()
{
    printf("Here are the available trains to your destination...\n");
    printf("___(The deprature timings are mentioned below the train names)___ ");

        char train_db[7][3] = {'MatsyagandhaExpress','MangalaLakshadweepExpress','PrashantiExpres',
                            'SharavatiExpress','WaingangaSuperfastExpress','KondaveeduExpress'
                            ,'RaniChennammaExpress','JanShatabdiExpress','RajyaRaniExpress'
                            ,'SiddagangaIntercity','VishwamanavaExpress','ChamundiExpress'
                            ,'KaveriExpress','BasavaExpress','GolGumbazExpress',
			     'TippuSuperfastExpress','DurontoExpress','GaribRathExpress'
				,'MalgudiExpress','GomateshwaraExpress','KarnatakaSamparkKrantiExpress'};   // database of trains 

    int l = 0, u = 20, ind1, ind2;
    srand(time(0)); 
        for(int i = 0; i < 5; i++)
        {
                        int time_hr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
                        int time_min[8] = {10,15,20,30,35,40,45,50};   // database of times 
                        int rand_hr,rand_min;

                        int low_hr = 0,up_hr = 11,hr_index,hr;
                        srand(time(0));
                            for (int i = 0; i < 2; i++) {
                                hr_index = (rand() % (up_hr - low_hr + 1)) + low_hr;
                                hr = time_hr[hr_index];
                                break;
                            }

                        int low_min = 0,up_min = 7,min_index,min;
                        srand(time(0));
                            for (int i = 0; i < 2; i++) {
                                min_index = (rand() % (up_min - low_min + 1)) + low_min;
                                min = time_min[min_index];
                                break;
                            }

            ind1 = (rand() % (u - l + 1)) + l;
		ind2 = (rand() % (u - l + 1)) + l;
		
            printf("%d.",i+1);
            printf("%c_",train_db[ind1][ind2]);
            if(i%2 == 0)
            {
                printf("%d:%d AM\n",hr,min);
            }
            else if( i%2 != 0)
            {
                printf("%d:%d PM\n",hr,min);
            }
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

