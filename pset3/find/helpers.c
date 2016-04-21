/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 * simdevrob(gmail.com)
 *
 * Helper functions for Problem Set 3.
 */
#include <stdio.h>    
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

/**
int binarySearch(int key,int array[], int min, int max )
{
  
    
    //printf("BIN Search clalled");
    int mid_index = min + ((max - min) / 2);


    // catch end loop
    if ( max < min ) {
        return 1;
    }
    if ( mid_index <= 1 && array[mid_index] == key ) 
    {
            printf("Value of: %i found!\n", array[mid_index]);
            return 0;
    }    
    else
    {
        return 1;
    }
    
        if ( array[mid_index] < key)
        {
           printf("midpoint: %i with value: %i\n", mid_index, array[mid_index]);
           return binarySearch(key, array, min + mid_index, max);
        }
        else if ( array[mid_index] > key)
        {
           printf("midpoint: %i with value: %i\n", mid_index, array[mid_index]);
           return binarySearch(key, array, min , max - mid_index );
        };
    if ( array[mid_index] == key)
    {
        //printf("Value of: %i found!\n", array[mid_index]);
        return 0;
    }
    printf("ended with 1");
    return 1;
  
};
   **/
   
/**
 *  Binary Search : 
 *  templated from http://www.programmingsimplified.com/c/source-code/c-program-binary-search
 *  customized by simdevrob(gmail.com)
 */
bool search(int value, int values[], int n)
{
    //int error = binarySearch(value, values, 0,  n - 1 );
    int first, last, middle;
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    
    while ( first <= last) 
    {
        if (values[middle] < value)
        first = middle + 1;
        else if ( values[middle] == value)
        {
           printf("%i found at [%i]\n", value, middle + 1 );
            return true;
        }
        else
        
        last = middle - 1;
        middle = (first + last) / 2;
        

    };
   
        
    return false;
    
};

/**
 * Sorts array of n values.
 */
void sort( int values[], int n )
{
    // Insertion Sort
    int i, d, t;
    
    for ( i = 1 ; i <= n - 1; i++)
    {
        d = i ;
        
        while ( d > 0 && values[d] < values[d - 1 ]) {
            t = values[d];
            values[d] = values[d - 1];
            values[d - 1] = t;
            
            d--;
        }
    };
    
    for ( i = 0; i <= n - 1; i++) 
    {
        //values[i] = values[i];
       // printf("[%i]%i", i, values[i]);
    }
}