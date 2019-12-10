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
<<<<<<< HEAD
=======
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
>>>>>>> f69be15c8a1658e58b9bc238aed6779e3fd2ee48
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
* @return manhatten distance to nearest point
*/
<<<<<<< HEAD
int runProgram() {
	int workingNrPart1=0;
	int workingNrPart2=0;
	for(int nr= 231832; nr < 767346;nr++){
		std::string strNr{std::to_string(nr)};
		int lastNr = -1;
		bool equal = false;
		std::array<int,10> counts{1,1,1,1,1,1,1,1,1,1};
		for (auto ch: strNr){
			if( (int(ch)-0x30) >= lastNr){
				if( (int(ch)-0x30) == lastNr){
					counts.at(lastNr)++;
					equal = true;
				}
				lastNr = int(ch)-0x30;
			}
			else{
				lastNr = -1;
				break;
			}
		}
		if(equal && (lastNr != -1)){
			bool checkPart2 = false;
			for (auto count : counts) {
				if (count == 2) {
					workingNrPart2++;
					break;
				}
			}
            workingNrPart1++;
		}
	}
	INFO_LOG("part2 check true: " << workingNrPart2);
	return workingNrPart1;
=======
int runProgram(std::string fileName)
{
	int result = 0;
	std::vector< std::string > tree;

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	INFO_LOG("run: " << fileName);

	for (inputType data; file >> data;) {
		if (data.connection.first == "COM") {
			tree.push_back(data.connection.second);
			INFO_LOG(data.connection.first << " >> " << data.connection.second);
		}
	}

	return result;
>>>>>>> f69be15c8a1658e58b9bc238aed6779e3fd2ee48
}

/**
* @brief the mainloop
<<<<<<< HEAD
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 04");
	int result = runProgram();
	INFO_LOG("part1: " << result);
=======
*/
int main()
{
	INFO_LOG("aoc 2019 day 06");
	assert(runProgram("../test.txt") == 0);
	//INFO_LOG("part1: " << runProgram("../data.txt"));
>>>>>>> f69be15c8a1658e58b9bc238aed6779e3fd2ee48
	return 0;
}
