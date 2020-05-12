#include "algorithms.h"

// Temporary array for merge sort and radix sort
int* tempArr;

// Temporary array for count sort and bucket sort
// For bucket sort: Stores how many elements are currently stored in each bucket
int* countArr;

// Buckets for bucket sort
// buckets[i*bucketSize + j] == buckets[i][j]
// i: which bucket
// j: index within each bucket
// max(i) = bucketCount - 1
// max(j) = bucketSize - 1
// bucketCount * bucketSize = size of array
int* buckets;

// number of buckets in bucket sort
int bucketCount;

// size of each bucket (default is the input array size)
int bucketSize;

void bubbleSort(int arr[], int size)
{
    int i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&(arr[j]), &(arr[j + 1]));
}

void insertionSort(int arr[], int size)
{
    int i, j, key;

    // key: to be inserted
    // arr[j]: to be compared
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i;

        // Sort until (i - 1)th index by moving the key until it fits
        while ((--j >= 0) && (arr[j] > key))
            arr[j + 1] = arr[j];
        
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k, h;

    i = left;
    j = mid + 1;
    k = left;

    while ((i <= mid) && (j <= right))
    {
        if (arr[i] <= arr[j])
            tempArr[k++] = arr[i++];
        else
            tempArr[k++] = arr[j++];
    }

    while (i <= mid)
        tempArr[k++] = arr[i++];

    while (i <= mid)
        tempArr[k++] = arr[j++];

    // Copy to the original array
    for (h = left; h <= right; h++)
        arr[h] = tempArr[h];
}

void mergeSort(int arr[], int left, int right)
{
    int mid;

    // Sort recursively
    if (left < right)
    {
        mid = (left + right) / 2;       // Divide the list into two sublists

        mergeSort(arr, left, mid);      // Split 0 to mid
        mergeSort(arr, mid + 1, right); // Split 1 to n
        merge(arr, left, mid, right);   // Merge two lists
    }
}

int partition(int arr[], int left, int right)
{
    int pivot, low, high;

    // Set pivot as the leftmost element
    pivot = arr[left];
    low = left + 1;
    high = right;

    while (low <= high) // Until left meets right
    {
        // Find values bigger than pivot - shift low to right side one by one
        while ((low <= right) && (pivot >= arr[low]))
            low++;

        // Find values smaller than pivot - shift high to left side one by one
        while ((high >= (left + 1)) && (pivot <= arr[high]))
            high--;

        if (low <= high)
            swap(&(arr[low]), &(arr[high]));
    }

    swap(&(arr[left]), &(arr[high]));

    // Return the pivot index
    return high;
}

void quickSort(int arr[], int left, int right)
{
    int pivot;

    if (left < right)
    {
        // Partition the array and get the pivot
        pivot = partition(arr, left, right);

        // Recursively call quickSort for left and right side of the pivot
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

// tempArr acts as a output array
// countArr saves the counts of occurences
void countingSort(int arr[], int size, int digit)
{
    int i;

    // Step 1. Initialization
    for (i = 0; i < 10; i++)
        countArr[i] = 0;

    // Step 2. Save counts
    for (i = 0; i < size; i++)
        countArr[(arr[i] / digit) % 10]++;

    // Step 3. Accumulation
    for (i = 1; i < 10; i++)
        countArr[i] += countArr[i - 1];

    // Step 4. Reordering
    for (i = size - 1; i >= 0; i--) {
        tempArr[countArr[(arr[i] / digit) % 10] - 1] = arr[i];
        countArr[(arr[i] / digit) % 10]--;
    }

    // Copy to the original array
    for (i = 0; i < size; i++)
        arr[i] = tempArr[i];
}

void radixSort(int arr[], int size)
{
    int digit, max;

    // Get the maximum value in the array
    max = getMax(arr, size);

    // Sort every digit using stable sort (counting sort)
    for (digit = 1; max / digit > 0; digit *= 10)
        countingSort(arr, size, digit);
}

// countArr acts as a storage of how many elements are stored in each bucket
void bucketSort(int arr[], int size)
{
    int i, bucketIndex, index, max;

    // Get the maximum value in the array to determine the range for each bucket
    max = getMax(arr, size);

    // Step 1. Create an array of empty buckets with size of as much as the size of array
    // Done outside the function

    // Step 2. Scatter the elements into each bucket
    for (i = 0; i < size; i++)
    {
        bucketIndex = (int)floor(((bucketCount - 1) * arr[i]) / max);
        buckets[bucketIndex * bucketSize + countArr[bucketIndex]] = arr[i];
        countArr[bucketIndex]++;
    }

    // Step 3. Sort the elements in each bucket
    for (i = 0; i < bucketCount; i++)
        insertionSort(buckets + i * bucketSize, countArr[i]);

    // Step 4. Gather
    index = 0;
    for (int i = 0; i < bucketCount; i++)
        for (int j = 0; j < countArr[i]; j++)
            arr[index++] = buckets[i * bucketSize + j];
}