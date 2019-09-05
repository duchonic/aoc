#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

// read file
struct inputType{
	std::string command;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		return is;
	}
};

typedef std::pair<int,int> Point;

int main(){

	std::vector<inputType> v;

	std::vector<std::vector<int>> block{{7,4,1},{8,5,2},{9,6,3}};
	std::vector<std::vector<int>> blockPart2{ 
		{0,0,5,0,0}, 
		{0,0xA,6,2,0}, 
		{0xD,0xB,7,3,1}, 
		{0,0xC,8,4,0}, 
		{0,0,9,0,0}};

	Point pos{1,1};
	Point posPart2{0,2};

	std::cout << "test 0,1: " << block.at(2).at(1) << std::endl;
    std::cout << "test 0,2: " << blockPart2.at(posPart2.first).at(posPart2.second) << std::endl;
	std::cout << "aoc 2016 day02" << std::endl;
	
	auto testfile = std::ifstream("../test.txt");
	assert(testfile.is_open());

	for(inputType test; testfile >> test;){
		v.push_back(test);
	}

	std::cout << "test:" << std::endl;
	for(auto test: v){
		std::cout << test.command << std::endl;
		for(auto direction: test.command){
			switch(direction){
				case 'U':{
					if(pos.second < 2){
						pos.second++;
					}

					switch(posPart2.first){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.second < 3) {
								posPart2.second++;
							}
							break;
						}
						case 2:{
							if(posPart2.second < 4) {
								posPart2.second++;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				case 'D':{
					if(pos.second > 0){
						pos.second--;
					}

					switch(posPart2.first){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.second > 1) {
								posPart2.second--;
							}
							break;
						}
						case 2:{
							if(posPart2.second > 0) {
								posPart2.second--;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				case 'R':{
					if(pos.first < 2){
						pos.first++;
					}

					switch(posPart2.second){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.first < 3) {
								posPart2.first++;
							}
							break;
						}
						case 2:{
							if(posPart2.first < 4) {
								posPart2.first++;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				case 'L':{
					if(pos.first > 0){
						pos.first--;
					}

						switch(posPart2.second){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.first > 1) {
								posPart2.first--;
							}
							break;
						}
						case 2:{
							if(posPart2.first > 0) {
								posPart2.first--;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				default:{
					assert(0);
					break;
				}
			}
		}
		std::cout << "x:" << pos.first << "y:" << pos.second << std::endl;
		std::cout << "x:" << posPart2.first << "y:" << posPart2.second << std::endl;
		std::cout << "part 1 nr: " << block.at(pos.first).at(pos.second) << std::endl;
		std::cout << "part 2 nr: " << blockPart2.at(posPart2.first).at(posPart2.second) << std::endl;
	}

	pos.first = 1;
	pos.second = 1;
	posPart2.first = 0;
	posPart2.first = 2;

	v.clear();
	auto file = std::ifstream("../data.txt");
	assert(file.is_open());
	
	for(inputType data; file >> data;){
		v.push_back(data);
	}

	std::cout << "data:" << std::endl;
	for(auto data: v){
		for(auto direction: data.command){
			switch(direction){
				case 'U':{
					if(pos.second < 2){
						pos.second++;
					}

					switch(posPart2.first){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.second < 3) {
								posPart2.second++;
							}
							break;
						}
						case 2:{
							if(posPart2.second < 4) {
								posPart2.second++;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				case 'D':{
					if(pos.second > 0){
						pos.second--;
					}

					switch(posPart2.first){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.second > 1) {
								posPart2.second--;
							}
							break;
						}
						case 2:{
							if(posPart2.second > 0) {
								posPart2.second--;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				case 'R':{
					if(pos.first < 2){
						pos.first++;
					}

					switch(posPart2.second){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.first < 3) {
								posPart2.first++;
							}
							break;
						}
						case 2:{
							if(posPart2.first < 4) {
								posPart2.first++;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				case 'L':{
					if(pos.first > 0){
						pos.first--;
					}

						switch(posPart2.second){
						case 0:
						case 4:{
							break;
						}
						case 1:
						case 3:{
							if(posPart2.first > 1) {
								posPart2.first--;
							}
							break;
						}
						case 2:{
							if(posPart2.first > 0) {
								posPart2.first--;
							}
							break;
						}
						default:{
							assert(0);
							break;
						}
					}

					break;
				}
				default:{
					assert(0);
					break;
				}
			}
		}
		std::cout << "x:" << pos.first << "y:" << pos.second << std::endl;
		std::cout << "x:" << posPart2.first << "y:" << posPart2.second << std::endl;
		std::cout << "part 1 nr: " << block.at(pos.first).at(pos.second) << std::endl;
		std::cout << "part 2 nr: " << blockPart2.at(posPart2.first).at(posPart2.second) << std::endl;

	}
	return 0;
}
