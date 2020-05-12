#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "algorithms.h"

#define NUM_CASES 3

// Swaps two variables
void swap(int* i, int* j);

// Gets the maximum element in an array
int getMax(int arr[], int size);

// Prints all elements in an array
void printArray(int arr[], int size);

#endif