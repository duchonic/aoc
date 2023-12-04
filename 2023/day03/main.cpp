/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-02
 * 
 * @copyright codestation (c) 2023
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

#include <regex>

struct color_pixel {
	uint8_t red; 
	uint8_t green;
	uint8_t blue;
};


/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input, bool DoPart2, color_pixel setting) {
	int64_t returnValue = 0;

	int line_nr = 0;
	std::vector<std::pair<int, int>> symbols;
	std::vector<std::pair<int, int>> numbers;
	std::vector<int> values;

	std::map<std::pair<int, int>, std::vector<int>> map;

	for (std::string line : input) {
		std::string read_value{""};
		std::array< std::pair<int,int>, 2 > startstop;
		bool start_value = false;
		for (int x = 0; x < line.size(); x++) {
			if (!isdigit(line.at(x))) {

				if (DoPart2) {
					if (line.at(x) == '*') {
						symbols.push_back({x, line_nr});
					}
				}
				else {
					if (line.at(x) != '.') {
						symbols.push_back({x, line_nr});
					}

				}
				
				if (start_value) {
					values.push_back( std::stoi(read_value));
					start_value = false;
				}

			}
			else {
				if (start_value) {
					read_value.push_back(line.at(x));
				}
				else {
					numbers.push_back( {x, line_nr} );
					start_value = true;
					read_value.clear();
					read_value.push_back(line.at(x));
				}
			}
		}
		line_nr += 1;
	}


	for (int nr=0; nr < numbers.size(); nr++) {

		for (int size = 0; size < std::to_string(values.at(nr)).size(); size++) {
			bool found = false;
			std::array< std::pair<int,int>, 8> neighbour{ 
				std::pair{-1,-1}, std::pair{0,-1}, std::pair{1,-1},
				std::pair{-1,0},                   std::pair{1, 0},
				std::pair{-1,1}, std::pair{0,1}, std::pair{1,1} };
			for (auto nb : neighbour) {
				std::pair<int,int> check = {numbers.at(nr).first + size + nb.first, numbers.at(nr).second + nb.second};
				for (auto item: symbols) {
					if (check == item) {
						if (DoPart2) {
							if (map.find(item) == map.end()) {
								map[item] = std::vector<int>();
								map[item].push_back(values.at(nr));
							}
							else {
								map[item].push_back(values.at(nr));
								returnValue += map[item][0] * values.at(nr);
							}
						}
						else {
							returnValue += values.at(nr);
						}

						found = true;
						break;
						
					}
				}
				if (found) {
					break;
				}
			}
			if (found) {
				break;
			}
		}
	}



	return returnValue;	
}


int main() {
	color_pixel setting = {12,13,14};

	std::vector<std::string> data = readstuff();
	std::cout << "2023 day01 solve part 1" << std::endl;
	int64_t part1 = solve(data, false, setting);
	std::cout << "part1 : " << part1 << std::endl;

	std::cout << "2023 day01 solve part 2" << std::endl;
	int64_t part2 = solve(data, true, setting);
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
