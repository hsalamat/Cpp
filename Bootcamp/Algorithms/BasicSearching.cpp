/** @file BasicSearching.cpp
 *  @brief Problem: Given an array arr[] of n elements, write a function to search a given element x in arr[].
 *  A simple approach is to do a linear search, i.e
 *  Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
 *   If x matches with an element, return the index.
 *   If x doesn’t match with any of elements, return -1.
 *  The time complexity of the above algorithm is O(n).   
 *  Linear search is rarely used practically because other search algorithms such as the binary search algorithm 
 *  and hash tables allow significantly faster-searching comparison to Linear search.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}


//! Improve Linear Search Worst-Case Complexity
//! if element Found at last  O(n) to O(1)
//! It is the same as previous method because here we are performing 2 ‘if’ operations in one iteration of the loop 
//! and in previous method we performed only 1 ‘if’ operation.This makes both the time complexities same.
void search2(vector<int> arr, int search_Element)
{
    int left = 0;
    int length = arr.size();
    int position = -1;
    int right = length - 1;

    // Run loop from 0 to right
    for (left = 0; left <= right;)
    {

        // If search_element is found with
        // left variable
        if (arr[left] == search_Element)
        {

            position = left;
            cout << "Element found in Array at "
                << position + 1 << " Position with "
                << left + 1 << " Attempt";

            break;
        }

        // If search_element is found with
        // right variable
        if (arr[right] == search_Element)
        {
            position = right;
            cout << "Element found in Array at "
                << position + 1 << " Position with "
                << length - right << " Attempt";

            break;
        }
        left++;
        right--;
    }

    // If element not found
    if (position == -1)
        cout << "Not found in Array with "
        << left << " Attempt";
}


int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    //! Linear Search Call
    int result = search(arr, n, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result << endl;

    vector<int> arr2{ 1, 2, 3, 4, 5 };
    int search_element = 5;

    //!Linear search call on both sides
    search2(arr2, search_element);

    return 0;
}