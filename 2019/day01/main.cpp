#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

// read file
struct inputType{
	int nr;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.nr;
		return is;
	}
};

int main(){

	std::vector<inputType> v;

	std::cout << "aoc 2019 day01" << std::endl;

	int totalSum = 0;
	int totalSumPartTwo = 0;
	
	auto file = std::ifstream("../data.txt");
	assert(file.is_open());

	for(inputType info; file >> info;){
		v.push_back(info);
	}


	for(auto info: v){
		int add = (info.nr/3)-2;
		totalSum += add;
		totalSumPartTwo += add;
		std::cout << "add/total/nr" << totalSum << "/" << add << "/" << info.nr << std::endl;
		while (true){
			add /= 3;
			add -= 2;
			if(add>0){
				totalSumPartTwo += add;
				std::cout << "part2 add/sum " << add << "/" << totalSumPartTwo << std::endl; 
			}
			else{
				break;
			}
		}
	}
	std::cout << "total:" << totalSum << std::endl;
	std::cout << "totalPart2:" << totalSumPartTwo << std::endl;

	return 0;
}
