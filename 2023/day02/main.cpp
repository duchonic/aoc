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

	int64_t gamenr = 1;

	for (std::string line : input) {

		std::vector<std::string> package;
		split_str(line, ':', package);
		
		std::vector<std::string> color;
		split_str(package[1], ';', color);	

		bool saturated = false;

		color_pixel actual_pixel = {0, 0, 0};
		for (auto item : color) {
			std::vector<std::string> pixel;
			split_str(item, ',', pixel);
			for (auto c: pixel) {
				std::vector<std::string> value;
				split_str(c, ' ', value);
				
				if (find(value.at(2), "gr")) {
					
					uint8_t green = std::atoi(value.at(1).c_str());

					if (green > actual_pixel.green) {
						actual_pixel.green = green;
					}
					if (std::atoi (value.at(1).c_str() ) > setting.green) {
						saturated = true;
					}
				} else if (find(value.at(2), "red")) {

					uint8_t red = std::atoi(value.at(1).c_str());

					if (red > actual_pixel.red) {
						actual_pixel.red = red;
					}
					if (std::atoi (value.at(1).c_str() ) > setting.red) {
						saturated = true;
					}
				} else if (find(value.at(2), "bl")) {
					
					uint8_t blue = std::atoi(value.at(1).c_str());
					if (blue > actual_pixel.blue) {
						actual_pixel.blue = blue;
					}
					if (std::atoi (value.at(1).c_str() ) > setting.blue) {
						saturated = true;
					}
				}
			}
		}
		
		if (DoPart2) {
			returnValue += actual_pixel.red * actual_pixel.green * actual_pixel.blue;
		} else {
			if (!saturated) {
				returnValue += gamenr;
			}
		}
		gamenr++;
	}
	return returnValue;	
}


int main() {
	color_pixel setting = {12,13,14};

	std::vector<std::string> data = readstuff();
	std::cout << "2023 day01 solve part 1" << std::endl;
	int64_t part1 = solve(data, false, setting);
	std::cout << "2023 day01 solve part 2" << std::endl;
	int64_t part2 = solve(data, true, setting);
	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
