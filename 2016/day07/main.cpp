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

	std::string line;
	std::vector<std::string> inner;
	std::vector<std::string> outer;


	friend std::istream& operator>>(std::istream& is, inputType& info){



		info.inner.clear();
		info.outer.clear();

		std::getline(is, info.line);

		INFO_LOG(info.line);

		std::istringstream line( info.line );

		std::string innerLine;
		std::string outerLine;

		for (int i = 0; i < std::count(info.line.begin(), info.line.end(), '['); i++) {

			std::getline(line, outerLine, '[');
			info.outer.push_back(outerLine);
			std::getline(line, innerLine, ']');
			info.inner.push_back(innerLine);
			
		}
		std::getline(line, outerLine);
		info.outer.push_back(outerLine);

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

		INFO_LOG(data.line);

		for (auto item : data.outer) {
			//INFO_LOG("outer: " << item);
			for (int pos = 0; pos < (item.size() - 3); pos++) {
				std::string left{ item.substr(pos, 2) };
				std::string right{ item.substr(pos + 2, 2) };
				std::reverse(right.begin(), right.end());
				if (left == right && (left[0] != left[1])) {
					outsideCheck = true;
					INFO_LOG("outer match check:" << left << " with:" << right);
				}
			}
		}

		for (auto item : data.inner) {
			//INFO_LOG("inner: " << item);
			for (int pos = 0; pos < (item.size() - 3); pos++) {
				std::string left{ item.substr(pos, 2) };
				std::string right{ item.substr(pos + 2, 2) };
				std::reverse(right.begin(), right.end());
				if (left == right) {
					insideCheck = true;
					INFO_LOG("inner match check:" << left << " with:" << right);
				}
			}
		}

		if (insideCheck) {
			INFO_LOG("does not support, ABBA inside\n");
		}
		else if (outsideCheck) {
			INFO_LOG(" =========>>> does support!\n");
			support++;
		}
		else {
			INFO_LOG("does not support\n");
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

	//runProgram("../test.txt");
	runProgram("../data.txt");

	return 0;
}
