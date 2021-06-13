#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a,otp,otp_enter;
	long double ph;

	srand(time(0));
	printf("TO PROCEED FOR CANCELLATION, PRESS '1'\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("ENTER PHONE NUMBER: ");
		scanf("%ld",&ph);
		otp = rand();
		printf("OTP: %d\n",otp);
		printf("ENTER YOUR OTP: ");
		scanf("%d",&otp_enter);
		if(otp_enter==otp)
		{
			printf("TICKETS HAVE BEEN CANCELED!\n");
		}
		else
		{
			printf("INVALID OTP\n");
		}
	}
	printf("THANK YOU\n");
	return 0;
}


		
			
		
		
		 
		

	
	
