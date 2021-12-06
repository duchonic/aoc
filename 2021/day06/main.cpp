/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
	*/

#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"

#include <functional>
#include <numeric>
#include <iomanip>
#include <algorithm> // for sort

int main() {

	//std::vector<uint8_t> data{3,4,3,1,2};

	std::vector<uint8_t> data{
		3,3,5,1,1,3,4,2,3,4,3,1,1,3,3,1,5,4,4,1,
		4,1,1,1,3,3,2,3,3,4,2,5,1,4,1,2,2,4,2,5,
		1,2,2,1,1,1,1,4,5,4,3,1,4,4,4,5,1,1,4,3,
		4,2,1,1,1,1,5,2,1,4,2,4,2,5,5,5,3,3,5,4,
		5,1,1,5,5,5,2,1,3,1,1,2,2,2,2,1,1,2,1,5,
		1,2,1,2,5,5,2,1,1,4,2,1,4,2,1,1,1,4,2,5,
		1,5,1,1,3,1,4,3,1,3,2,1,3,1,4,1,2,1,5,1,
		2,1,4,4,1,3,1,1,1,1,1,5,2,1,5,5,5,3,3,1,
		2,4,3,2,2,2,2,2,4,3,4,4,4,1,2,2,3,1,1,4,
		1,1,1,2,1,4,2,1,2,1,1,2,1,5,1,1,3,1,4,3,
		2,1,1,1,5,4,1,2,5,2,2,1,1,1,1,2,3,3,2,5,
		1,2,1,2,3,4,3,2,1,1,2,4,3,3,1,1,2,5,1,3,
		3,4,2,3,1,2,1,4,3,2,2,1,1,2,1,4,2,4,1,4,
		1,4,4,1,4,4,5,4,1,1,1,3,1,1,1,4,3,5,1,1,
		1,3,4,1,1,4,3,1,4,1,1,5,1,2,2,5,5,2,1,5,
	};


	std::vector<uint64_t> world{ 0,0,0,0,0,0,0,0,0 };

	for (auto fish : data) {
		world.at(fish)++;
	}

	int days = 0;
	while (days++ < 256) {
		uint64_t newfish = world.at(0);
		world.erase(world.begin());
		world.push_back(newfish);
		world.at(6) += newfish;
	
		if (days == 80) {
			std::cout << "d:" << days << ' ';
			for (auto fish : world) {
				std::cout << fish << ' ';
			}
			std::cout << std::endl;

			//  accumulate(world.begin(), world.end(), 0);
			uint64_t sum = 0; 
			for (uint64_t fish : world) {
				sum += fish;
			}
			std::cout << "part1 : " << sum << std::endl;
		}
		
		if (days == 256) {
			std::cout << "d:" << days << ' ';
			for (auto fish : world) {
				std::cout << fish << ' ';
			}
			std::cout << std::endl;

			//  accumulate(world.begin(), world.end(), 0);
			uint64_t sum = 0; 
			for (uint64_t fish : world) {
				sum += fish;
			}
			std::cout << "part2 : " << sum << std::endl;
		}
	}
	return 0;
}
