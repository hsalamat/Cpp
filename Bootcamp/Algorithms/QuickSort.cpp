/** @file QuickSort.cpp
 *  @brief quick sort
    This technique follows the divide and conquers algorithm and is considered very efficient and quicker for huge arrays. 
    They are divided into three subsections: a left, a right and the middle. 
    The middle element has a single value, and it is named as the pivot. 
    The mechanism goes like this, the element in the left segment should not have a key larger than the middle element 
    and the no element in the right has a key that is smaller than that of the middle element. 
    Quicksort uses a recursive concept while sorting sub-part. The array is divided into subpart, again left and right segments 
    are partitioned by conquering.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(vector<int> arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
  arr --> vector to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(vector<int> list)
{
    for (int a : list)
        cout << a << endl;
}

int main()
{
    //int arr[] = { 10, 7, 8, 9, 1, 5 };
    vector<int> vec = { 10, 7, 8, 9, 1, 5 };
    
    //int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(vec, 0, vec.size() -1);
    printf("Sorted vector: \n");
    printArray(vec);
    return 0;
}