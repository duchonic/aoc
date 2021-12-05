/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
    */

#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"


std::vector< std::array< std::array<int, 5> , 5>> cards;

static void printCards() {
	for (auto card : cards){
		logger("cards:")
		for (auto line : card) {
			for (auto nr : line) {
				std::cout << nr << ' '; 
			}
			std::cout << std::endl;
		}
	}
}

int main() {
	std::vector<std::string> data = readstuff();
	std::vector<std::string> sequence;

	split_str(data.front(), ',', sequence);
	logger("sequence:");
	for (auto nr : sequence) {
		std::cout << nr << ' ';
	}
	std::cout << std::endl;

	int actualCard = -1;
	for (int line=2; line < data.size(); line+= 6) {
		std::array<std::array<int, 5>,5> empty;
		cards.push_back(empty);
		actualCard++;	
		for (int y=0; y<5; y++) {
			std::stringstream ss(data.at(line+y));

			for (int count=0; count < 5; count++) {
				int number;
				ss >> number;
				cards.at(actualCard).at(y).at(count) = number;
			}
		}
	}

	printCards();

	int16_t part1 = 0;
	int16_t part2 = 0;

	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 0;
}
