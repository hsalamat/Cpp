/** @file problem-7.cpp
 *  @brief 10001st prime
	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

	What is the 10001st prime number?
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


bool isPrime(int number)
{
	bool result = true;

	for (int i = 2; i < number; i++)
		if (number % i == 0) return false;

	return result;
}

vector<long long> findPrimes(long long index)
{
	vector<long long> pFactors;
	int i = 0;

	int number = 2;
	do
	{
		if (isPrime(number))
		{
			pFactors.push_back(number);
			i++;
		}

		number++;
	} while (i < index);

	return pFactors;
}
int main()
{
	vector<long long> pTest = findPrimes(6);
	assert(pTest[5] == 13);

	vector<long long> p10001 = findPrimes(10001);
	for (long long p : p10001)
	{
		cout << p << ", " << endl;
	}

	cout << endl << "The 10001st prime number : " << p10001[10000] << endl;
}
