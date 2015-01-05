#include <stdlib.h>
#include <stdio.h>
#include "pamt1.h"

/*
 * Function name: initData()
 * Function prototype: void initData( char a[], int size );
 * Description: Initializes an array a of length size with random values
 * Parameters: a[]    array to be populated with random values
 *             size   size of the array to be populated
 * Side Effects: After call to this function, the array a[] will contain
 *               random values.
 * Error Conditions: None.
 */

void initData( char a[], int size )
{
   int i, j;
   int *arr = (int *) a; // Use arr as an array of int
   int div4 = size / 4;  // # of 4-byte ints to write into the array
   int mod4 = size % 4;  // # of trailing bytes

   srand( 41 );

   /* Slam an int into 4 consecutive bytes vs. one byte at at time. */
   for ( i = 0; i < div4; ++i )
   {
     arr[i] = rand(); // Initializing 4 bytes at a time.

     /* Let the user know we are still working and not hung. */
     if ( (i % 10000000) == 0 )
     {
       (void) fprintf( stderr, "%s", "." );
     }
   }

   /*
    * Take care of the remaining bytes one byte at a time from the next
    * random int returned by rand().
    */
   int randValue = rand();

   i = i * 4;
   for ( j = 0; j < mod4; ++j )
   {
     a[i++] = randValue << (j * 8) >> 24;
   }
  
   fprintf( stderr, "%s", " Done\n\n" );
}
