#include<stdio.h>
#include<string.h> 
int final_ticket(int s, int t);
char disp(char name);
char name; // global variables
int age ,rm ;//s- serial num | rm reservation multiplier |
int  main()
{ 
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
  return 0;

}


void final_ticket(int s, int t)
{
   
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
  int fp ,dm;
  fp = dm*t*rm;
  printf("total cost : %f",fp);

}

void disp(char name)
{ 
  printf("name : %s",name) ;
  printf("mobile phone: ");
  printf("booking status: BOOKED");
  printf ("name of the train: ");
  printf ("depature time:");
  printf ("arrival  time:");
  printf("car number:");
}
