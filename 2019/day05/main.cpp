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


/**
 * @brief sonar scope count positives slopes in data input
 * 
 * @param input vector with data
 * @param width width of windows to calculate
 * @return int16_t sum of positives slopes
 */
static int16_t sonarScope(std::vector<std::string> input, int8_t width) {
	int16_t lineNumber = 0;

	return returnValue;	
}


int main() {
	std::vector<std::string> data = readstuff();
	int16_t part1 = sonarScope(data, 1);
	int16_t part2 = sonarScope(data, 3);
	std::cout << "part1 xyz : " << part1 << std::endl;
	std::cout << "part2 abc: " << part2 << std::endl;
	return 0;
}
