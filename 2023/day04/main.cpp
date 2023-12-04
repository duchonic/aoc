/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-02
 * 
 * @copyright codestation (c) 2023
 *   ___    ___   __| |   ___    ___   | |_   __ _   | |_    (_)    ___   _ _   
 *  / _ |  / _ \ / _` |  / -_)  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \ 
 *  \___|  \___/ \__,_|  \___|  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|
 * /""""\_/""""\_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
 * =-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-
*/

#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/plot.h"


/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 0;

	std::vector<int> winners;
	std::vector<int> numbers;
	std::vector<int> copies;

	for (auto line : input) {
		copies.push_back(1);
	}

	int card_nr = 0;
	for (auto line : input) {
		std::vector<std::string> linearray;
		split_str(line, ' ', linearray);

		winners.clear();
		for (int win=2; win <= 11; win++) {
		//for (int win=2; win <= 6; win++) {
			winners.push_back( std::atoi( linearray.at(win).c_str() ));
		}	
		numbers.clear();
		for (int num=13; num < linearray.size(); num++) {
		//for (int num=8; num < linearray.size(); num++) {
			numbers.push_back( std::atoi (linearray.at(num).c_str() ));
		}

		int64_t result = 0;
		int64_t local_copies = 0;
		
		for (auto win : winners) {
			for (auto num : numbers) {
				if (num == win) {
					local_copies += 1;
					if (result == 0) {
						result = 1;
					} else {
						result *= 2;
					}
				}
			}
		}

		for (int run = 1; run <= copies.at(card_nr); run++) {
			for (int win_copies = card_nr + 1; win_copies < card_nr + 1 + local_copies; win_copies++) {
				copies.at(win_copies) = copies.at(win_copies) + 1;
			}
		}
		card_nr += 1;

		returnValue += result;
	}

	if (DoPart2) {
		returnValue = 0;
		for (auto cop : copies) {
			returnValue += cop;
		}
	}

	return returnValue;	
}


int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "2023 day04 solve part 1" << std::endl;
	int64_t part1 = solve(data, false);
	std::cout << "part1 : " << part1 << std::endl;

	std::cout << "2023 day04 solve part 2" << std::endl;
	int64_t part2 = solve(data, true);
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
