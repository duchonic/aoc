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
#include <regex>


static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 0;

	std::string path = input.at(0);
	std::cout << path << std::endl;

	// dictionary with string keys and pair of string as values
	std::map<std::string, std::pair<std::string, std::string>> dict;


	std::string start;
	std::string end;

	//for (auto line : input.at(2)) {
	for (int pos = 2; pos < input.size(); pos++) {
		std::regex re("([A-Z]+) = \\(([A-Z]+), ([A-Z]+)\\)");
		std::smatch match;
		std::regex_search(input.at(pos), match, re);
		
		std::pair<std::string, std::string> value{match[2], match[3]};
		std::string key = match[1];

		if (start.empty()) {
			start = key;
		}
		end = key;
		dict[key] = value;
	}
	start = "AAA";
	end = "ZZZ";

	std::cout << "start: " << start << " end: " << end << std::endl;


	while (start != end) {

		for (auto direction: path) {
			if (direction == 'L') {
				start = dict[start].first;
			} else {
				start = dict[start].second;
			}
			returnValue++;
		}
		std::cout << "start: " << start << " end: " << end << std::endl;
	}

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
