# CAU 2020 Algorithms Project
This program calculates the worst case execution time in microseconds for six different sorting algorithms.

## Sorting Algorithms Implemented
There are six sorting algorithms included.
- Bubble Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Radix Sort (using count sort for each digit as a stable sort internally)
- Bucket Sort (using insertion sort for sorting bucket elements)

## System Environment
- This program utilizes **windows.h** header to calculate the execution time in microseconds.
- Hence, Windows is necessary.
- Tested on Windows 10 with Visual Studio 2019

## Navigation
- You can just follow the guidance of the menu, and simply press numbers between 0 to 6 and enter.

## Notice
### Regarding Input Arrays
- The input arrays are all dynamically allocated, and initialized as the worst cases for each input size.
- That is, they are initialized in decreasing order.
- The input sizes are **10**, **100**, and **1000**.
- For example, the array elements in the array with a size 10 are { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }.

### Regarding the Bucket Sort
- The data structure used for buckets is an 1D array, but works as an 2D array.
- The numbers of buckets for the bucket sort are 5, 10, and 20 for the input sizes 10, 100, and 1000, respectively.
- The bucket size for each bucket is set to be the size of array.

### Regarding the Execution Times of Each Algorithm
- Some algorithms including bucket sort use temporary arrays that are dynamically allocated and initialized to 0.
- Their execution times do not include the allocation and initialization times of the arrays.
