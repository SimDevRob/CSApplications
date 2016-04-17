/**
 *   Hail Ceaser!! by simdevrob(gmail.com)
 * 
 *  This is a basic encryption application in C.
 *  It requires a a non negative integer 
 *  command line argument. The user is then
 *  asked for a string.
 * 
 *  The output will be a "rotation" of each char
 *  string. 
 */
 
// includes
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
// function declars

int main(int argc, string argv[])
{
    // declare vars
    int rot_int;
    string user_string;
    
    // check command line argument and set vars
    if (argc == 2)
    {
        rot_int = atoi(argv[1]) % 26;
       
        // ask for string from user and checks
        do
        {
            user_string = GetString();
        }
        while(strlen(user_string) == 0);
    }
    else
    {
        printf("a non-negative int was not provided!\n");    
        return 1;
    };
    
    // itterates through string and finds int for each char
    for (int i = 0, n = strlen(user_string); i < n; i++)
    {
        
        // seperate char upper case alphas from symbols and rotate
        int char_int = user_string[i];
        int cypher_sum;
        if (char_int <= 90 && char_int >= 65 )
        {
            char_int = char_int - 65;
            cypher_sum = char_int + rot_int;
            int cypher_ascii_int = cypher_sum + 65;
            if (cypher_ascii_int > 90)
            {
                cypher_ascii_int = cypher_ascii_int - 26;
            }
            char cypher_char = cypher_ascii_int;
            printf("%c", cypher_char);
        }
        else if( char_int <= 122 && char_int >= 97) 
        {
            char_int = char_int - 97;
            cypher_sum = char_int + rot_int;
            int cypher_ascii_int = cypher_sum + 97;
            if (cypher_ascii_int > 122)
            {
                cypher_ascii_int = cypher_ascii_int - 26;
            }
            char cypher_char = cypher_ascii_int;
            printf("%c", cypher_char);
        } 
        else 
        {
            char cypher_char = char_int;
            printf("%c", cypher_char);
        };
    };
    printf("\n");
    return 0;
}