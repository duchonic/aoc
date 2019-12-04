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

	int workingNr=0;
	// 767346
	for(int nr=231832; nr<234001;nr++){
		std::string strNr{std::to_string(nr)};

		int lastNr = 0;
		bool equal = false;
		INFO_LOG(nr);
		std::array<int,10> count{0,0,0,0,0,0,0,0,0,0};

		for (auto ch: strNr){
			if( int(ch) >= lastNr){
				INFO_LOG(ch);
				if( int(ch) == lastNr){
					INFO_LOG(lastNr);
					//count.at(int(ch))++;
					equal = true;
				}
				lastNr = int(ch);
			}
			else{
				lastNr = -1;
				break;
			}
		}
		if(equal && (lastNr != -1)){
			INFO_LOG(nr);
			workingNr++;
		}
	}
	return workingNr;
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
