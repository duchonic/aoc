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

	std::vector<std::pair<int, int>> points;

	for (uint16_t col = 0; col < input.at(0).size(); col++) {
		for (uint16_t row = 0; row < input.size(); row++) {
			if (input.at(row).at(col) == '#') {
				points.push_back(std::pair<int, int>{col, row});
			}
		}
	}
	uint64_t increment = 1;
	if (DoPart2) {
		increment = 1000000 - 1;
	}

	// sort points by first argument in pair
	std::sort(points.begin(), points.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});

	// check if empty line
	uint64_t actualPoint = 0;
	while (actualPoint <= points.at(points.size()-1).first) {
		auto it = std::find_if(points.begin(), points.end(), [actualPoint](auto &point) {
			return point.first == actualPoint;
		});
		if (it == points.end()) {
			// increment all points after this (first value)
			for (auto &point : points) {
				if (point.first > actualPoint) {
					point.first += increment;
				}
			}
			actualPoint+=increment;
		}
		actualPoint++;
	}

	// sort points by first argument in pair
	std::sort(points.begin(), points.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});

	// check if empty col
	actualPoint = 0;
	while (actualPoint <= points.at(points.size()-1).second) {
		auto it = std::find_if(points.begin(), points.end(), [actualPoint](auto &point) {
			return point.second == actualPoint;
		});
		if (it == points.end()) {
			// increment all points after this (second value)
			for (auto &point : points) {
				if (point.second > actualPoint) {
					point.second+= increment;
				}
			}
			actualPoint+=increment;
		}
		actualPoint++;
	}

	for (auto source : points) {
		for (auto destination: points) {
			int64_t distance = std::abs(source.first - destination.first) + std::abs(source.second - destination.second);
			returnValue += distance;
		}
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
