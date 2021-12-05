/** @file problem-9.cpp
 *  @brief Special Pythagorean triplet
 *  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

	a^2 + b^2 = c^2
	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
	 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <array>
using namespace std;

array<int, 3> findPythoagoreanTriplet(int number)
{

	array<int, 3> triplet = { 0,0,0 };

	for (int a = 1; a <= number; a++) {
		for (int b = 1; b <= number ; b++) {
			for (int c = 1; c <= number ; c++) {
				if (a + b + c == number)
				{
					if (pow(a, 2) + pow(b, 2) == pow(c, 2))
					{
						triplet[0] = a;
						triplet[1] = b;
						triplet[2] = c;
						return triplet;
					}
				}
			}
		}
	}
	return triplet;
}

int main()
{

	array<int, 3> triplet =  findPythoagoreanTriplet(1000);
       
	cout << "the product abc : " << triplet[0] * triplet[1] * triplet[2];
	return 0;
}