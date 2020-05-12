#ifndef _CLI_H_
#define _CLI_H_

#include "general.h"

// Initializes variables with memory allocation
void initVariables();

// Sorts and measure execution times
void doBubbleSort();
void doInsertionSort();
void doMergeSort();
void doQuickSort();
void doRadixSort();
void doBucketSort();

// Prints the input arrays before sorting
void printInputArraysBeforeSorting();

// Prints the input arrays after sorting
void printInputArraysAfterSorting();

// Prints the execution times for each arrays taken for the algorithm
void printExecutionTime();

// Frees memories allocated in initVariables
void freeInputArrayMemories();

#endif