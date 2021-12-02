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


static int32_t calcPath( std::vector<std::string> input, bool aim) {
	typedef struct {
		int32_t x;
		int32_t y;
		int32_t aim;
	}Position;

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
		
		if (direction == "forward") {
			pos.x += distance;
			if (aim) {
				pos.y += pos.aim * distance;
			}
		}
		else if (direction == "up") {
			if (aim) {	
				pos.aim -= distance;
			}
			else {
				pos.y -= distance;
			}
		}
		else if (direction == "down") {
			if (aim) {
				pos.aim += distance;
			}
			else {
				pos.y += distance;
			}
		}
	}
	return (pos.x * pos.y);
}


int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "part1 : " << calcPath(data, false) << std::endl;
	std::cout << "part2 : " << calcPath(data, true) << std::endl;
	return 0;
}
