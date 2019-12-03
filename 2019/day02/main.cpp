#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

int main(){
	std::vector<int> input{
	 	1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,6,19,23,1,23,13,27,2,6,27,31,1,5,31,35,2,10,35,39,1,6,39,43,1,13,43,47,2,47,6,51,1,51,5,55,1,55,6,59,2,59,10,63,1,63,6,67,2,67,10,71,1,71,9,75,2,75,10,79,1,79,5,83,2,10,83,87,1,87,6,91,2,9,91,95,1,95,5,99,1,5,99,103,1,103,10,107,1,9,107,111,1,6,111,115,1,115,5,119,1,10,119,123,2,6,123,127,2,127,6,131,1,131,2,135,1,10,135,0,99,2,0,14,0
	};
	std::cout << "aoc 2019 day02" << std::endl;
	
	int programmCounter = 0;
	for ( int i=0 ; i<input.size(); i+=4){
		if(input.at(i) == 1){
			programmCounter+=4;
			input.at( input.at(i+3) ) = input.at( input.at(i+1) ) + input.at( input.at(i+2) );
		}
		else if(input.at(i) == 2){
			programmCounter+=4;
			input.at( input.at(i+3) ) = input.at( input.at(i+1) ) * input.at( input.at(i+2) );
		}
		else if(input.at(i) == 99){
			break;
		}
	}
	std::cout << "Part1: "  << input.at(0) << std::endl;

	/** output for part2 */
	int output = 19690720;	
	/** to break the outer loop */
	bool foundValue = false;

	for (int noun=0; noun<99; noun++){ /* outerloop, exit with flag from inner loop */
		for (int verb=0; verb<99; verb++){ /* innerloop, exit with break, set flag */
			std::vector<int> input{
				1,noun,verb,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,6,19,23,1,23,13,27,2,6,27,31,1,5,31,35,2,10,35,39,1,6,39,43,1,13,43,47,2,47,6,51,1,51,5,55,1,55,6,59,2,59,10,63,1,63,6,67,2,67,10,71,1,71,9,75,2,75,10,79,1,79,5,83,2,10,83,87,1,87,6,91,2,9,91,95,1,95,5,99,1,5,99,103,1,103,10,107,1,9,107,111,1,6,111,115,1,115,5,119,1,10,119,123,2,6,123,127,2,127,6,131,1,131,2,135,1,10,135,0,99,2,0,14,0
			};
			
			int programmCounter = 0;
			for ( int i=0 ; i<input.size(); i+=4){
				if(input.at(i) == 1){
					programmCounter+=4;
					input.at( input.at(i+3) ) = input.at( input.at(i+1) ) + input.at( input.at(i+2) );
				}
				else if(input.at(i) == 2){
					programmCounter+=4;
					input.at( input.at(i+3) ) = input.at( input.at(i+1) ) * input.at( input.at(i+2) );
				}
				else if(input.at(i) == 99){
					break;
				}
			}

			if (input.at(0) == output){
				std::cout << "Part2: " << noun * 100 + verb << std::endl;
				foundValue = true;
				break;
			}
			if(foundValue){
				break;
			}
		}
	}
	return 0;
}
