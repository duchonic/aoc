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
#include <execution> // for parallel execution

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


	std::vector<int64_t> world1{0,0,0,0,0,0,0,0,0};
	std::vector<int64_t> world2{0,0,0,0,0,0,0,0,0};
	
	for (auto fish : data1) {
		world1.at(fish)++;
	}

	int days = 0;
	while (days++ < 256) {
		int newfish = world1.at(0);
		world1.erase(world1.begin());
		world1.push_back(newfish);
		world1.at(6) += newfish;
	}

	for (auto fish : world1) {
		std::cout << fish << ' ';
	}
	std::cout << std::endl;

	for (auto fish : data2) {
		world2.at(fish)++;
	}

	days = 0;
	while (days++ < 256) {
		int newfish = world2.at(0);
		world2.erase(world2.begin());
		world2.push_back(newfish);
		world2.at(6) += newfish;
	}

	for (auto fish : world2) {
		std::cout << fish << ' ';
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
	int64_t sum1 =  accumulate(world1.begin(), world1.end(), 0);
	int64_t sum2 =  accumulate(world2.begin(), world2.end(), 0);
	std::cout << "part1 : " << sum1 << ' ' << sum2 << std::endl;

	return 0;
}
