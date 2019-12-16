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
#include "json.h"
#include "log.h"

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

int runProgram(std::string fileName)
{
	int result = 0;
	std::vector< std::string > tree;

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	INFO_LOG("run: " << fileName);

	// for convenience
	using json = nlohmann::json;
	json Connections;

	std::map<std::string, int> treeDistances;
	std::map<std::string, std::string> directions;

	for (inputType data; file >> data;) {
		treeDistances.insert(std::make_pair(data.connection.second, 0));
		directions.insert(std::make_pair(data.connection.second, data.connection.first));
	}

	int count = 0;
	

	for (auto destinations : treeDistances) {
		auto start = destinations.first;
		bool printFlag = false;
		if (start == "YOU" || start == "SAN") {
			printFlag = true;
		}

		if (printFlag) {
			INFO_LOG("route from: " << start << " count: " << count);
		}
		while (start != "COM") {
			count++;
			start = directions[start];
			if (printFlag) {
				std::cout << start << " ";
			}
		}
		if (printFlag) {
			std::cout << std::endl;
		}
	}
	return count;
}

int main()
{
	INFO_LOG("aoc 2019 day 06");
	assert(runProgram("../test.txt") == 42);
	INFO_LOG("part1: " << runProgram("../data.txt"));
	return 0;
}
