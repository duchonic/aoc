#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::pair<std::string, int>> program;
std::vector<int> instructionCounter;

bool checkInstuctionCounter(){
	for(auto counter : instructionCounter){
		if(counter >= 2){
			return false;
		}
	}
	return true;
}

int main(){
	std::ifstream inputFile("day08.txt");        // Input file stream object
	if (inputFile.good()) {
		std::string operation;
		int argument;
		while(inputFile >> operation >> argument){
			program.push_back(std::make_pair(operation, argument));
			instructionCounter.push_back(0);
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	int accumulator = 0;
	int programcounter = 0;
	int flipper = 0;

	while(programcounter < program.size() && flipper < program.size()-1 ){

		accumulator = 0;
		programcounter = 0;
		for(int &counter : instructionCounter){
			counter = 0;
		}
		std::cout << "test FLIPPER: " << flipper << std::endl;


		if(flipper == 0){
			//first round
		}
		else{
			//flipp back
			if( program.at(flipper-1).first == "nop"){
				program.at(flipper-1).first = "jmp";
			}
			else if( program.at(flipper-1).first == "jmp"){
				program.at(flipper-1).first = "nop";
			}
		}

		for(int pos=flipper;pos<program.size();pos++){

			if( program.at(pos).first == "nop"){
				program.at(pos).first = "jmp";
				flipper = pos+1;
				break;
			}
			else if( program.at(pos).first == "jmp"){
				program.at(pos).first = "nop";
				flipper = pos+1;
				break;
			}
		}

		for(auto instruction : program){
			std::cout << instruction.first << ' ' << instruction.second << std::endl;
		}

		while( checkInstuctionCounter() && programcounter < program.size() ){

			auto instruction = program.at(programcounter);
			instructionCounter.at(programcounter)++;
			if(instruction.first == "acc"){
				accumulator += instruction.second;
				programcounter++;
				std::cout << "acc:" << accumulator << " pc:" << programcounter << std::endl;
			}
			else if(instruction.first == "jmp"){
				programcounter+=instruction.second;
			}
			else if(instruction.first == "nop"){
				programcounter++;
			}
			else{
				assert(0);
			}
			std::cout << accumulator <<  '/' << programcounter << std::endl;
		}

	}

	if(programcounter >= program.size()){
		std::cout << "we found a solution" << std::endl;
	}


	std::cout << "part2: " << std::endl;
	return 0;
}

