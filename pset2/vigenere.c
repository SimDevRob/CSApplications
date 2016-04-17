/**
 * Vigenère’s cipher by simdevrob(gmail.com)
 * 
 * A cipher that takes a phrase key and encrypts a string.
 */

// includes
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int rot_index(string pass_phrase, int i_count)
            {
                int mod_factor = strlen( pass_phrase );
                return i_count % mod_factor;
            };

/**
 *  CipherASCII requires quoted 'char' for arg[0, 1, 2, 3, 4] and rotation int. 
 */
char CipherASCII( int lowest_upper_char, int highest_upper_char, int lowest_lower_char, int highest_lower_char, int acsii_char, int rot_value) 
{
 
    // if char is uppercase then encrypt
    if ( acsii_char >= lowest_upper_char && acsii_char <= highest_upper_char )
    {
        int acsii_int = acsii_char + rot_value;

        // if value needs to wrap around
        if (acsii_int > highest_upper_char)
        {
            acsii_int = acsii_int - 26;
        };
        char cipher_char = acsii_int;
        return cipher_char;
    } 
            
    // if char is lowercase encrypt
    else if( acsii_char <= highest_lower_char && acsii_char >= lowest_lower_char) 
    {
         int acsii_int = acsii_char + rot_value;

        // if char needs to wrap around
        if (acsii_int > highest_lower_char)
        {
            acsii_int = acsii_int - 26;
        };
        char cipher_char = acsii_int;
        return cipher_char;
    } 
    
    // if char is not an Alpha let it through
    else 
    {
        char cipher_char = acsii_char;
        return cipher_char;
    };
};
    
int main(int argc, string argv[])
{
    // set vars
    string user_string = NULL;
    int error = 0;

    // check command line argument and set vars
    if (argc == 2)
    {
        for (int i =0, n = strlen(argv[1]); i < n; i++)  
        // check and set pass_phrase
        if ( isalpha(argv[1][i]) )
        {
            //do nothing, it's a good thing!
        }
        else
        {
            printf("Alphabetical Only, Please!\n");
            error = 1;
        };
         
    }
    else
    {
        printf("Need Pass Phrase, Please!\n");   
        error = 1;
    };
    

    if (error == 0)
    {
        // get user_string 
        do
            {
                user_string = GetString();
            }
        while ( user_string == NULL);

        // declare vars
        int space_value = ' ';
        int i_offset = 0;

        // itterate through string and encrypt
        for (int i = 0, n = strlen(user_string); i < n; i++)
        {
            if (user_string[i] != space_value && isalpha(user_string[i]))
            {
                // cycle through keyphrase to provide rot_int
                // char rot_char = argv[1][rot_index(argv[1], i - i_offset)];
                int rot_char_int = argv[1][rot_index(argv[1], i - i_offset)];
                // rot_int = rot_int % pass_modulo;
                int a_int = 'a';
                int z_int = 'z';
                int A_int = 'A';
                int Z_int = 'Z';
                if (rot_char_int >= a_int && rot_char_int <= z_int )
                {
                    rot_char_int= rot_char_int - a_int;
                    if( rot_char_int > 26)
                    {
                        rot_char_int = rot_char_int - 26;
                    }
                };
                if (rot_char_int >= A_int && rot_char_int <= Z_int )
                {
                    rot_char_int = rot_char_int - A_int;
                     if( rot_char_int > 26)
                    {
                        rot_char_int = rot_char_int - 26;
                    }
                };
                char cipher_char = CipherASCII('A','Z','a','z', user_string[i], rot_char_int );
                printf("%c" , cipher_char);
            }
            else
            {
                i_offset++;
                printf("%c", user_string[i]);
            }
        }
    };
    // display encrypted char
    if (error != 0)
    {
        return error;
    }
    else
    {
        printf("\n");
        return 0;   
    };
}