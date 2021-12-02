/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
    */

#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"

typedef struct {
	int32_t x;
	int32_t y;
	int32_t aim;
}Position;

static int32_t calcPath( std::vector<std::string> input) {
	Position pos = {
		.x = 0,
		.y = 0,
	};

	for (auto line: input) {
		std::stringstream s(line);
		std::string direction;
		int16_t distance;

		s >> direction;
		s >> distance;
		
		if (direction.compare("forward") == 0) {
			pos.x += distance;
		}
		else if (direction.compare("up") == 0) {
			pos.y -= distance;
		}
		else if (direction.compare("down") == 0) {
			pos.y += distance;
		}
	}
	log("endpos x:" << pos.x << " y:" << pos.y);
	return (pos.x * pos.y);
}
static int32_t calcPath2( std::vector<std::string> input) {
	Position pos = {
		.x = 0,
		.y = 0,
		.aim = 0,
	};

	for (auto line: input) {
		std::stringstream s(line);
		std::string direction;
		int16_t distance;

		s >> direction;
		s >> distance;
		
		if (direction.compare("forward") == 0) {
			pos.x += distance;
			pos.y += pos.aim * distance;
		}
		else if (direction.compare("up") == 0) {
			pos.aim -= distance;
		}
		else if (direction.compare("down") == 0) {
			pos.aim += distance;
		}
	}
	log("endpos x:" << pos.x << " y:" << pos.y);
	return (pos.x * pos.y);
}


int main() {

	int16_t part2 = 0;
	
	std::vector<std::string> data = readstuff();
	std::cout << "part1 : " << calcPath(data) << std::endl;
	std::cout << "part2 : " << calcPath2(data) << std::endl;

	return 1;
}
