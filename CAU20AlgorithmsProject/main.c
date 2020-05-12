#define _CRT_SECURE_NO_WARNINGS
#include "cli.h"

#define BUBBLE_SORT     1
#define INSERTION_SORT  2
#define MERGE_SORT      3
#define QUICK_SORT      4
#define RADIX_SORT      5
#define BUCKET_SORT     6

int main()
{
    int showInputAns = 0;
    int whichAlgo = 0;


    printf("Show Inputs? (0: no, 1: yes): ");
    scanf("%d", &showInputAns);

    while (1)
    {
        printf("-----------------------------\n");
        printf("Choose your algorithm:\n");
        printf("0. Exit without sort\n");
        printf("1. Bubble sort\n");
        printf("2. Insertion sort\n");
        printf("3. Merge sort\n");
        printf("4. Quick sort\n");
        printf("5. Radix sort\n");
        printf("6. Bucket sort\n");
        printf("Which algorithm? (n=0-6): ");
        scanf("%d", &whichAlgo);

        printf("\n");

        if (whichAlgo < 1 || whichAlgo > 6) {
            printf("Exiting the program...\n");
            break;
        }

        printf("Creating arrays...\n");

        initVariables();

        if (showInputAns)
            printInputArraysBeforeSorting();

        /************************************/
        /*                                  */
        /*               Sort               */
        /*                                  */
        /************************************/
        printf("\nSorting...\n\n");
        switch (whichAlgo)
        {
        case BUBBLE_SORT:
            printf("[Bubble Sort]\n");
            doBubbleSort();
            break;
        case INSERTION_SORT:
            printf("[Insertion Sort]\n");
            doInsertionSort();
            break;
        case MERGE_SORT:
            printf("[Merge Sort]\n");
            doMergeSort();
            break;
        case QUICK_SORT:
            printf("[Quick Sort]\n");
            doQuickSort();
            break;
        case RADIX_SORT:
            printf("[Radix Sort]\n");
            doRadixSort();
            break;
        case BUCKET_SORT:
            printf("[Bucket Sort]\n");
            doBucketSort();
            break;
        default:
            break;
        }

        printExecutionTime();

        printf("\n");

        if (showInputAns)
            printInputArraysAfterSorting();

        printf("Freeing memories...\n");
        freeInputArrayMemories();
    }

    return 0;
}