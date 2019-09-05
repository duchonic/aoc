#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

// read file
struct inputType{
	int a;
	int b;
	int c;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.a;
		is >> info.b;
		is >> info.c;
		return is;
	}
};

int main(){

	std::vector<inputType> v;
	

	std::cout << "aoc 2016 day03" << std::endl;
	
	auto testfile = std::ifstream("../test.txt");
	assert(testfile.is_open());

	for(inputType test; testfile >> test;){
		v.push_back(test);
	}

	std::cout << "test:" << std::endl;
	int works = 0;
	int fails = 0;
	for(auto test: v){

		std::multiset<int> triangle{test.a, test.b, test.c};
		std::cout << "new triangle: ";
		int count = 0;
		int sumOfSmalls = 0;
		for(int i: triangle){
			std::cout << i << " ";

			if(count++ <= 1){
				sumOfSmalls+=i;
			}
			else if(sumOfSmalls <= i){
				std::cout << "doesnt work" << std::endl;
				fails++;
			}
			else{
				std::cout << "works" << std::endl;
				works++;
			}
		}
	}
	std::cout << "works:" << works << " fails:" << fails << std::endl;

	v.clear();
	auto file = std::ifstream("../data.txt");
	assert(file.is_open());
	
	for(inputType data; file >> data;){
		v.push_back(data);
	}

	std::cout << "data:" << std::endl;
	works = 0;
	fails = 0;
	for(auto data: v){
		std::multiset<int> triangle{data.a, data.b, data.c};
		std::cout << "new triangle: ";
		int count = 0;
		int sumOfSmalls = 0;
		for(int i: triangle){
			std::cout << i << " ";

			if(count++ <= 1){
				sumOfSmalls+=i;
			}
			else if(sumOfSmalls > i){
				std::cout << "works" << std::endl;
				works++;
			}
			else{
				std::cout << "doesnt work" << std::endl;
				fails++;
			}
		}
	}
	std::cout << "works:" << works << " fails:" << fails << " sum:" << works+fails << std::endl;
	

	return 0;
}
