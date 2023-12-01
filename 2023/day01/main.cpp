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

#include <regex>
#include <string>

/**
 * @brief solves the problem
 */
static int64_t solve(std::vector<std::string> input) {
	int64_t returnValue = 0;

	for (auto line : input) {

		//std::cout << "solved with reges: " << std::regex_replace(line, std::regex(R"([a-z])"), "")  << std::endl;
		auto solve_line = line;
		std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

		int index = 0;
		for (auto &number : numbers) {
			solve_line = std::regex_replace(solve_line, std::regex(number), std::to_string(index));
			//std::cout << "number: " << number << " index: " << index << std::endl;
			index++;
		}
		std::cout << "solved with reges: " << solve_line << std::endl;
		auto value = std::regex_replace(solve_line, std::regex(R"([a-z])"), "");

		auto first = value.begin();
		auto last = value.end()-1;

		std::cout << "first: " << *first << " last: " << *last << std::endl;
		
		returnValue += *last - '0';
		returnValue += (*first - '0') * 10;
		std::cout << "return value: " << returnValue << std::endl;

	}
	return returnValue;	
}


int main() {
	std::vector<std::string> data = readstuff();
	std::cout << "2023 day01 solve part 1" << std::endl;
	int64_t part1 = solve(data);
	//std::cout << "2023 day01 solve part 2" << std::endl;
	int64_t part2 = solve(data);
	std::cout << "part1 : " << part1 << std::endl;
	//std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
