#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <array>

/*
Right 1, down 1.
Right 3, down 1. (This is the slope you already checked.)
Right 5, down 1.
Right 7, down 1.
Right 1, down 2.
*/

int main(){
	std::array<int,5> adders{0,0,0,0,0};
	std::array<int,5> treesCount{0,0,0,0,0};
	const std::array<int,5> ADDER = {1,3,5,7,1};
	std::ifstream inputFile("day03.txt");        // Input file stream object
	//std::ifstream inputFile("day03_test.txt");
	if (inputFile.good()) {
		int lineNummer = 0;
		std::string line;
		while(inputFile >> line){
			for(auto index:{0,1,2,3,4}){
				if( line.at( adders[index]%line.size() ) == '#'){
					if(index == 4){
						if(lineNummer%2==0){
							treesCount[index]++;
							line.at(adders[index]%line.size()) = 'X';
						}
						else{
							//line.at(adders[index]%line.size()) = 'O';
						}
					}
					else{
						if(index==0){
							//line.at(adders[index]%line.size()) = 'X';
						}
						treesCount[index]++;
					}
				}
				else{
					if(index!=4){
						//line.at(adders[index]%line.size()) = 'O';
					}

				}
				if(index == 4){
					if(lineNummer%2==0){
						adders[index]+=ADDER[index];
					}
				}
				else{
					adders[index]+=ADDER[index];
				}
			}
			std::cout << line << " " << lineNummer << std::endl;
			lineNummer++;
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "part1: " << treesCount[1] << std::endl;

	long result = 1;
	std::cout << "part2: ";

	for(auto tree:treesCount){
		result *= tree;
		std::cout << tree << " ";
	}
	std::cout << "product = " << result << std::endl;

	return 0;
}

