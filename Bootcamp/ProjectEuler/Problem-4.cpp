/** @file problem-4.cpp
 *  @brief Largest palindrome product
	A palindromic number reads the same both ways.
	The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

	Find the largest palindrome made from the product of two 3-digit numbers.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;


bool isPalindrome(int number)
{
	bool result = false;
	std::string tmp = std::to_string(number);
	char const* num_char = tmp.c_str();
	int len = tmp.length();
	int halfLen = (int)tmp.length() / 2;

		for (int i = 0; i <= halfLen; i++)
			if (num_char[i] != num_char[len - i - 1])
				return false;
	return true;

}


vector<int> findPalindrome(int digits)
{
	vector<int> palindrome;
	int smallDigitNumber = pow(10, (digits - 1));
	int maxDigitNumber = pow(10, digits) - 1;
	for (int i = smallDigitNumber; i <= maxDigitNumber; i++)
	{
		for (int j = smallDigitNumber; j <= maxDigitNumber; j++)
		{
			if (isPalindrome(i * j)) palindrome.push_back(i * j);
		}
	}
	return palindrome;
}
int main()
{
	vector<int>  pTest = findPalindrome(2);
	assert(*max_element(pTest.begin(), pTest.end()) == 9009);

	vector<int> palindrome = findPalindrome(3);
	for (auto p : palindrome)
	{
		cout << p << ", " << endl;
	}

	cout << endl << "the maximum palindrome is " << *max_element(palindrome.begin(), palindrome.end()) << endl;
}
