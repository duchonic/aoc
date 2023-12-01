/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
 |"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
\*-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-*/

#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"

/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 0;

	for (auto line : input) {
		
		int first = -1;
		int last = -1;

		std::string solve_LeftToRight = "";
		std::string solve_RightToLeft = "";

		for (int pos = 0; pos < line.size(); pos++) {
			char nextChar_RightToLeft = line.at(line.size()-1-pos);
			char nextChar_LeftToRight = line.at(pos);

			if (isdigit(nextChar_RightToLeft) && (last == -1)) {
				last = nextChar_RightToLeft - '0';
			}			
			if (isdigit(nextChar_LeftToRight) && (first == -1)) {
				first = nextChar_LeftToRight - '0';
			}

			if (DoPart2) {
				solve_RightToLeft = nextChar_RightToLeft + solve_RightToLeft;
				std::vector<std::string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
				int index = 1;
				for (auto &number : numbers) {
					if (last != -1) {
						if (solve_RightToLeft.find(number) != std::string::npos) {
							last = index;
							break;
						}
					}
					index += 1;
				}
			}
		}
		returnValue += last;
		returnValue += first * 10;
	}
	return returnValue;	
}


int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "2023 day01 solve part 1" << std::endl;
	int64_t part1 = solve(data, false);
	std::cout << "2023 day01 solve part 2" << std::endl;
	int64_t part2 = solve(data, true);
	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
