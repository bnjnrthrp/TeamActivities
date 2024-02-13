#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    return 0; // modify to return the index of the min value
}

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: Selectionsort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    // todo: implement selection sort
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    // TODO: Implement insertion sort
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    // Outer loop iterates through whole array. Each iteration tells us how many elements are in the sorted side.
    int num_swaps;
    for (int i = 0; i < size - 1; i++)
    {
        num_swaps = 0; // reset swap counter to 0 at the top of the loop
                       // Inner loop starts at 0 and goes until the end of the unsorted list
        for (int j = 0; j < size - 1 - i; j++)
        {
            // compares j and the element to its right, swaps if j is larger.
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                num_swaps++; // Increment the swap counter for this cycle.
            }
        }
        if (num_swaps == 0)
        {          // if we went through the entire array without needing a swap
            break; // then its all sorted and we can break
        }

        // now that we're done swapping print the current state of the array
        if (print)
        {
            printIntArray(array, size);
        }
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;

    int i = l;
    int j = m + 1;
    int start = l;

    // While we loop through the left side
    while (i <= m && j <= r)
    {
        // Compare left side index to right side index
        if (arr[i] < arr[j])
        {
            temp[start] = arr[i];
            start++;
            i++;
        }
        else
        {
            // Add right side to the temp array
            temp[start] = arr[j];
            start++;
            j++;
        }
    }
    // finish adding the leftover right side
    while (j <= r)
    {
        temp[start] = arr[j];
        start++;
        j++;
    }
    // leftover on the left, finish adding to array
    while (i <= m)
    {
        temp[start] = arr[i];
        start++;
        i++;
    }
    // copy temp array to original array
    for (i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void mergeSort(int arr[], int temp[], int l, int r)
{
    // recursion if r > l
    if (r > l)
    {
        //  1. Find the middle point 'm' to divide the array into two halves:

        int m = (l + r) / 2;
        //  2. divide the first half:
        mergeSort(arr, temp, l, m);
        //  3. divide the second half:
        mergeSort(arr, temp, m + 1, r);
        //  4. Merge the two halves sorted in step 2 and 3:
        merge(arr, temp, l, m, r);
    }
}

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    if (temp == NULL)
    {
        printf("array was null\n");
        exit(1);
    }
    mergeSort(array, temp, 0, size - 1);
    free(temp);
}

// provided code

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif