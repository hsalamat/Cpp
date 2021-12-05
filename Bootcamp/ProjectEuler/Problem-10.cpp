/** @file problem-10.cpp
 *  @brief Summation of primes
	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

	Find the sum of all the primes below two million.
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

long long sumPrimes(long long number)
{
	vector<long long> pFactors;
	long long sum = 2;
	pFactors.push_back(2);
	cout << "2";

	for (int i = 3; i < number; i++ )
	{
		if (isPrime(i))
		{
			cout << ", " << i;
			pFactors.push_back(i);
			sum += i;
		}
	}

	cout << endl;
	return sum;
}
int main()
{
	long long pTest = sumPrimes(10);
	assert(pTest == 17);
	cout << endl;

	long long p2mil = sumPrimes(2000000);

	cout << endl << "the sum of all the primes below two million : " << p2mil << endl;
}
