#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <algorithm>

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

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	for (inputType data; file >> data;) {
		v.push_back(data);
	}

	DEBUG_LOG("data from " << fileName);
	
	std::unordered_map<char, uint16_t> count;
	
	for (auto data : v) {
		count.clear();

		for (char ch : data.command) {
			count[ch]++;
		}

		INFO_LOG(data.command);
		//for (auto [key, value] : count) {
		//	DEBUG_LOG("key:" << key << " value:" << value);
		//}

		using myPair = std::pair<char, unsigned int>;
		auto comp = [](const myPair& a, const myPair& b) {
			return (a.second > b.second || a.second == b.second && a.first < b.first);
		};

		std::set<myPair, decltype(comp) > sorted(comp);
		for (auto const& kv : count)
			sorted.insert(kv);

		DEBUG_LOG("Sorted list according to frequency then alphabetically");
		for (auto const& kv : sorted){
			DEBUG_LOG( kv.first << " = " << kv.second );
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
