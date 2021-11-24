//Read  numbers from stdin and print their sum to stdout.
//Task
//Read 3 numbers from stdin and print their sum to stdout.
//
//Input Format
//
//One line that contains  space - separated integers : a , b, and c.
//
//Constraints
//1<=a,b,c<=1000
//Output Format
//
//Print the sum of the three numbers on a single line.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdarg>
using namespace std;

bool checkrange(int num, ...)
{
    va_list arguments;
    //! Initializing arguments to store all values after num 
    va_start(arguments, num);
    // Sum all the inputs; we still rely on the function caller to tell us how many there are 
    for (int x = 0; x < num; x++)
    {
        int arg = va_arg(arguments, int);
        if (arg < 1 || arg >1000)
            return false;
    }
    va_end(arguments);                  // Cleans up the list

    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a,b,c;
    bool running = true;
    while (running)
    {
        cout << "please enter three integers between 1-1000" << endl;
        cin >> a >> b >> c;
        if (checkrange(3, a, b, c))
        {
            cout << a + b + c << endl;
            running = false;
        }
        else
        {
            cout << "The numbers must be in the range 1-1000. Please re-enter three integers between 1-1000" << endl;
        }
    }
    return 0;
}
