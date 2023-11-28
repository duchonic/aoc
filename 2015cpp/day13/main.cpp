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

#include <algorithm>
#include <random>


/**
 * @brief sonar scope count positives slopes in data input
 * 
 * @param input vector with data
 * @param width width of windows to calculate
 * @return int16_t sum of positives slopes
 */
static int16_t sonarScope(std::vector<std::string> input, int8_t width) {
	int16_t lineNumber = 0;
	int16_t returnValue = 0;

	std::vector<std::string> names;
	names.push_back("Nicolas");
	std::vector<std::vector<std::string>> data;

	std::vector<std::vector<std::string>> tablesetup;

	for (auto dummy : input) {

		std::vector<std::string> line;

		std::stringstream ss(dummy);
		std::string item;
		while (std::getline(ss, item, ' ')) {
			line.push_back(item);
		}
		data.push_back(line);
		lineNumber++;
	}

	for (auto line : data) {
		if (std::count(names.begin(), names.end(), line.at(0)) == 0) {
			names.push_back(line.at(0));
			std::cout << "new name added: " << line.at(0) << std::endl;
		}
		std::string from = line.at(0);
		std::string to = line.at(10).substr(0, line.at(10).size() - 1);

		std::vector<std::string> tableline;
		tableline.push_back(from);
		tableline.push_back(to);

		if (line.at(2) == "lose") {
			std::cout << from << "@" << to <<  " -" << line.at(3) << std::endl;
			tableline.push_back("-" + line.at(3));
		}
		else {
			std::cout << from << "@" << to << " +" << line.at(3) << std::endl;
			tableline.push_back(line.at(3));
		}
		tablesetup.push_back(tableline);
	}

	auto rng = std::default_random_engine {};

	// do all permutations of the names
	std::cout << "do all permutations of the names" << std::endl;
	do {
		int actualval = 0;

		for (int i = 0; i < names.size(); i++) {
			std::string from = names.at(i);
			std::string to = names.at( (i+1) % names.size());
			for (auto line : tablesetup) {
				if (line.at(0) == from && line.at(1) == to) {
					actualval += std::stoi(line.at(2));
				}
			}	
		}

		for (int i = names.size() - 1; i >= 0; i--) {
			std::string from = names.at(i);
			std::string to = names.at( (i-1) % names.size());
			for (auto line : tablesetup) {
				if (line.at(0) == from && line.at(1) == to) {
					actualval += std::stoi(line.at(2));
				}
			}
		}

		if (actualval > returnValue) {
			returnValue = actualval;
		}
		
	} while (std::next_permutation(names.begin(), names.end()));

	return returnValue;	
}


int main() {
	std::vector<std::string> data = readstuff();
	int16_t part1 = sonarScope(data, 1);
	//int16_t part2 = sonarScope(data, 3);
	std::cout << "part1 abc: " << part1 << std::endl;
	//std::cout << "part2 abc: " << part2 << std::endl;
	return 0;
}
