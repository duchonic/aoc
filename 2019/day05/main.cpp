#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

#define ADD 		1
#define MULTIPLY 	2
#define STORE 		3
#define LOAD        4
#define EXIT 		99

int calc(std::vector<int> input, int code){
	int i = 0;
	if(input.at(i) == ADD){
		input.at( input.at(i+3) ) = input.at( input.at(i+1) ) + input.at( input.at(i+2) );
	}
	else if(input.at(i) == MULTIPLY){
		input.at( input.at(i+3) ) = input.at( input.at(i+1) ) * input.at( input.at(i+2) );
	}
	else if(input.at(i) == STORE){
		
	}
	else if(input.at(i) == EXIT){
		assert(0);
	}

	return 0;
}

int runProgram(int inputValue, std::vector<int> input){
	int output = 0;

	int pc = 0;
	bool running = true;
	int diagnosticCode = 0;
	while (running) {

		switch (input[pc]) 
		{
			case ADD: {
				int cmd = input[pc++];
				int first = input[pc++];
				int second = input[pc++];
				int result = input[pc++];
				std::cout << "pc:" << pc <<  " add   cmd:" << cmd << "  " << input[first] << " + " << input[second] << " = " << input[result]  << std::endl;				
				input[result] = input[first] + input[second];
				break;
			}
			case MULTIPLY: {
				int cmd = input[pc++];
				int first = input[pc++];
				int second = input[pc++];
				int result = input[pc++];
				std::cout << "pc:" << pc << " mul   cmd:" << cmd << " " << input[first] << " * " << input[second] << " = " << input[result] << std::endl;
				input[result] = input[first] + input[second];
				break;
			}
			case STORE: {
				int cmd = input[pc++];
				int parameter = input[pc++];
				std::cout << "pc:" << pc << " store cmd:" << cmd << " input  value:" << parameter << std::endl;
				input[parameter] = inputValue;
				break;
			}
			case LOAD: {
				int cmd = input[pc++];
				int parameter = input[pc++];
				std::cout << "pc:" << pc << " load  cmd:" << cmd << " output value:" << parameter << std::endl;
				output = input[parameter];
				break;
			}
			case 99: {
				running = false;
				break;
			}
			default:{
				
				int opcode = input[pc]%100;
				std::cout << "opcode:" << opcode << " ";
				int firstFlag = input[pc]%1000 / 100;
				int secondFlag = input[pc]%10000 / 1000;
				int thirdFlag = input[pc]%100000 / 10000;
				std::cout << input[pc++] << std::endl;
				std::cout << " " << thirdFlag << " " << secondFlag << " " << firstFlag << std::endl;
				
				switch (opcode){
					case ADD: {
						int first = input[pc++];
						int second = input[pc++];
						int result = input[pc++];
						std::cout << "pc:" << pc <<  " add cmd:" << opcode << "  " << input[first] << " + " << input[second] << " = " << input[result]  << std::endl;				
						input[result] = input[first] + input[second];
						break;
					}
					case MULTIPLY: {
						int first = input[pc++];
						int second = input[pc++];
						int result = input[pc++];
						std::cout << "pc:" << pc << " mul cmd:" << opcode << " " << input[first] << " * " << input[second] << " = " << input[result] << std::endl;
						input[result] = input[first] + input[second];
						break;
					}
					default:{
						break;
					}
				}
				running = false;
				break;
			}
		}
	}
	return output;
}


int main(){
	std::vector<int> input{
		3, 225, 1, 225, 6, 6, 1100, 1, 238,225, 104,0,  1101,69,55,225, 1001,144,76,224,101,-139,224,224,4,224,1002,223,8,223,1001,224,3,224,1,223,224,223,1102,60,49,225,1102,51,78,225,1101,82,33,224,1001,224,-115,224,4,224,1002,223,8,223,1001,224,3,224,1,224,223,223,1102,69,5,225,2,39,13,224,1001,224,-4140,224,4,224,102,8,223,223,101,2,224,224,1,224,223,223,101,42,44,224,101,-120,224,224,4,224,102,8,223,223,101,3,224,224,1,223,224,223,1102,68,49,224,101,-3332,224,224,4,224,1002,223,8,223,1001,224,4,224,1,224,223,223,1101,50,27,225,1102,5,63,225,1002,139,75,224,1001,224,-3750,224,4,224,1002,223,8,223,1001,224,3,224,1,223,224,223,102,79,213,224,1001,224,-2844,224,4,224,102,8,223,223,1001,224,4,224,1,223,224,223,1,217,69,224,1001,224,-95,224,4,224,102,8,223,223,1001,224,5,224,1,223,224,223,1102,36,37,225,1101,26,16,225,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,1107,677,677,224,102,2,223,223,1006,224,329,1001,223,1,223,1108,677,677,224,1002,223,2,223,1006,224,344,1001,223,1,223,107,226,226,224,1002,223,2,223,1006,224,359,101,1,223,223,1008,226,226,224,102,2,223,223,1005,224,374,1001,223,1,223,1107,226,677,224,1002,223,2,223,1006,224,389,1001,223,1,223,1008,677,226,224,1002,223,2,223,1005,224,404,1001,223,1,223,7,677,226,224,102,2,223,223,1005,224,419,1001,223,1,223,1008,677,677,224,1002,223,2,223,1006,224,434,1001,223,1,223,108,226,226,224,102,2,223,223,1006,224,449,1001,223,1,223,108,677,677,224,102,2,223,223,1006,224,464,1001,223,1,223,107,226,677,224,1002,223,2,223,1005,224,479,101,1,223,223,1108,226,677,224,1002,223,2,223,1006,224,494,1001,223,1,223,107,677,677,224,1002,223,2,223,1006,224,509,101,1,223,223,7,677,677,224,102,2,223,223,1006,224,524,1001,223,1,223,1007,226,677,224,1002,223,2,223,1005,224,539,1001,223,1,223,8,226,677,224,1002,223,2,223,1005,224,554,101,1,223,223,8,677,677,224,102,2,223,223,1005,224,569,101,1,223,223,7,226,677,224,102,2,223,223,1006,224,584,1001,223,1,223,1007,226,226,224,102,2,223,223,1006,224,599,1001,223,1,223,1107,677,226,224,1002,223,2,223,1006,224,614,1001,223,1,223,1108,677,226,224,1002,223,2,223,1005,224,629,1001,223,1,223,1007,677,677,224,102,2,223,223,1006,224,644,1001,223,1,223,108,226,677,224,102,2,223,223,1005,224,659,101,1,223,223,8,677,226,224,1002,223,2,223,1006,224,674,1001,223,1,223,4,223,99,226
	};

	std::vector<int> test1{
		3,0,4,0,99
	};

	std::vector<int> test2{
		1002,4,3,4,33
	};

	std::cout << "aoc 2019 day05.1" << std::endl;
	
	// test 1
	std::cout << "test1: 3,0,4,0,99" << std::endl;
	int result = runProgram(81, test1);
	assert(result == 81);
	
	// test 2
	std::cout << "test2: 1002,4,3,4,33" << std::endl;
	result = runProgram(11, test2);
	assert(result == 0);


	std::cout << "Test1: " << result  << std::endl;

	return 0;
}
