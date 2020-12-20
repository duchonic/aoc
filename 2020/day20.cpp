#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>

//std::array< std::array<std::bitset<10>,10>,9> puzzle;
std::array< std::array<std::string, 10>, 9> puzzle;

int main(){
	std::vector<std::string> numbers;
	std::ifstream inputFile("day20_test.txt");        // Input file stream object

	int partNr = -1;

	if (inputFile.good()) {

		int puzzleLine = 0;
		int actualLine = 0;
		for (std::string line; std::getline(inputFile, line); ) {

			if( std::string_view(line).starts_with("T") ){
				std::cout << line << std::endl;
				puzzleLine = 0;
				std::cout << "done part:" << partNr << " line:" << actualLine << std::endl;
				partNr++;
			}
			else if( std::string_view(line).starts_with("#") || std::string(line).starts_with(".") ){

				//std::bitset<10> a(line.c_str(), 10, '.', '#');
				std::cout << line << std::endl;
				std::replace(line.begin(), line.end(), '.', '0');
				std::replace(line.begin(), line.end(), '#', '1');
				puzzle.at(partNr).at(puzzleLine) = line;
				puzzleLine++;
			}
			actualLine++;
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	for(auto &part:puzzle){

		std::cout << std::endl << "newpart:" << std::endl;
		for(auto line: part){
			std::cout << line << std::endl;

		}

		std::cout << "firstline: " << part.at(0) << ':' << std::stoull( part.at(0), 0, 2 ) << std::endl;
		std::reverse( part.at(0).begin(), part.at(0).end() );
		std::cout << "firstline: " << part.at(0) << ':' << std::stoull( part.at(0), 0, 2 ) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "part1:" << std::endl;
	std::cout << "part2:" << std::endl;
	return 0;
}

