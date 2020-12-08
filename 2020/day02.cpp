#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <algorithm>


int main(){
	std::vector<std::string> numbers;
	std::ifstream inputFile("day02.txt");        // Input file stream object

	int countPassword = 0;
	int countPasswordPart2 = 0;
	if (inputFile.good()) {
		int min,max;
		char letter;
		char dummy;
		std::string password;
		
		while(inputFile >> min >> dummy >> max  >> letter >>  dummy >> password){
			int count = std::count(password.begin(), password.end(), letter);
			std::cout << min << max << letter << ' ' << password << std::endl;
			std::cout << std::count(password.begin(), password.end(), letter) << std::endl;
			if(count >= min && count <= max){
				countPassword++;
			}
			char a = password.at(min-1);
			char b = password.at(max-1);

			if( (a==letter || b == letter) && a != b){
				countPasswordPart2++;
			}
			//std::cout << password.at(min-1) << ' ' << password.at(max-1) << std::endl;
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	for(auto val:numbers){
		std::cout << val << std::endl;
	}

	std::cout << std::endl;
	std::cout << "part1:" << countPassword << std::endl;

	std::cout << "part2:" << countPasswordPart2 << std::endl;
	return 0;
}

