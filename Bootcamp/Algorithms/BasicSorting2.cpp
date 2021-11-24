/** @file BasicSorting2.cpp
 *  @brief Problem: the sort() function sorts the elements in ascending order.
 *  It generally takes two parameters, the first one being the point of the array/vector from where the sorting needs to begin 
    and the second parameter being the length up to which we want the array/vector to get sorted. 
    The third parameter is optional and can be used in cases such as if we want to sort the elements lexicographically.
    The basic method by which the sorting algorithm works is based on comparison.
    The sorting function, attempts to compare each and every element of the list.
    The comparison works in a way as comparing the first element with the second element, followed by second and third and so on. Here the comparison operator “<” is widely used.
    So, simply speaking, the sort function at a time, picks two values, or elements of a list, then compare these two values to identify smaller and a bigger value and arrange them in a form, ascending or descending, whichever is required.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::array<int, 10> list = { 9, 6, 3, 5, 7, 4, 2, 8, 1, 0, };
    std::cout << '\n';
    std::cout << "Sorting done with simple < operator: ";
    std::cout << '\n';
    std::sort(list.begin(), list.end());
    for (auto a : list) {
        std::cout << a << "  ";
    }
    std::cout << '\n';
    std::cout << "\n This is output of sorting using custom function: ";
    std::cout << '\n';
    struct {
        bool operator()(int a, int b) const {
            return a < b;
        }
    } customLess;
    std::sort(list.begin(), list.end(), customLess);
    for (auto a : list) {
        std::cout << a << " ";
    }
    std::cout << '\n';
}