#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"
#include <time.h>
#include <stdlib.h>

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
                           ,"KarnatakaSamparkKrantiExpress","AmaravatiExpress"
						   ,"PanchagangaExpress","NightQueenPassenger","PrashantiNilayamExpress"
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
int enterplace(int p1,int p2)
{
	int distance_val = 0, dist_multiplier;
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
	
	if(distance_val >= 1 && distance_val <=5)
	{
		dist_multiplier = 2;
	}
	else if(distance_val >=6 && distance_val <=10)
	{
		dist_multiplier = 3;
	}
	else if(distance_val >=11 && distance_val <15)
	{
		dist_multiplier = 4;
	}
	return dist_multiplier ; // Poorna use this to multiply with reservation multiplier and
							// number of tickets to get final ticket price 
}

void cancel_front()
{
	FILE *fp;
	
	//ATTEMPT TO OPEN THE TEXT FILE
	fp = fopen("logindetails.txt","r");

	//CHECKING IF THE FILE EXISTS
	if(fp == NULL)
	{
		printf("	FILE DOES NOT EXIST! \n");
	}

	//OPENING THE FILE AND PROCEEDING IF FILE EXISTS
	else
	{
		char ph[20], check[20];

		printf("	PLEASE ENTER YOUR PHONE NUMBER:  \n");   //PROMPTING USER TO ENTER THE PHONE NUMBER
		scanf("%s", &ph);
	
		fscanf(fp, "%s", &check);   //READING THE PHONE NUMBER PRESENT IN THE TEXT FILE
		if(!(strcmp(ph, check)))   //CHECKING IF THE ENTERED PHONE NUMBER MATCHES THAT PRESENT IN THE TEXT FILE
		{

			//GENERATING AN OTP
			int otp, otp_enter;
			int l = 1000, u = 9999, trials = 0;

			srand(time(0)); 
			otp = (rand() % (u - l + 1)) + l;  //ENSURING THAT THE RANDOM OTP GENERATED WILL CONSIST OF 4 DIGITS ONLY.
			printf("	OTP: %d\n", otp);
			printf("\n");

			//PROMPT FOR USER TO ENTER THE OTP
			printf("	ENTER YOUR OTP: ");
			scanf("%d", &otp_enter);

			//WE SHALL LIMIT THE NUMBER OF TRIALS OF OTP ENTRY TO 4.
			while((otp_enter != otp) && (trials <= 2))
			{
				printf("	INVALID OTP! PLEASE TRY AGAIN \n");
				printf("\n");
				printf("	ENTER YOUR OTP: ");
				scanf("%d", &otp_enter);
				trials++;
			}

			//CHECKING IF THE NUMBER ENTERED MATCHES THE GENERATED OTP
			if(otp_enter == otp)
			{
				printf("\n");
				printf("	TICKETS HAVE BEEN CANCELED! \n");
			}
			else
			{
				printf("\n");
				printf("	UNABLE TO CANCEL. SORRY! \n");
			}
		
		}

		else    //IF PHONE NUMBER ENTERED DOES NOT MATCH THAT PRESENT IN THE TEXT FILE
		{
			printf("\n");
			printf("	INVALID PHONE NUMBER! \n");
		}

		fclose(fp);
	}

	printf("\n");
	printf("	THANK YOU! \n");
}

void cancel_end()
{
	int a, otp, otp_enter;

	printf("	TO PROCEED TO CANCELLATION, PRESS '1':  \n");    //USER CONFIRMS WHETHER HE WANTS TO PROCEED TO CANCELLATION.
	scanf("%d", &a);
	if(a == 1)
	{
		int l = 1000, u = 9999, otp, trials = 0;

		srand(time(0)); 
		otp = (rand() % (u - l + 1)) + l;  //ENSURING THAT THE RANDOM OTP GENERATED WILL CONSIST OF 4 DIGITS ONLY.
		printf("	OTP: %d\n", otp);
		printf("\n");
		printf("	ENTER YOUR OTP: ");
		scanf("%d", &otp_enter);
		//WE SHALL LIMIT THE NUMBER OF TRIALS OF OTP ENTRY TO 4.
		while((otp_enter != otp) && (trials <= 2))
		{
			printf("	INVALID OTP! PLEASE TRY AGAIN \n");
			printf("\n");
			printf("	ENTER YOUR OTP: ");
			scanf("%d", &otp_enter);
			trials++;
		}
		//CHECKING IF THE NUMBER ENTERED MATCHES THE GENERATED OTP
		if(otp_enter == otp)
		{
			printf("\n");
			printf("	TICKETS HAVE BEEN CANCELED! \n");
		}
		else
		{
			printf("\n");
			printf("	UNABLE TO CANCEL. SORRY!! \n");
		}
		
	}
	printf("	THANK YOU! \n");
}

double mobileNumber()                                         //Function definition
{
	double mobileNum;
	printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf("                       ENTER YOUR PHONE NUMBER: ");
	scanf("%lf",&mobileNum);
	
    if (mobileNum < 1000000000 || mobileNum > 9999999999)
    {
        printf("\n Please enter only 10 digits... \n");
		mobileNumber();    
    }
    return mobileNum;
}

void random_num()
{
    int a;
    int i;
	double mob = mobileNumber();
    
    printf("\n");
    printf("                       ONE TIME PASSWORD is : ");
    int l = 1000, u = 9999, otp, trials = 0;
	srand(time(0)); 
	a = (rand() % (u - l + 1)) + l;
    printf("%d\n",a);
    printf(" \n                       ENTER ONE TIME PASSWORD: ");
    scanf("%d",&otp);
    i=0; 
    
    if(a==otp)
    {
        printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	 
        FILE *fp;
	    fp=fopen("logindetails.txt","w");
        fprintf(fp,"%lf",mob);
        fclose(fp);

    }    
    else 
    {
        printf("\n              SORRY !!!!  LOGIN IS UNSUCCESSFULL");   
    }
}
void final_ticket(int s, int t,int distmult)
{	
	int rm;
	
  // reservation multipliers: 1- rs 25 | 2 - rs 20 |3 - rs 15 |4 - rs 10
  if (s>=1 && s<=4)
  {
    if(s==1)
    {
      printf("coach class: AC CHAIR");
      rm= 25;
    }   
    if(s==2)
    {
      printf("coach class: AC SLEEPER");
      rm=20;
    }  
    if(s==3)
    {
      printf("coach class: SLEEPER");
      rm= 15;
    }   
    else
    {
      printf("coach class:  CHAIR");
      rm=10;
    }     
  }
  else
  {
    printf("error");
  }
  
  //final price = distance_multiplier * number of tickets * reservation multiplier 
  // reservation multipliers: 1- rs 25 | 2 - rs 20 |3 - rs 15 |4 - rs 10
  
  printf("total cost : %f",(distmult*t*rm));
}


