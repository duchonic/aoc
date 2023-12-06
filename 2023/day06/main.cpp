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


std::vector<int64_t> tries_to_beat_the_game(int64_t time, int64_t distance) {
	std::vector<int64_t> returnValue;
	for (int64_t speed = 0; speed < time; speed++) {
		 int64_t race_time = time - speed;
		 int64_t race_distance = speed * race_time;
		 if (race_distance > distance ) {
			returnValue.push_back(speed);
		 }
	}
	return returnValue;
}

/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input, bool DoPart2) {
	int64_t returnValue = 1;

/*  test data
	Time:      7  15   30
	Distance:  9  40  200
	real data
	Time:        35     93     73     66
	Distance:   212   2060   1201   1044
*/
	//test data
	//std::vector<int> times = {7, 15, 30};
	//std::vector<int> distances = {9, 40, 200};

	//real data
	//std::vector<int> times = {35, 93, 73, 66};
	//std::vector<int> distances = {212, 2060, 1201, 1044};

    // part 2 with test data
	//std::vector<int> times = {71530};
	//std::vector<int> distances = {940200};

	// part 2 with real data
	std::vector<int64_t> times = {35937366};
	std::vector<int64_t> distances = {212206012011044};

	for (int race=0; race<times.size(); race++) {
		std::cout << "race nr: " << race << std::endl;
		auto race1 = tries_to_beat_the_game(times.at(race), distances.at(race));
		returnValue *= race1.size(); 
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
