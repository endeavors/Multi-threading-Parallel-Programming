/*
 * Filename: sequentialSquaredSumMinMax.cpp
 * Author: Gurkirat Singh
 * Description: This file calculates the square of a number inside the array.
 *              The array is fed in its entirety but it is divided into
 *              serveral subarrays.
 */

#include "pamt1.h"

/*
 * Function name: sequentialSquaredSumMinMax()
 * Function prototype:
 *     struct result sequentialSquaredSumMinMax(char a[], int lo, int hi);
 * Description: This function takes in a low index and high index of the array
 *              and then squares each element in it and puts the result back
 *              in the struct named result.
 * Parameters:
 *      arg1: char a[] -- array that contains chars to be squared
 *      arg2: int lo -- index of the array where we need to start
 *      arg2: int hi -- index of array where we can go maximum
 * Side Effects: None
 * Error Conditions: None. Error Conditions are performed in main
 * Return Value: returns the entire struct
 */

struct result sequentialSquaredSumMinMax(char a[], int lo, int hi)
{
    int index; /*index that will be our counter inside array*/
    struct result result; /*struct with prototype that will hold our values*/

    /*No negative indexes are allowed */
    if (lo < 0 || hi < 0) return result;

    /*Initialize struct values*/
    result.min = a[0];
    result.max = a[0];
    result.sum = 0;

    for (index = lo; index < hi; index++){
       
        /*Get the value at particular index of array*/
        long num = a[index];
        /* Square the number */
        long square = num * num;
        
	/*Check if we have found a minimum or a maximum */
        if (num < result.min) result.min = num;
        if (num > result.max) result.max = num;
        
	/*Keep adding the sum of the squares*/
        result.sum += square;        
    }

    /*Return the entire struct*/
    return result;
}
