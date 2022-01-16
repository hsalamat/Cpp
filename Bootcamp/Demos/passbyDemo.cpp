/** @file passbyDemo.cpp
 *  @brief difference in passing in a variable by ref/value/pointer to a function
 *  Difference Between Reference Variable and Pointer Variable:
 
    A reference is the same object, just with a different name and a reference must refer to an object. Since references can’t be NULL, they are safer to use. 

	A pointer can be re-assigned while a reference cannot, and must be assigned at initialization only.
	The pointer can be assigned NULL directly, whereas the reference cannot.
	Pointers can iterate over an array, we can use increment/decrement operators to go to the next/previous item that a pointer is pointing to.
	A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
	A pointer to a class/struct uses ‘->’ (arrow operator) to access its members whereas a reference uses a ‘.’ (dot operator)
	A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.

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

struct demo {
    int a;
};

int main()
{
	string bye;
	int val = 5;
	passByVal(val);
	passByRef(val);
	passByPtr(&val);


    int x = 5;
    int y = 6;
    demo d;

    int* p;
    p = &x;
    p = &y; // 1. Pointer reintialization allowed

    int& r = x;
    // &r = y;                 // 1. Compile Error

    r = y; // 1. x value becomes 6

    p = NULL;
    // &r = NULL;             // 2. Compile Error

    // 3. Points to next memory location
    p++;

    // 3. x values becomes 7
    r++;

    cout << &p << " " << &x << '\n'; // 4. Different address
    cout << &r << " " << &x << '\n'; // 4. Same address

    demo* q = &d;
    demo& qq = d;

    q->a = 8;
    // q.a = 8;                 // 5. Compile Error
    qq.a = 8;
    // qq->a = 8;             // 5. Compile Error

    // 6. Prints the address
    cout << p << '\n';

    // 6. Print the value of x
    cout << r << '\n';


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