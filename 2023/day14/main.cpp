/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-07
 * 
 * @copyright codestation (c) 2023
 *                   _                 _             _       __
 *   ___    ___    _| |   ___    ___  | |_    _ _   | |_    (__)   ___    _ _   
 *  / _ |  / _ \  /_` |  / -_)  (_-<  |  _|  /_` |  |  _|   |  |  / _ \  | ' \ 
 *  \___|  \___/  \_,_|  \___|  /__/   \__|  \_,_|   \__|   |__|  \___/  |_||_|
 * /""""\_/""""\_/""""\_/".."\_/""""\_/""""\_/""""\_/""""\_/""""\_/""""\_/""""\
 * -0--0-=-0--0-=-0--0-=-0xx0-=-0--0-=-0--0-=-0--0-=-0--0-=-0--0-=-0--0-=-0--0-
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

#include <algorithm>


static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 0;

	for (auto line : input) {
		std::cout << line << std::endl;
	}

	std::vector<std::pair<uint16_t, uint16_t>> rocks_loose;
	std::vector<std::pair<uint16_t, uint16_t>> rocks_fix;

	for (uint16_t x = 0; x < input.at(0).size(); x++) {
		for (uint16_t y = 0; y < input.size(); y++) {
			if (input.at(y).at(x) == '#') {
				rocks_fix.push_back(std::pair<uint16_t, uint16_t>{x,y});
			} else if (input.at(y).at(x) == 'O') {
				rocks_loose.push_back(std::pair<uint16_t, uint16_t>{x,y});
			}
		}
	}

	std::cout << std::endl;
	std::cout << "fix rocks" << std::endl;
	for (auto fix : rocks_fix) {
		std::cout << fix.first << "/" << fix.second << " ";
	}
	std::cout << std::endl;

	/** tilt the board to north, sort first y top to bottom */
	std::sort(rocks_loose.begin(), rocks_loose.end(), [](auto &left, auto &right) {
		return (left.second < right.second);
	});

	bool moved_rock = true;
	while (moved_rock) {
		
		moved_rock = false;
		for (auto &loose : rocks_loose) {
			std::cout << loose.first << '/' << loose.second << std::endl; 
			if (loose.second > 0) {
				bool blocked = false;
				for (auto fix : rocks_fix) {
					if (fix.first == loose.first && fix.second == (loose.second-1)) {
						std::cout << "is blocked by fix rock" << std::endl;
						blocked = true;
					}
				}
				for (auto loose_fix : rocks_loose) {
					if (loose_fix.first == loose.first && loose_fix.second == (loose.second-1)) {
						std::cout << "is blocked by loose rock" << std::endl;
						blocked = true;
					}
				}
				if (!blocked) {
					loose.second -= 1;
					moved_rock = true;
				}
			}
		}
	}

	

	/** calculate the score */
	std::cout << "loose rocks" << std::endl;
	for (auto loose : rocks_loose) {
		std::cout << loose.first << '/' << loose.second << " "; 
		returnValue += ( input.size() - loose.second);
	}
	std::cout << std::endl;

	return returnValue;	
}

int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "2023 day05 solve part 1" << std::endl;
	int64_t part1 = solve(data, false);
	std::cout << "part1 : " << part1 << std::endl;
	return 0;
	
	std::cout << "2023 day05 solve part 2" << std::endl;
	int64_t part2 = solve(data, true);
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
