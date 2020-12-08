#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
	std::vector<std::string> numbers;
	std::ifstream inputFile("day10.txt");        // Input file stream object

	if (inputFile.good()) {
		int min,max;
		char letter;
		char dummy;
		std::string password;
		while(inputFile >> min >> dummy >> max  >> letter >>  dummy >> password){
			std::cout << min << max << letter << password << std::endl;
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	for(std::string val:numbers){
		std::cout << val << std::endl;
	}

	std::cout << std::endl;
	std::cout << "part1:" << std::endl;
	std::cout << "part2:" << std::endl;
	return 0;
}

