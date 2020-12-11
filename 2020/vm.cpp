#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

std::string exec(const char* cmd);
std::string copy(std::string new_clipboard);

std::vector<std::pair<std::string, int> > program;
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

	std::ifstream inputFile("vm.txt");        // Input file stream object

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


	while( checkInstuctionCounter() && programcounter < program.size() ){
		auto instruction = program.at(programcounter);
		instructionCounter.at(programcounter)++;

		if(instruction.first == "acc"){
			accumulator += instruction.second;
			programcounter += 1;
		}
		else if(instruction.first == "jmp"){

			programcounter += instruction.second;
		}
		else if(instruction.first == "nop"){

			programcounter += 1;
		}
		else{
			assert(0);
		}
	}

	std::cout << "solution : " << accumulator << std::endl;
	copy( std::to_string(accumulator));

	return 0;
}

std::string exec(std::string cmd)
{
  FILE* pipe = popen(cmd.c_str(), "r");
  if (!pipe) return "ERROR";
  char buffer[128];
  std::string result = "";
  while(!feof(pipe)){
    if(fgets(buffer, 128, pipe) != NULL){
      result += buffer;
    }
  }
  pclose(pipe);
  return result;
}

std::string copy(std::string new_clipboard)
{
  std::stringstream cmd;
  cmd << "echo \"" << new_clipboard << "\" | pbcopy";
  return exec(cmd.str());
}