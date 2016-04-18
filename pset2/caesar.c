/**
 *   Hail Caesar!! by simdevrob(gmail.com)
 *   v1.0 - 04-17-2016
 * 
 * A command-line cipher-encrypter that requires an integer command-line argument
 * and uses it to encrypt a string provided by user after initialization.
 * 
 * To use: 
 *   * compile
 *   * execute initialization with argument.
 * 
 * Initialization command example:
 * 
 *     $./a.out 13 
 *
 * User is then prompted for a string that will be encrypted. The cipher will
 * display the "encrypted string" and then exit with a return int of 0 if no errors
 * where thrown.
 * 
 * Return 0 - No Errors
 * Return 1 - Problem validating commmand argument 
 * 
 * 
 */
 
// includes
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// function declars
char CipherASCII();

// run main routine    
int main(int argc, string argv[])
{
    // declare vars
    int rot_int;
    string user_string;
    
    // check command-line argument and set vars
    if (argc == 2)
    {
        rot_int = atoi(argv[1]) % 26;
       
        // ask for string from user and checks for input
        do
        {
            user_string = GetString();
        }
        while(strlen(user_string) == 0);
    }
    else
    {
        // Yells at user if command-line int is not provided
        printf("Please provide a non-negative int!\n");    
        return 1;
    };
    
    // itterates through string and finds int for each char
    for (int i = 0, n = strlen(user_string); i < n; i++)
    {
        char display_char = CipherASCII('A', 'Z', 'a', 'z', user_string[i], rot_int);
        printf("%c", display_char);
    };
    printf("\n");
    return 0;
}

// define local functions
/**
 *  CipherASCII requires quoted 'char' for arg[0, 1, 2, 3, 4] and rotation int. 
 */
char CipherASCII( int lowest_upper_char, int highest_upper_char, int lowest_lower_char, int highest_lower_char, int acsii_char, int rot) 
            {
                // if char is uppercase then encrypt
                if ( acsii_char >= lowest_upper_char && acsii_char <= highest_upper_char )
                {
                    acsii_char = acsii_char + rot;

                    // if value needs to wrap around
                    if (acsii_char > highest_upper_char)
                    {
                        acsii_char = acsii_char - 26;
                    };
                     char cipher_char = acsii_char;
                     return cipher_char;
                } 
                
                // if char is lowercase ..
                else if( acsii_char <= highest_lower_char && acsii_char >= lowest_lower_char) 
                {
                    // ..encrypt
                    acsii_char = acsii_char + rot;

                    // if char needs to wrap around
                    if (acsii_char > highest_lower_char)
                    {
                        acsii_char = acsii_char - 26;
                    };
                    char cipher_char = acsii_char;
                    return cipher_char;
        } 
        
        // if char is not an Alpha let it through
        else 
        {
            char cipher_char = acsii_char;
            return cipher_char;
        };
    };
    
    