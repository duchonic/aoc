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


/*
 * @brief process input that contains a 2d grid with '#' and '.' characters
 * inputfile example:
	...#......
	.......#..
	#.........
	..........
	......#...
	.#........
	.........#
	..........
	.......#..
	#...#.....
*/
static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 0;

	std::vector<std::vector<char>> map;

	for (auto line : input) {
		std::vector<char> row{'x', ' '};
		map.push_back(row);
	}

	const int expansion = 1000000;

	// expand the map with empty columns
	for (int col = 0; col < input.at(0).size(); col++) {
		bool found = false;
		for (int row = 0; row < input.size(); row++) {
			map.at(row).push_back(input.at(row).at(col));
			if (input.at(row).at(col) == '#') {
				found = true;
			}
		}
		if (!found) {
			//expand the row
			if (DoPart2) {
				for(int i = 1; i < expansion; i++) {
					for (int row = 0; row < input.size(); row++) {
						map.at(row).push_back('.');
					}
				}
			}
			else {
				for (int row = 0; row < input.size(); row++) {
					map.at(row).push_back('.');
				}

			}
		}
	}

	std::vector<std::vector<char>> expand_row;

	for (auto line : map) {
		// if no '#' in the line expand a new line
		bool found = false;
		for (auto c : line) {
			if (c == '#') {
				found = true;
			}
		}
		if (!found) {
			if (DoPart2) {
				for(int i = 1; i < expansion; i++) {
					expand_row.push_back(line);
				}
			}
			else {
				expand_row.push_back(line);
			}
		}
		expand_row.push_back(line);
	}

	std::vector<std::pair<int, int>> points;

	for (int col = 0; col < expand_row.at(0).size(); col++) {
		for (int row = 0; row < expand_row.size(); row++) {
			if (expand_row.at(row).at(col) == '#') {
				points.push_back(std::pair<int, int>{col-2, row});
			}
		}
	}

	for (auto source : points) {
		for (auto destination: points) {
			int distance = std::abs(source.first - destination.first) + std::abs(source.second - destination.second);
			returnValue += distance;
		}
	}

	for (auto line : expand_row) {
		for (auto c : line) {
			std::cout << c;
		}
		std::cout << std::endl;
	}

	return returnValue/2;	
}

int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "2023 day05 solve part 1" << std::endl;
	int64_t part1 = solve(data, false);
	std::cout << "part1 : " << part1 << std::endl;

	std::cout << "2023 day05 solve part 2" << std::endl;
	int64_t part2 = solve(data, true);
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
