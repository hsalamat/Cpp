/** @file promotionPrizeDemo.cpp
 *  @brief Promotion Prize
 *  Steam is running a promotion in which customers receive prizes 
 *  for purchasing a secret combination of games. 
 *  The combination will change each day, and the team running the promotion wants 
 *  to use a code list to make it easy to change the combination. 
 *  The code list contains groups of games. Both the order of groups
 *  within the code list and the order of the games within the groups matter.
 *  However, between the groups of game, any number, and type of game is allowable. 
 *  The term "anything" is used to allow for any type of game to appear 
 *  in that location within the group.
 *
 *  consider the following secret code list: [[group4,group4],[group3,anything,group3]]
 * 
 *  Based on the above secret code list, a customer who made wither the following purchases would win the prize:
 *  
 *  1. group1, group4, group4, group3, group1, group3
 *  2. group4, group4, group1, group1, group3, group4, group3, group3
 * 
 *  write an algorithm to output 1 if the customer is a winner else output 0
 * 
 *  Input
 *  The input to the function/method consists of two arguments:
 *  1. codeList: a string array of space-separated values representing 
 *  the order and grouping of specific games that must be purchased in order to win the prize for the day 
 * 
 *  2. ShoppingCart: a list representing the order in which a customer purchases game
 * 
 *  Outtput
 *  Reutrn an integer 1 if the customer is a winner else return 0
 * 
 *  Note
 *  'anything' in the codeList represents that any game can be ordered 
 *  in place of 'anything' has to be something, it cannot be "nothing"
 *  
 *  'anything' must represent one and only one game.
 *  
 *  if secret code list is empty then it is assumed that customer is a winner.
 * 
 *  Examples:
 *  
 *  Example1
 *  
 *  Input:
 *  codeList = [[group4, group4],[group3, anything, group3]]
 *  shoppingCart = [group3,group4, group4, group3, group1, group3]
 *  Output: 1
 *  
 *  Explanation:
 *  codeList contains two groups: [group4,group4] and [group3, anything, group3].
 *  The second group contains 'anything' so any game can be ordered in place of 'anything'
 *  in the shopping cart.
 *  The cusomter is a winner as the customer has added games in the order games in the groups
 *  and the order of groups in the codeList is also maintained in the shopping cart.
 * 
 *  Example2:
 *  Input:
 *  codeList = [[group4, group4],[group3, anything, group3]]
 *  shoppingCart = [group3,group1, group3, group4, group4]
 *  Output: 0
 * 
 *  Explanation: The customer is not a winner as the customer has added the games in order of groups
 *  but group [group3, anything, group3] is not following the group [group4, group4]
 * 
 *  Example3:
 *  Input:
 *  codeList = [[group4, group4],[group3, anything, group3]]
 *  shoppingCart = [group4,group3, group4, group3, group1,group3]
 *  Output: 0 
 *  Explanation: The customer is not a winner as the customer has added the games in an order
 *  which is not following the order of game names in the first group.
 *
 *  Example4:
 *  Input:
 *  codeList = [[group4, group4],[group4, group4, group3]]
 *  shoppingCart = [group4,group4, group4, group3]
 *  Output: 0 
 *  Explanation: The customer is not a winner as first 2 games form group1, all three games
 *  would form group2, but can't because it would contain all groups of group1.
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */




#include <iostream>
#include <algorithm>    // std::find_if
#include <functional>   // std::not1
#include <vector>
#include <string>
using namespace std;

/// <summary>
/// this function is expected to return an integer
/// </summary>
/// <param name="codeList"></param>
/// <param name="shoppingCart"></param>
/// <returns></returns>
int foo(vector <string> codeList, vector<string>  shoppingCart)
{
	return 0;
}

string ltrim(const string& str) {
	string s(str);
	s.erase(
		s.begin(), find_if(s.begin(), s.end(), not1(std::ptr_fun<int, int>(isspace)))
	);
	return s;
}

string rtrim(const string& str) {
	string s(str);
	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end()
	);
	return s;
}

int main()
{

	std::cout << "Please, enter the number of code list items: ";
	string codeList_count_temp;
	getline(cin, codeList_count_temp);


	int codeList_count = stoi(ltrim(rtrim(codeList_count_temp)));

	vector<string> codeList(codeList_count);

	for (int i = 0; i < codeList_count; i++) {
		std::cout << "Please, enter the code list item [" << i<< "]: ";
		string codeList_item;
		getline(cin, codeList_item);

		codeList[i] = codeList_item;
	}


	std::cout << "Please, enter the number of shopping card items: ";
	string shoppingCart_count_temp;
	getline(cin, shoppingCart_count_temp);

	int shoppingCart_count = stoi(ltrim(rtrim(shoppingCart_count_temp)));

	vector<string> shoppingCart(shoppingCart_count);

	for (int i = 0; i < shoppingCart_count; i++) {
		string shoppingCart_item;
		std::cout << "Please, enter the shopping item [" << i << "]: ";
		getline(cin, shoppingCart_item);

		shoppingCart[i] = shoppingCart_item;
	}


	int result = foo(codeList, shoppingCart);

   
	cout << "\n";

	return 0;
}