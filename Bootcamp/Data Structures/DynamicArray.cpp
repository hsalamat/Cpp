/** @file DynamicArray.cpp
 *  @brief Dynamic Array
	A dynamic array should be deleted from the computer memory once its purpose is fulfilled.
	The delete statement can help you accomplish this.
	The released memory space can then be used to hold another set of data.
	However, even if you do not delete the dynamic array from the computer memory,
	it will be deleted automatically once the program terminates.

	Note:
	To delete a dynamic array from the computer memory, you should use delete[], instead of delete.
	The [] instructs the CPU to delete multiple variables rather than one variable.
	The use of delete instead of delete[] when dealing with a dynamic array may result in problems.
	Examples of such problems include memory leaks, data corruption, crashes, etc.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include<iostream>
using namespace std;
int main() {
	int x, n;
	cout << "How many numbers will you type?" << "\n";
	cin >> n;

	int* arr = new int(n);

	cout << "Enter " << n << " numbers" << endl;
	for (x = 0; x < n; x++) {
		cin >> arr[x];
	}
	cout << "You typed: ";
	for (x = 0; x < n; x++) {
		cout << arr[x] << " ";
	}
	cout << endl;

	return 0;
}