#include "general.h"

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int getMax(int arr[], int size)
{
    int i, max;

    max = arr[0];
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}