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
	std::string first;
	std::string second;
	std::string third;

	friend std::istream& operator>>(std::istream& is, inputType& info){
		std::getline(is, info.first, '[');
		std::getline(is, info.second, ']');
		std::getline(is, info.third);
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
	
	int support = 0;

	for (auto data : v) {
		bool insideCheck = false;
		bool outsideCheck = false;

		INFO_LOG(data.first << " " << data.second << " " << data.third);

		for (int pos = 0; pos < (data.first.size()-3); pos++) {
			std::string left{ data.first.substr(pos, 2) };
			std::string right{ data.first.substr(pos+2, 2) };
			std::reverse(right.begin(), right.end());
			if (left == right && (left[0] != left[1])) {
				outsideCheck = true;
				INFO_LOG("first match check:" << left << " with:" << right);
			}
		}


		for (int pos = 0; pos < (data.second.size()-3); pos++) {
			std::string left{ data.second.substr(pos, 2) };
			std::string right{ data.second.substr(pos+2, 2) };
			std::reverse(right.begin(), right.end());
			if (left == right) {
				insideCheck = true;
				INFO_LOG("second match check:" << left << " with:" << right);
			}
		}


		for (int pos = 0; pos < (data.third.size()-3); pos++) {
			std::string left{ data.third.substr(pos, 2) };
			std::string right{ data.third.substr(pos+2, 2) };
			std::reverse(right.begin(), right.end());
			if (left == right && (left[0]!=left[1])) {
				outsideCheck = true;
				INFO_LOG("third match check:" << left << " with:" << right);
			}
		}

		if (insideCheck) {
			//INFO_LOG("does not support, ABBA inside");
		}
		else if (outsideCheck) {
			INFO_LOG(" =========>>> does support!");
			support++;
		}

	}
	INFO_LOG("SUPPORT:" << support);
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2016 day 07");

	runProgram("../test.txt");
	runProgram("../data.txt");

	return 0;
}
