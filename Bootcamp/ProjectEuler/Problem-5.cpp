/** @file problem-5.cpp
 *  @brief Smallest multiple
	2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;


int findSmallDivisbile(int range)
{
	bool result = false;
	int number = 10;
	bool found = true;
	while (true)
	{
		found = true;
		number++;
		for (int i = 2; i <= range; i++)
			if (number % i != 0) found = false;
         
		if (found == true) 
			return number;
	}
	return number;

}


int main()
{

	assert(findSmallDivisbile(10) == 2520);

	cout << endl << 
		"the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 :  " 
		<< findSmallDivisbile(20) << endl;
}
