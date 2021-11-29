/** @file stoiDemo.cpp
 *  @brief stoi example: the function returns the converted integral number as an int value.
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main()
{
	std::string str_dec = "2001, A Space Odyssey";
	std::string str_hex = "40c3";
	std::string str_bin = "-10010110001";
	std::string str_auto = "0x7f";

	std::string::size_type sz;   // alias of size_t

	int i_dec = std::stoi(str_dec, &sz);
	int i_hex = std::stoi(str_hex, nullptr, 16);
	int i_bin = std::stoi(str_bin, nullptr, 2);
	int i_auto = std::stoi(str_auto, nullptr, 0);

	std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
	std::cout << str_hex << ": " << i_hex << '\n';
	std::cout << str_bin << ": " << i_bin << '\n';
	std::cout << str_auto << ": " << i_auto << '\n';

	std::string str = "We think in generalities, but we live in details.";
	// (quoting Alfred N. Whitehead)

	std::string str2 = str.substr(3, 5);     // "think"

	std::size_t pos = str.find("live");      // position of "live" in str

	std::string str3 = str.substr(pos);     // get from "live" to the end

	std::cout << str2 << ' ' << str3 << '\n';

	return 0;
}

