#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <array>
#include "log.h"

/**
* @brief process data in file with this struct
*
*/
struct inputType{
	std::string command;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		return is;
	}
};

/**
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
*
*/
void runProgram(std::string fileName) {

	std::vector<inputType> v;
	std::array< std::map<char, uint16_t>, 8> cols;

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	for (inputType data; file >> data;) {
		v.push_back(data);
	}

	DEBUG_LOG("data from " << fileName);
	
	std::unordered_map<char, uint16_t> count;
	
	for (auto data : v) {
		INFO_LOG(data.command);
		size_t index = 0;
		for (char ch : data.command) {
			cols[index++][ch]++;
		}
	}
	std::string solution{ "" };
	for (size_t index : {0, 1, 2, 3, 4, 5, 6, 7}) {
		char maxChar;
		uint16_t min = 50000;
		for (auto ch : cols[index]) {
			if (ch.second < min) {
				min = ch.second;
				maxChar = ch.first;
			}
		}
		solution += maxChar;
		INFO_LOG("col:" << index << " max char: " << maxChar);
	}

	DEBUG_LOG(solution);

	for (auto data : v) {
		count.clear();

		for (char ch : data.command) {
			count[ch]++;
		}

		using myPair = std::pair<char, unsigned int>;
		auto comp = [](const myPair& a, const myPair& b) {
			return (a.second > b.second || a.second == b.second && a.first < b.first);
		};

		std::set<myPair, decltype(comp) > sorted(comp);
		for (auto const& kv : count)
			sorted.insert(kv);

		//DEBUG_LOG("Sorted list according to frequency then alphabetically");
		for (auto const& kv : sorted){
			//DEBUG_LOG( kv.first << " = " << kv.second );
		}
	}
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2016 day 06");

	runProgram("../test.txt");
	//runProgram("../data.txt");

	return 0;
}
