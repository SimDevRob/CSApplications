/**
*  Finds and displays the initial letter 
*  and the letters following a space from 
*  user input and displays them together
*  in uppercase. 
*/

// includes
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    //declare vars
    string space = " ";
    
    // takes user input and checks
    string name = GetString();
    
    // iterates through each char of string
    for (int i = 0; i < strlen(name); i++)
    {
    
        // take first char and display it upper cassed
        if (i == 0)
        {
            printf("%c", toupper(name[0]));
        };
    
        // find chars following a space and display them upper cased
        if (name[i] == space[0])
        {
            printf("%c", toupper(name[i+1]));          
        };
    };
    
    // new line
    printf("\n");
}