/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
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

#include <assert.h>

/*
    Seed 79, soil 81, fertilizer 81, water 81, light 74, temperature 78, humidity 78, location 82.
    Seed 14, soil 14, fertilizer 53, water 49, light 42, temperature 42, humidity 43, location 43.
    Seed 55, soil 57, fertilizer 57, water 53, light 46, temperature 82, humidity 82, location 86.
    Seed 13, soil 13, fertilizer 52, water 41, light 34, temperature 34, humidity 35, location 35.
*/

int64_t solve_part( std::array<int64_t, 3> input, int64_t seed) {
	int64_t returnValue = seed;

	int64_t destination = input.at(0);
	int64_t source = input.at(1);
	int64_t length = input.at(2);

	if (seed >= source && seed <= source + length-1) {
		int64_t offset = seed - source;
		assert(offset >= 0);
		returnValue = offset + destination;
	}
	assert(returnValue >= 0);

	return returnValue;
}


/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 100000000000;

	std::vector<int64_t> seeds;
	std::vector<std::vector<int64_t>> seeds_part2;
	std::vector<std::vector<std::array<int64_t, 3>>> commands_global;
	std::vector<std::array<int64_t, 3>> commands;

	/**
	 * commands will always be 
	 * destination, source, length
	 *
	 * example (50, 98, 2) will copy 2 bytes from 98 to 50
	 *  
	*/
	for (auto line : input) {

		std::vector<std::string> split;
		split_str(line, ':', split);


		if (split.size()) {
			if (split.at(0) == "seeds") {
				std::vector<std::string> split_seeds;
				split_str(split.at(1), ' ', split_seeds);

				std::vector<int64_t> seed_pair;
				seed_pair.clear();
				for (auto seed : split_seeds) {
					if (DoPart2) {
						if (seed_pair.size() == 0) {
							seed_pair.push_back(std::atoll(seed.c_str()));
						}
						else {
							seed_pair.push_back(std::atoll(seed.c_str()));
							seeds_part2.push_back(seed_pair);
							seed_pair.clear();
						}
					}
					else {
						seeds.push_back(std::atoll(seed.c_str()));
					}
				}
			}
			else if (isdigit(split.at(0)[0])) {
				std::vector<std::string> split_command;
				split_str(split.at(0), ' ', split_command);

				int64_t destination = std::atoll(split_command.at(0).c_str());
				int64_t source = std::atoll(split_command.at(1).c_str());
				int64_t length = std::atoll(split_command.at(2).c_str());
				std::array<int64_t, 3> command_array = {destination, source, length};
				commands.push_back(command_array);
			}
			else  {
				commands_global.push_back(commands);
				commands.clear();
			}
		}
	}
	commands_global.push_back(commands);


	if (DoPart2) {
		for (auto pair : seeds_part2) {
			std::cout << "pair : " << pair.at(0) << " " << pair.at(1) << std::endl;
		
			for (int64_t start = pair.at(0); start <= pair.at(0) + pair.at(1); start++) {
				int64_t calc_seed = start;
				for (auto commands : commands_global) {
					for (auto command : commands) {

						int64_t old_seed = calc_seed;
						calc_seed = solve_part(command, calc_seed);
						if (old_seed != calc_seed) {
							break;
						}
					}
				}
				if (calc_seed < returnValue) {
					returnValue = calc_seed;
				}
			}
		
		}

		
	}
	else {
		for (auto seed : seeds) {
			int64_t calc_seed = seed;
			for (auto commands : commands_global) {
				for (auto command : commands) {

					int64_t old_seed = calc_seed;
					calc_seed = solve_part(command, calc_seed);
					if (old_seed != calc_seed) {
						break;
					}
				}
			}
			if (calc_seed < returnValue) {
				returnValue = calc_seed;
			}
		}
	}

	return returnValue;	
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
