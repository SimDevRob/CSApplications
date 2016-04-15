#include <cs50.h>
#include <stdio.h>

/* 
  Asks user for a shower time length and
  displays the number of bottles aprox.
  used in a shower
*/
int main(void)
{
    //declare vars
   int bottles_min = 12;
   int time_length = 0;

   // ask for time from user in minutes
   printf("minutes: ");
   time_length = GetInt();
   
   //calculate the water used
   int bottles_used = time_length * bottles_min;
   printf("bottles: %d \n", bottles_used);
   
}