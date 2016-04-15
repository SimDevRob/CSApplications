#include <cs50.h>
#include <stdio.h>

/*
  Ask user for a positive integer no greater
  than 23 and then draws a half pyramid with
  a height of the given integer.
*/

int main(void)
{
    //declare vars
    int height = 0;

    //ask user for non-negative integer less than 23 and check input
    do 
    {
      printf("height: ");
      height = GetInt();
    
    }
    while ( height < 0 || height > 23);
    
    /* 
      Draw pyrimid using input as height.
    */
    if (height != 0) 
    {
   
        //declare pyramid vars
        int pyramid_tile_count = 2;
        int empty_tile_count = height - 1;
    
        //loop drawing logic
        do 
        {
            // display blank space
            int i = 0;
            while( i < empty_tile_count )
            {
                printf(" ");
                i++;
            };
            
            //display pyramid cell "#"
            int j = 0; 
            while (j < pyramid_tile_count )
            {
                printf("#");
                j++;
            };
        
            //newline and var adjustments for loop iteration
            printf("\n");
            empty_tile_count--;
            pyramid_tile_count++;
        } 
        while ( empty_tile_count >= 0 );
    };
}