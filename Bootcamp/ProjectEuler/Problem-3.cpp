/** @file problem-3.cpp
 *  @brief Largest prime factor
    The prime factors of 13195 are 5, 7, 13 and 29.

    What is the largest prime factor of the number 600851475143 ?

    CHAR_MIN	Minimum value for a variable of type char.	-128; 0 if /J option used
    CHAR_MAX	Maximum value for a variable of type char.	127; 255 if /J option used
    MB_LEN_MAX	Maximum number of bytes in a multicharacter constant.	5
    SHRT_MIN	Minimum value for a variable of type short.	-32768
    SHRT_MAX	Maximum value for a variable of type short.	32767
    USHRT_MAX	Maximum value for a variable of type unsigned short.	65535 (0xffff)
    INT_MIN	Minimum value for a variable of type int.	-2147483647 - 1
    INT_MAX	Maximum value for a variable of type int.	2147483647
    UINT_MAX	Maximum value for a variable of type unsigned int.	4294967295 (0xffffffff)
    LONG_MIN	Minimum value for a variable of type long.	-2147483647 - 1
    LONG_MAX	Maximum value for a variable of type long.	2147483647
    ULONG_MAX	Maximum value for a variable of type unsigned long.	4294967295 (0xffffffff)
    LLONG_MIN	Minimum value for a variable of type long long.	-9,223,372,036,854,775,807 - 1
    LLONG_MAX	Maximum value for a variable of type long long.	9,223,372,036,854,775,807
    ULLONG_MAX	Maximum value for a variable of type unsigned long long.	18,446,744,073,709,551,615 (0xffffffffffffffff)

     *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


vector<long long> findPrimeFactors(long long number)
{
    vector<long long> pFactors;
    for (long i = 2; i <= number; i++)
    {
        if (number % i == 0)
        {
            pFactors.push_back(i);
            number /= i;
            while (number % i == 0)
                number /= i;
        }
    }
    return pFactors;
}
int main()
{
    vector<long long> pFactorsTest = findPrimeFactors(13195);
    assert(*max_element(pFactorsTest.begin(), pFactorsTest.end()) == 29);

    vector<long long> pFactors = findPrimeFactors(600851475143);
    for (long long p : pFactors)
    {
        cout << p << ", " << endl;
    }

    cout << endl << "the maximum prime factor is " << *max_element(pFactors.begin(), pFactors.end()) << endl;
}
