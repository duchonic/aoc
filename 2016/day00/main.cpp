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
	int nr;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		is >> info.nr;
		return is;
	}
};

int main(){

	std::vector<inputType> v;

	std::cout << "aoc 2016 dayxy" << std::endl;
	
	auto testfile = std::ifstream("../test.txt");
	assert(testfile.is_open());

	for(inputType test; testfile >> test;){
		v.push_back(test);
	}

	std::cout << "test:" << std::endl;
	for(auto test: v){
		std::cout << test.command << std::endl;
	}

	v.clear();
	auto file = std::ifstream("../data.txt");
	assert(file.is_open());
	
	for(inputType data; file >> data;){
		v.push_back(data);
	}

	std::cout << "data:" << std::endl;
	for(auto data: v){
		std::cout << data.command << " nr:" << data.nr << std::endl;
	}
	

	return 0;
}
