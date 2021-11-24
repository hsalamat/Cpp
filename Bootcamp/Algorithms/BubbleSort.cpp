#include<iostream>
#include <array>
using namespace std;
int main()
{
	int m, j, temp;
	//int list[10] = { 55, 96, 61, 563, 4, 464, 112, 788, 934, 2 };
	std::array<int, 10> list = { 55, 96, 61, 563, 4, 464, 112, 788, 934, 2 };
	for (m = 0; m < 10; m++)
	{
		for (j = m + 1; j < 10; j++)
		{
			if (list[j] < list[m])
			{
				temp = list[m];
				list[m] = list[j];
				list[j] = temp;
			}
		}
	}
	cout << "Code will print the list of items sorted ...\n";

	for (auto a : list) {
			cout << a << endl;
	}
	return 0;
}