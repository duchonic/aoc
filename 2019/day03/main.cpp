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
* Bot who travells around Class
*
*/
class MyBot
{
public:
	MyBot(std::string newName);
	~MyBot();
	std::string name;
	void move(std::string moveCommand) {
		int moves = std::stoi( moveCommand.substr(1) );
		switch (moveCommand.at(0)){
			case 'R': {
				move(std::make_pair(moves, 0));
				break;
			}
			case 'L': {
				move(std::make_pair(-moves, 0));
				break;
			}
			case 'U': {
				move(std::make_pair(0, moves));
				break;
			}
			case 'D': {
				move(std::make_pair(0, -moves));
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
	std::vector< std::pair<int, int>> getTrace(void){
		return trace;
	}
	std::vector<int> getSteps(void){
		return steps;
	}

private:
	
	int x;
	int y;
	int step;

	std::vector< std::pair<int, int> > trace;
	std::vector<int> steps;

	void move(std::pair<int, int> moveSteps) {
		if (moveSteps.first != 0) {
			int endposX = (x+moveSteps.first);
			if (endposX > x){
				while( x < endposX){
					trace.push_back(std::make_pair(++x,y));
					steps.push_back(++step);
				}
			}
			else{
				while( x > endposX){
					trace.push_back(std::make_pair(--x,y));
					steps.push_back(++step);
				}
			}
		}
		else {
			int endposY = (y+moveSteps.second);
			if(endposY > y){
				while(y < endposY){
					trace.push_back(std::make_pair(x,++y));
					steps.push_back(++step);
				}
			}
			else{
				while( y > endposY){
					trace.push_back(std::make_pair(x,--y));
					steps.push_back(++step);
				}
			}
		}
	};
};

MyBot::MyBot(std::string newName) : name(newName)
{
	x = 0;
	y = 0;
	step = 0;
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
		first.move(command);
		auto pos = first.getPos();
	}
	std::vector<std::pair<int,int>> firstTrace = first.getTrace();
	auto firstSteps = first.getSteps();

	INFO_LOG(second.name);
	std::stringstream ss2(bots.at(1));
	while (std::getline(ss2, command, delim)) {
		second.move(command);
		auto pos = second.getPos();
	}
	std::vector<std::pair<int,int>> secondTrace = second.getTrace();
	auto secondSteps = second.getSteps();

	int minimumManhatten = 100000;
	int minimumSteps = 1000000;
	int secondPos = 0;
	for (auto secondKey : secondTrace){

		int firstPos = 0;
		for (auto firstKey : firstTrace){
			if( firstKey == secondKey){
				int manhatten = abs(firstKey.first) + abs(firstKey.second);
				INFO_LOG("found, distance: " << manhatten);
				//INFO_LOG("firstpos." << firstPos << " second." << secondPos);
				//INFO_LOG("firststeps." << firstSteps.at(firstPos));
				//INFO_LOG("secondstps." << secondSteps.at(secondPos));
				int stepsTotal = firstSteps.at(firstPos) + secondSteps.at(secondPos);
				//INFO_LOG("steps." << stepsTotal);
				if(manhatten < minimumManhatten){
					minimumManhatten = manhatten;
				}
				if(stepsTotal < minimumSteps){
					minimumSteps = stepsTotal;
				}
			}
			firstPos++;
		}
		secondPos++;
	}
	INFO_LOG("part2:" << minimumSteps);
	return minimumManhatten;
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 03");
	assert( runProgram("../test_a.txt") == 159);
	assert( runProgram("../test_b.txt") == 135);
	INFO_LOG("part1: " << runProgram("../data.txt"));
	return 0;
}
