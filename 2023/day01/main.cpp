/**       _             _       _                                          _
 * @brief blub
 * @author
 *  __     ___   __| |   ___            ___   | |_   __ _   | |_    (_)    ___   _ _   
 * / _|   / _ \ / _` |  / -_)     _    (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \ 
 * \__|   \___/ \__,_|  \___|   _(_)_  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|
 * """"|_|"""""_|"""""_|"""""|_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|""""|
 *\-0-0-"`-0-0-"`-0-0-"`-0-0-*"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-
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

	for (auto line : input) {
		std::array<int, 2> nr{-1, -1};
		std::array<std::string, 2> solve{"", ""};

		std::array<int, 2> checks{0,1};

		for (int pos = 0; pos < line.size(); pos++) {
			std::array<char, 2> next{line.at(pos), line.at(line.size()-1-pos)};

			for (auto check : checks) {
				if (isdigit(next.at(check)) && (nr.at(check) == -1)) {
					nr.at(check) = next.at(check) - '0';
				}			
			}

			if (DoPart2) {
				solve.at(0) = solve.at(0) + next.at(0);
				solve.at(1) = next.at(1) + solve.at(1);

				int index = 1;
				for (auto &number : get_numbers_1_to_9()) {
					for (auto check : checks) {
						if (nr.at(check) == -1) {
							if (find(solve.at(check), number)) {
								nr.at(check) = index;
							}
						}
					}
					index += 1;
				}
			}
		}
		returnValue += nr[1];
		returnValue += nr[0] * 10;

	}

	//plotter(data_x, data_y);
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
