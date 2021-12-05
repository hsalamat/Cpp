/** @file problem-6.cpp
 *  @brief Sum square difference
    Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;


long long sum_of_squares(int range)
{
	long long sumOfSquares = 0;
	for (int i = 1; i <= range; i++)
		sumOfSquares += pow(i, 2);

	return sumOfSquares;
}
long long square_of_sums(int range)
{
	long long squareOfSums = 0;
	for (int i = 1; i <= range; i++)
		squareOfSums += i;
	squareOfSums = pow(squareOfSums, 2);

	return squareOfSums;
}


int main()
{

	assert(sum_of_squares(10) == (long long) 385);
	assert(square_of_sums(10) == (long long) 3025);


	cout << endl << 
		"the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum : " 
		<< square_of_sums(100) - sum_of_squares(100) << endl;
}
