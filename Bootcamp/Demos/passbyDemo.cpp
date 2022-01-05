/** @file passbyDemo.cpp
 *  @brief difference in passing in a variable by ref/value/pointer to a function
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <cstdio>
#include <string>
#include <stdio.h>
#include<iostream>
using  namespace std;
void passByVal(int val); //pass in a copy of the variable
void passByRef(int& ref); //pass in the actual variable
void passByPtr(int* ptr); //pass in the address of the variable

int main()
{
	string bye;
	int val = 5;
	passByVal(val);
	passByRef(val);
	passByPtr(&val);

	getline(cin, bye);
	return 0;
}

void passByVal(int val)
{
	val = 10;
	printf("val = %i \n", val);
}

void passByRef(int& ref)
{
	ref = 20;
	printf("ref = %i \n", ref);
}

void passByPtr(int* ptr)
{
	printf("*ptr = %i \n", *ptr);
	*ptr = 30;
	printf("*ptr = %i \n", *ptr);
}