/**
 * Vigenère’s Cipher by simdevrob(gmail.com)
 * v 1.1
 * 
 * A command line encrypter-cipher that requires an alphabetical
 * phrase key and uses it to encrypt a string provided by user after
 * initialization.
 * 
 * To use: 
 *   * compile
 *   * execute initialization with argument.
 * 
 * Initialization command example:
 * 
 *     $./a.out PassPhrase 
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
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// function declarations

int rot_index();
char VigenereASCII();

int main(int argc, string argv[])
{
   
    // set public vars
    string user_string = NULL;
    int error = 0;

    // check for command line argument and set vars
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)  
        
        // check and set pass_phrase
        if ( !isalpha(argv[1][i]) )
        {
       
            printf("Alphabetical Only, Please!\n");
            error = 1;
        };
    }
    else
    {
        // yell at the user politely.
        printf("Need Pass Phrase, Please!\n");   
        error = 1;
    };
    if (error == 0)
    {
        
        // get and check for user_string 
        do
            {
                user_string = GetString();
            }
        while ( user_string == NULL);

        // initialize operational vars for itteration
        int space_value = ' ';
        int i_offset = 0;

        // itterate through string and encrypt
        for (int i = 0, n = strlen(user_string); i < n; i++)
        {
            if (user_string[i] != space_value && isalpha(user_string[i]))
            {
                
                // initialize vars for filter
               
                int a_int = 'a';
                int z_int = 'z';
                int A_int = 'A';
                int Z_int = 'Z';
                
                // get index of current itteration for passphrase
                int rot_char_int = argv[1][rot_index(argv[1], i - i_offset)];
                
                // sort out capitals 
                if (rot_char_int >= a_int && rot_char_int <= z_int )
                {
                    rot_char_int= rot_char_int - a_int;
                };
                if (rot_char_int >= A_int && rot_char_int <= Z_int )
                {
                    rot_char_int = rot_char_int - A_int;
                };
                
                // mod 26 to normalize wrap around values
                rot_char_int = rot_char_int % 26;
                
                // call VigenereASCII cipher function
                char cipher_char = VigenereASCII('A','Z','a','z', user_string[i], rot_char_int );
                printf("%c" , cipher_char);
            }
            else
            {
                i_offset++;
                printf("%c", user_string[i]);
            }
        }
    };
    if (error != 0)
    {
        return error;
    }
    else
    {
        printf("\n");
        return 0;   
    };
};

// define local functions

/**
 * function rot_index( string, int )
 * 
 * A function that returns the index int for a char in 
 * string pass_phrase with relation to an itterations loop counter.
 */
int rot_index(string pass_phrase, int i_count)
            {
                int mod_factor = strlen( pass_phrase );
                return i_count % mod_factor;
            };

/**
 * function VigenereASCII( int, int, int, int, int )
 *  
 * A function that will rotate a char value by a given rotation 
 * 
 * VigenereASCII requires two ranges lowest and highest ASCII values for uppercase
 * arg[ 0, 1 ] and lowercase arg[ 2, 3 ]. Arg[4] requires integer ACSII char value 
 * and arg[ 5 ] is the rotation value. 
 */
char VigenereASCII( int lowest_upper_char, int highest_upper_char, int lowest_lower_char, int highest_lower_char, int acsii_char, int rot_value) 
{
 
    // if char is uppercase then encrypt..
    if ( acsii_char >= lowest_upper_char && acsii_char <= highest_upper_char )
    {
        int acsii_int = acsii_char + rot_value;

        // if encrypt char needs to wrap around
        if (acsii_int > highest_upper_char)
        {
            acsii_int = acsii_int - 26;
        };
        char cipher_char = acsii_int;
        return cipher_char;
    } 
            
    // if char is lowercase encrypt..
    else if( acsii_char <= highest_lower_char && acsii_char >= lowest_lower_char) 
    {
        int acsii_int = acsii_char + rot_value;

        // if encrypt char needs to wrap around
        if (acsii_int > highest_lower_char)
        {
            acsii_int = acsii_int - 26;
        };
        char cipher_char = acsii_int;
        return cipher_char;
    } 
    
    // if char is not alphabetic let it through
    else 
    {
        char cipher_char = acsii_char;
        return cipher_char;
    };
};
 