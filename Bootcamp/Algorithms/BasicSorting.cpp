/** @file BasicSorting.cpp
 *  @brief the sort() function sorts the elements in ascending order.
 *  C++ uses sort () built-in function for their algorithms to sort the containers like vectors, arrays.
 *  Sort(array , array +size);
 *  It generally takes two parameters, the first one being the point of the array/vector from where the sorting needs to begin 
    and the second parameter being the length up to which we want the array/vector to get sorted. 
    The third parameter is optional and can be used in cases such as if we want to sort the elements lexicographically.
    The basic method by which the sorting algorithm works is based on comparison.
    The sorting function, attempts to compare each and every element of the list.
    The comparison works in a way as comparing the first element with the second element, followed by second and third and so on. Here the comparison operator “<” is widely used.
    So, simply speaking, the sort function at a time, picks two values, or elements of a list, then compare these two values to identify smaller and a bigger value and arrange them in a form, ascending or descending, whichever is required.
    The order of complexity is given by 0(N*log(N)).    
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(arr, arr + n);

    cout << "\nArray after sorting using "
        "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}