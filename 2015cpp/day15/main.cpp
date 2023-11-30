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

#include <numeric>
#include <algorithm>
#include <random>


/**
 * @brief sonar scope count positives slopes in data input
 * 
 *              capacity durability  flavor  texture  calories
 * Sugar		3		0			0		-3		2
 * Sprinkles    -3		3			0		0		9
 * Candy 		0		0			-3		0		8
 * Chocolate   -3		0			0		5		6
 * 
 * @param input vector with data
 * @return int16_t sum of positives slopes
 */
static int64_t solve(std::vector<std::string> input) {
	int64_t returnValue = 0;

	// make a table from the comment
	std::array<std::array<int16_t, 5>, 4> ingredients {
		std::array<int16_t, 5>{3, 0, 0, -3, 2},
		std::array<int16_t, 5>{-3, 3, 0, 0, 9},
		std::array<int16_t, 5>{0, 0, -3, 0, 8},
		std::array<int16_t, 5>{-3, 0, 0, 5, 6}
	};
	}

	std::vector<std::vector<int16_t>> ingredients;

	for (auto line : input) {
		std::vector<std::string> ingredient;
		std::stringstream ss(line);
		std::string dummy;		
		int16_t a, b, c, d, e;
    	ss >> dummy >> dummy >> a >> dummy >> dummy >> b >> dummy >> dummy >> c >> dummy >> dummy >> d >> dummy >> dummy >> e;
		std::vector<int16_t> sums{a, b, c, d, e};
		ingredients.push_back(sums);
	}

	for (auto item : ingredients) {
		std::cout << item.at(0) << std::endl;
	}

	// have one counter from 0 to 100 and another from 100 to 0
	for (int64_t one=0; one<=100; one++) {
		for (int64_t two=0; two<=100; two++) {
			for (int64_t three=0; three<=100; three++) {
				for (int64_t four=0; four<=100; four++) {
					if (one+two+three+four == 100) {
						if (one > 0 && two > 0 && three > 0 && four > 0) {

							int64_t first = ingredients.at(0).at(0) * one + ingredients.at(1).at(0) * two + ingredients.at(2).at(0) * three + ingredients.at(3).at(0) * four;
							int64_t second = ingredients.at(0).at(1) * one + ingredients.at(1).at(1) * two + ingredients.at(2).at(1) * three + ingredients.at(3).at(1) * four;
							int64_t third = ingredients.at(0).at(2) * one + ingredients.at(1).at(2) * two + ingredients.at(2).at(2) * three + ingredients.at(3).at(2) * four;
							int64_t fourth = ingredients.at(0).at(3) * one + ingredients.at(1).at(3) * two + ingredients.at(2).at(3) * three + ingredients.at(3).at(3) * four;
							int64_t score = first * second * third * fourth;
							if (score > returnValue) {
								std::cout << one << ' ' << two << ' ' << three << ' ' << four << std::endl;
								std::cout << first << ' ' << second << ' ' << third << ' ' << fourth << std::endl;
								std::cout << "score: " << score << std::endl;
								returnValue = score;
							}

						}

					}
				}
			}
		}
	}

	/*
		int16_t down = 100 - up;
		assert(up + down == 100);
		std::cout << up << '/' << down << std::endl;
	}
	*/	

	return returnValue;	
}


int main() {
	std::vector<std::string> data = readstuff();
	int64_t part1 = solve(data);
	//int16_t part2 = solve(data);
	std::cout << "part1 abc: " << part1 << std::endl;
	//std::cout << "part2 abc: " << part2 << std::endl;
	return 0;
}
