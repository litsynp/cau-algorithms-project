#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include "general.h"

// Bubble sort
void bubbleSort(int arr[], int size);

// Insertion sort
void insertionSort(int arr[], int size);

// Merge sort using recursion
// merge function is called in mergeSort to merge the split arrays
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

// Recursive implementation of quick sort
// partition function is called in quickSort to partition the array and get pivot
int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);

// Counting sort modified for radix sort in order to sort within the given digit
void countingSort(int arr[], int size, int digit);

// Radix sort that utilizes counting sort for stable sort
void radixSort(int arr[], int size);

// Bucket sort that utilizes dynamically allocated buckets and countArr
void bucketSort(int arr[], int size);

#endif