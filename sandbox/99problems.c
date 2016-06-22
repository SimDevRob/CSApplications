/**
 * Make an array of 100 using the index as the value
 * and not hate my last ex. 
 */
 
 #include <stdio.h>
 
 int main(void)
 {
    //iterate values in an array from 0 to 99
    int number_array[99];
    for(int j = 0; j <= 99; j++ )
    {
        number_array[j] = j;
        printf("%d\n", number_array[j]);
    };
 }