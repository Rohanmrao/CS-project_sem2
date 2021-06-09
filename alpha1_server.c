#include <stdio.h>
#include <string.h>
#include "alpha1_server.h"

// creating all the functions that will land on the opening page  

void ticket_book()
{
    printf("Welcome to <name> !");
    printf("Enter start and stop destination from the given options:\n");
    
    FILE *display_places_ptr; char display_options;
    
    display_places_ptr = fopen("places.txt",r);
    while(1)
    {
      display_options = fgetc(display_places_ptr);
        if(feof(display_places_ptr))
        {
            break;
        }
        
        printf("%c\n",display_options);
    }
    
    printf("\n");
    printf("Enter starting station: ");
    char startpoint[40];
    scanf("%[^\n]%",&startpoint);
    
    printf("Enter the destination station: ");       // a mechanism to check if the user has entered something from the options itself and not randomly
    char endpoint[40];
    scanf("%[^\n]%",&endpoint);
    
        
}
