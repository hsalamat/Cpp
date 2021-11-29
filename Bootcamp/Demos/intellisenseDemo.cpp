/** @file intellisenseDemo.cpp
 *  @brief Game Customer Review
 *  You are building a way to help game customer search reviews quicker by providing
 *  real-time suggestions to search terms when the customer starts typing. When given a minimum of two characters into the serach field
 *  the system will suggest at most three keywords from the review word repository.
 *  As the customer continues to type in the reviews search bar the relavant keyword
 *  suggestions will update automatically.
 *
 *  Write an algorithm that will output a maximum of three keyword suggestions
 *  after each character is typed by the customer in the search field.
 *
 *  If there are more than three acceptable keywords, return the keywords that are first in alphabetical order.
 *  Only return krword suggestions after the customer has entered two characters.
 *  Keyword suggestions must start with the characters already typed.
 *  Both the repository and the customerQuery should be compared in a case sensitive way.
 *
 *  Input
 *  The input to the method/fucntion consists of two arguments:
 *  repository: a list of unique strings representingthe various keywords from the review comment section
 *  customerQuery: a string representing the full search query of the customer
 *
 *  Output
 *  Reutrns a list of list of strings in lower case,
 *  where each list represents the keyword suggestions made by the system as
 *  customer types each character of the customerQuery. Assume customer
 *  types characters in order without deleting or removing any characters.
 *  If an output is not possible, return an empty array([]).
 *
 *  Example
 *  Input:
 *  repository = ["mobile", "mouse", "moneypot","monitor", "mousepad"]
 *  customerQuery = "mouse"
 *
 *  Outout:
 *  ["mobile","moneypot","monitor"]
 *  ["mouse", "mousepad"]
 *  ["mouse","mousepad"]
 *
 *  Explanation:
 *  The chain of words that will generate in the search box will be
 *  mo, mou, mous, mouse
 *  and each line from output shows the suggestion of "mo" "mou", "mous", "mouse", respectively in each line
 *  For the keyword suggestions made by the system that are generated for "mo" that matches that will be generated are:
 *  ["mobile", "mouse", "moneypot","monitor", "mousepad"]
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


 /*
 * the searchSuggestionss functions is expected to return a 2D_STRING_ARRAY
 * @parameters
 * 1. string_array repository
 * 2.  customerQuery
 */

#include <iostream>
#include <algorithm>    // std::find_if
#include <functional>   // std::not1
#include <vector>
#include <string>
#include <string_view>
using namespace std;

vector<vector<string>> searchSugesstion(vector <string> repository, string customerQuery)
{

	vector<string> customerQueries;
	for (int i = 2; i < customerQuery.size(); i++)
	{
		cout << customerQuery.substr(0, i);
	}

	vector<vector<string>> result = {
		{"mobile", "moneypot", "monitor"} ,
		{"mouse", "mousepad" },
			{"mouse", "mousepad"}
	};

	return result;
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

	std::cout << "Please, enter the number of repository items: ";
	string repository_count_temp;
	getline(cin, repository_count_temp);

	int repository_count = stoi(ltrim(rtrim(repository_count_temp)));

	vector<string> repository(repository_count);

	for (int i = 0; i < repository_count; i++) {
		std::cout << "Please, enter the repository item [" << i << "]: ";
		string repository_item;
		getline(cin, repository_item);

		repository[i] = repository_item;
	}

	std::cout << "Please, enter the customer query: ";
	string customerQuery;
	getline(cin, customerQuery);

	vector <vector<string>> result = searchSugesstion(repository, customerQuery);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];

			if (j != result[i].size() - 1) {
				cout << " ";
			}
		}

		if (i != result.size() - 1) {
			cout << "\n";
		}
	}

	cout << "\n";
	return 0;
}