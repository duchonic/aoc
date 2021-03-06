#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <map>
#include <array>
#include "log.h"

/**
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
* @return manhatten distance to nearest point
*/
int runProgram() {
	int workingNrPart1=0;
	int workingNrPart2=0;
	for(int nr= 231832; nr < 767346;nr++){
		std::string strNr{std::to_string(nr)};
		int lastNr = -1;
		bool equal = false;
		std::array<int,10> counts{1,1,1,1,1,1,1,1,1,1};
		for (auto ch: strNr){
			if( (int(ch)-0x30) >= lastNr){
				if( (int(ch)-0x30) == lastNr){
					counts.at(lastNr)++;
					equal = true;
				}
				lastNr = int(ch)-0x30;
			}
			else{
				lastNr = -1;
				break;
			}
		}
		if(equal && (lastNr != -1)){
			bool checkPart2 = false;
			for (auto count : counts) {
				if (count == 2) {
					workingNrPart2++;
					break;
				}
			}
            workingNrPart1++;
		}
	}
	INFO_LOG("part2 check true: " << workingNrPart2);
	return workingNrPart1;
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 04");
	int result = runProgram();
	INFO_LOG("part1: " << result);
	return 0;
}
