/** @file MergeSort.cpp
 *  @brief merge sort
    Like QuickSort, Merge Sort is a Divide and Conquer algorithm. 
    It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. 
    The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process 
    that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merges two subarrays of vector.
// First subarray is vec[begin..mid]
// Second subarray is vec[mid+1..end]
void merge(vector<int> vec, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = vec[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = vec[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            vec[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            vec[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        vec[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        vec[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-vector
// of vec to be sorted 
void mergeSort(vector<int> vec, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(vec, begin, mid);
    mergeSort(vec, mid + 1, end);
    merge(vec, begin, mid, end);
}

void printArray(vector<int> list)
{
    for (int a : list)
        cout << a << endl;
}


int main()
{

    vector<int> vec = { 12, 11, 13, 5, 6, 7 };

    cout << "Given array is \n";
    printArray(vec);

    mergeSort(vec, 0, vec.size() - 1);

    cout << "\nSorted vector is \n";
    printArray(vec);
    return 0;
}