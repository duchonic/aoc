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


class MyBot
{
public:
	MyBot(std::string newName);
	~MyBot();
	std::string name;
	void move(std::string moveCommand) {

		switch (moveCommand.at(0))
		{
			case 'R': {
				INFO_LOG("right");
				move(std::make_pair(1, 0));
				break;
			}
			case 'L': {
				INFO_LOG("left");
				move(std::make_pair(-1, 0));
				break;
			}
			case 'U': {
				INFO_LOG("up");
				move(std::make_pair(0, 1));
				break;
			}
			case 'D': {
				INFO_LOG("down");
				move(std::make_pair(0, -1));
				break;
			}
			default:
				assert(0);
				break;
			}
	}
	std::pair<int, int> getPos(void) {
		return std::make_pair(x, y);
	}

private:
	
	int x;
	int y;
	std::vector< std::pair<int, int> > trace;
	
	void move(std::pair<int, int> moveSteps) {
		if (moveSteps.first != 0) {
			x += moveSteps.first;
		}
		else {
			y += moveSteps.second;
		}
	};
};

MyBot::MyBot(std::string newName) : name(newName)
{
	x = 0;
	y = 0;
}

MyBot::~MyBot()
{
}

/**
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
* @return manhatten distance to nearest point
*/
int runProgram(std::string fileName) {

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	std::vector<std::string> bots;

	for (inputType data; file >> data;) {
		bots.push_back(data.line);
	}

	MyBot first("a");
	MyBot second("b");

	DEBUG_LOG("data from " << fileName);

	char delim = ',';
	std::string command;

	INFO_LOG(first.name);
	std::stringstream ss1(bots.at(0));
	while (std::getline(ss1, command, delim)) {
		INFO_LOG(command);
		first.move(command);
		auto pos = first.getPos();
		INFO_LOG("x:" << pos.first << " y:" << pos.second);
	}
	
	INFO_LOG(second.name);
	std::stringstream ss2(bots.at(1));
	while (std::getline(ss2, command, delim)) {
		INFO_LOG(command);
		second.move(command);
		auto pos = second.getPos();
		INFO_LOG("x:" << pos.first << " y:" << pos.second);
	}

	return 0;
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 03");

	assert( runProgram("../test_a.txt") == 0);
	//assert( runProgram("../test_b.txt") == 135);
	//INFO_LOG("part1: " << runProgram("../data.txt"));

	return 0;
}
