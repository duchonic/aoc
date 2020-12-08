#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

int main(){
	std::vector<std::set<char>> persons;
	std::set<char> answers;
	long sumAnswers = 0;
	long sumSimmilarAnswers = 0;
	std::ifstream inputFile("day06.txt");        // Input file stream object


	if (inputFile.good()) {
		for (std::string line; std::getline(inputFile, line); ) {
			if(line.size()){
				std::set<char> oneperson;
				for(char c : line){
					answers.insert(c);
					oneperson.insert(c);
				}
				persons.push_back(oneperson);
			}
			else{
				for(char c:persons.at(0)){
					int count = 0;
					for(auto person: persons){
						auto serach = person.find(c);
						if(serach != person.end() ){
							count++;
						}
					}
					if(count >= persons.size()){
						sumSimmilarAnswers++;
					}
				}
				persons.clear();
				std::cout << "check group size: " << answers.size() << std::endl << std::endl;
				sumAnswers += answers.size();
				answers.clear();
			}
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	std::cout << "part1: " << sumAnswers << std::endl;
	std::cout << "part2: " << sumSimmilarAnswers << std::endl;
	return 0;
}

