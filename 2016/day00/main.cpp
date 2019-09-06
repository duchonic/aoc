#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

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
	for (auto data : v) {
		INFO_LOG(data.command);
	}
}

/**
* @brief the mainloop
* 
*/
int main(){

	//std::cout << "aoc 2016 dayxy" << std::endl;
	INFO_LOG("aoc 2016 day xy");
	runProgram("../test.txt");
	runProgram("../data.txt");

	return 0;
}
