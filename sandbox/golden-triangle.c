/**
 *  Take three integer inputs from the user and see if 
 *  they can make a triangle
 * 
 */
 
// includes
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    // initialize vars
    int lengths[3] = { 0, 0, 0};
   
    // ask for each input and check it for positive int
    do
    {
      for (int i = 0; i < 3; i++)
      {
          printf("please insert length %d:\n", i + 1);
          lengths[i] = GetInt();
      };

    }
    while (lengths[0] <= 0 || lengths[1] <= 0 || lengths[2] <= 0);
    
    // calculate that the sum of two of the lengths is less than the largest length
    
    
        
    }
     
}