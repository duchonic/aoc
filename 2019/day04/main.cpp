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
*
*/
struct inputType
{
	std::string line;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.line;
		return is;
	}
};


/**
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
* @return manhatten distance to nearest point
*/
int runProgram(std::string fileName) {
	auto file = std::ifstream(fileName);
	assert(file.is_open());
	DEBUG_LOG("data from " << fileName);

	std::vector<std::string> bots;
	for (inputType data; file >> data;) {
		bots.push_back(data.line);
		DEBUG_LOG(data.line);
	}

	return 0;
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 04");
	assert( runProgram("../test_a.txt") == 0);
	assert( runProgram("../test_b.txt") == 0);
	int result = runProgram("../data.txt");
	INFO_LOG("part1: " << result);
	return 0;
}
