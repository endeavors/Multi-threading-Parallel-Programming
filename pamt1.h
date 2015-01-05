#ifndef PAMT_H   /* Macro Guard */
#define PAMT_H

#include <thread>



struct result sequentialSquaredSumMinMax( char a[], int lo, int hi );
void initData( char a[], int size );
void usage( char* filename );

/*
 * The number of concurrent threads that the current machine can support.
 */

const int numOfThreads = std::thread::hardware_concurrency();

/*
 * The data structure to encapsulate the results of the calculations.
 */

struct result
{
  long long sum;
  int min;
  int max;
};

#endif
