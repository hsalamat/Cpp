/** @file BinarySearch.cpp
 *  @brief Problem: Binary Search: Search a sorted array by repeatedly dividing the search interval in half.   
    Begin with an interval covering the whole array. 
    If the value of the search key is less than the item in the middle of the interval, 
    narrow the interval to the lower half. Otherwise, narrow it to the upper half. 
    Repeatedly check until the value is found or the interval is empty.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

 // C++ program to implement recursive Binary Search
#include <iostream>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

//! Here is recursive implementation with check function which is a much easier implementation:
// define array globally
const int N = 1e6 + 4;

int a[N];
int n; // array size

// element to be searched in array
int k;

bool check(int dig)
{
    // element at dig position in array
    int ele = a[dig];

    // if k is less than
    // element at dig position
    // then we need to bring our higher ending to dig
    // and then continue further
    if (k <= ele) {
        return 1;
    }
    else {
        return 0;
    }
}
void binsrch(int lo, int hi)
{
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    // if a[lo] is k
    if (a[lo] == k)
        cout << "Element found at index "
        << lo; // 0 based indexing
    else
        cout
        << "Element doesnt exist in array"; // element
                                            // was not in
                                            // our array
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;

    cout << endl << "enter n elements: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;

    // it is being given array is sorted
    // if not then we have to sort it

    // minimum possible point where our k can be is starting
    // index so lo=0 also k cannot be outside of array so end
    // point hi=n

    binsrch(0, n);
    return 0;
}