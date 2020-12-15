#include <iostream>
#include <fstream>
#include <string>
#include <complex>
#include <vector>
#include <math.h>


int main(){
	std::ifstream inputFile("day13_test.txt");        // Input file stream object
	if (inputFile.good()) {
		std::vector<int> buslines;
		std::string line;
		std::getline(inputFile, line);
		int nr = std::stoi(line);
		std::getline(inputFile, line);
		std::replace(line.begin(), line.end(), ',', ' ');
		std::replace(line.begin(), line.end(), 'x', ' ');
		//std::cout << line << std::endl;

		std::ifstream busline(line);
		int bus;
		while(busline >> bus){
			std::cout << bus << std::endl;
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "part1: "  << std::endl;
	std::cout << "part2:" << std::endl;
	return 0;
}

