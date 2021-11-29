// istream::getline example
//Extracts characters from the stream as unformatted inputand stores them into s as a c - string, until either the extracted character is the delimiting character, or n characters have been written to s(including the terminating null character).
#include <iostream>     // std::cin, std::cout

int main() {
	char name[256], title[256];

	std::cout << "Please, enter your name: ";
	std::cin.getline(name, 256);

	std::cout << "Please, enter your favourite movie: ";
	std::cin.getline(title, 256);

	std::cout << name << "'s favourite movie is " << title;

	return 0;
}