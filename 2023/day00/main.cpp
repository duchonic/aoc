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
static int16_t sonarScope(std::vector<int16_t> input, int8_t width) {
	int16_t lineNumber = 0;
	int32_t lastNumber = 10000;
	int16_t returnValue = 0;
	for (auto dummy : input) {
		try{
			int32_t actualNumber = 0;
			for (uint8_t w = 0; w < width; w++) {
				actualNumber += input.at(lineNumber+w);	
			}
			if (actualNumber > lastNumber) {
				returnValue++;
			}	
			lastNumber = actualNumber;
		}
		catch(const std::out_of_range& e) {
			(void)e;
			logger("this is the end...");
			break;
		}
		lineNumber++;
	}
	return returnValue;	
}


int main() {
	std::vector<int16_t> data = readstuff2int();
	int16_t part1 = sonarScope(data, 1);
	int16_t part2 = sonarScope(data, 3);
	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
