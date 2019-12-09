#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <map>
#include <array>
#include "log.h"

/**
* @brief process data in file with this struct
*/
struct inputType
{
	std::pair<std::string, std::string> connection;

	friend std::istream& operator>>(std::istream& is, inputType& info) {
		std::string input;
		is >> input;
		if (input.size() > 0) {
			std::size_t firstString = 0;
			auto secondString = input.find_first_of(")");
			info.connection.first = input.substr(firstString, secondString);
			info.connection.second = input.substr(secondString+1);
		}
		return is;
	}
};

/**
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
* @return manhatten distance to nearest point
*/
int runProgram(std::string fileName)
{
	int result = 0;

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	INFO_LOG("run: " << fileName);

	for (inputType data; file >> data;) {
		INFO_LOG(data.connection.first << " >> " << data.connection.second);
	}
	return result;
}

/**
* @brief the mainloop
*/
int main()
{
	INFO_LOG("aoc 2019 day 06");
	assert(runProgram("../test.txt") == 42);
	INFO_LOG("part1: " << runProgram(""));
	return 0;
}
