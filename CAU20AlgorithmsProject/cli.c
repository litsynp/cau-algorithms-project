#include "cli.h"

extern int* tempArr;
extern int* countArr;
extern int* buckets;
extern int bucketCount;
extern int bucketSize;

// To measure time in micro seconds
LARGE_INTEGER startTime, endTime, frequency;
double execTimes[NUM_CASES];

// Input arrays and their corresponding sizes
int* inputs[NUM_CASES];
int sizes[NUM_CASES] = { 10, 100, 1000 };

// Number of buckets for bucket sort for each input arrays 
int bucketCounts[NUM_CASES] = { 5, 10, 20 };

void initVariables()
{
    int i, j;

    // Create input arrays
    for (i = 0; i < NUM_CASES; i++)
        inputs[i] = (int*)malloc(sizeof(int) * sizes[i]);

    // Initialize input arrays
    for (i = 0; i < NUM_CASES; i++)
    {
        for (j = 0; j < sizes[i]; j++)
            inputs[i][j] = sizes[i] - j;
    }
}

void doBubbleSort()
{
    int i;

    for (i = 0; i < NUM_CASES; i++)
    {
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
        bubbleSort(inputs[i], sizes[i]);
        QueryPerformanceCounter(&endTime);

        execTimes[i] = (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart;
    }
}

void doInsertionSort()
{
    int i;

    for (i = 0; i < NUM_CASES; i++)
    {
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
        insertionSort(inputs[i], sizes[i]);
        QueryPerformanceCounter(&endTime);

        execTimes[i] = (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart;
    }
}

void doMergeSort()
{
    int i;

    for (i = 0; i < NUM_CASES; i++)
    {
        // Allocate memory to temporary array to store sorted data for merge sort
        tempArr = malloc(sizeof(int) * sizes[i]);

        // Sort and measure the time
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
        mergeSort(inputs[i], 0, sizes[i] - 1);
        QueryPerformanceCounter(&endTime);

        execTimes[i] = (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart;

        // Free the memory
        free(tempArr);
    }
}


void doQuickSort()
{
    int i;

    for (i = 0; i < NUM_CASES; i++)
    {
        // Sort and measure the time
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
        quickSort(inputs[i], 0, sizes[i] - 1);
        QueryPerformanceCounter(&endTime);

        execTimes[i] = (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart;
    }
}

void doRadixSort()
{
    int i;

    for (i = 0; i < NUM_CASES; i++)
    {
        // Allocate memory to temporary array
        tempArr = malloc(sizeof(int) * sizes[i]);
        countArr = malloc(sizeof(int) * 10);

        // Sort and measure the time
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
        radixSort(inputs[i], sizes[i]);
        QueryPerformanceCounter(&endTime);

        execTimes[i] = (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart;

        // Free the memory
        free(tempArr);
        free(countArr);
    }
}

void doBucketSort()
{
    int i;

    for (i = 0; i < NUM_CASES; i++)
    {
        bucketSize = sizes[i];
        bucketCount = bucketCounts[i]; // 5 for array of length 10

        // Initialize buckets
        buckets = malloc(bucketCount * bucketSize * sizeof(int));
        for (int i = 0; i < bucketCount * bucketSize; i++)
            buckets[i] = 0;

        // Initialize count array for buckets
        countArr = (int*)malloc(sizeof(int) * bucketCount);
        for (int i = 0; i < bucketCount; i++)
            countArr[i] = 0;

        // Sort and measure the time
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&startTime);
        bucketSort(inputs[i], sizes[i]);
        QueryPerformanceCounter(&endTime);

        execTimes[i] = (double)(endTime.QuadPart - startTime.QuadPart) / (double)frequency.QuadPart;

        // Free the memories
        free(countArr);
        free(buckets);
    }
}


void printInputArraysBeforeSorting()
{
    int i;

    // Print arrays before sorting
    printf("[Before sorting]\n");
    for (i = 0; i < NUM_CASES; i++)
    {
        printf("inputs[%d] (size: %d):\n", i, sizes[i]);
        printArray(inputs[i], sizes[i]);
    }
    printf("\n");
}

void printInputArraysAfterSorting()
{
    int i;

    // Print arrays after sorting
    printf("[After sorting]\n");
    for (i = 0; i < NUM_CASES; i++)
    {
        printf("inputs[%d] (size: %d):\n", i, sizes[i]);
        printArray(inputs[i], sizes[i]);
    }
    printf("\n");
}

void printExecutionTime()
{
    int i;

    // Print execution times for each input arrays
    printf("[Execution Times]\n");
    for (i = 0; i < 3; i++)
    {
        printf("inputs[%2d] (size: %5d) execTime: %lf\n", i, sizes[i], execTimes[i]);
    }
}

void freeInputArrayMemories()
{
    int i;

    // Free memories of input arrays
    for (i = 0; i < 3; i++)
        free(inputs[i]);
}