
/**
 * Recursive Binary Search
 * 
 *  This is an example call to a recursive binary search
 *  int error = binarySearch(value, values, 0,  n - 1 );
 * 
 *  **In Development 
 */
 
 /*
    
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