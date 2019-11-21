#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>
#include <map>
#include <deque>
#include <algorithm>

#include "log.h"
#include "json.h"

/**
* @brief process data in file with this struct
*
*/
struct inputType{
	std::string command;
	unsigned int line = 0;
	std::string nr = "";
	std::string checksum = "";
	std::string decoy = "";
	std::string raw = "";
	bool startChecksum = false;
	
	std::map<char, int> map;

	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		info.line++;
		info.nr = "";
		info.checksum = "";
		info.decoy = "";
		info.raw = "";
		info.map.clear();

		for (char c : info.command) {
			if (isdigit(c)) {
				info.nr += c;
			}
			else if (c == '[') {
				info.startChecksum = true;
			}
			else if (c == ']') {
				info.startChecksum = false;
			}
			else if (info.startChecksum) {
				info.checksum += c;
			}
			else {
				info.raw += c;
				if (c != '-') {
					info.decoy += c;
					
					if( info.map.count(c) == 0){
						info.map[c] = 1;
					}
					else{
						info.map.at(c)++;
					}
				}
			}
		}
		return is;
	}
};

/**
 * @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
*
*/
void runProgram(std::string fileName) {
	std::vector<inputType> v;

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	for (inputType data; file >> data;) {
		v.push_back(data);
	}
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("2016/6");
	runProgram("../test.txt");
	runProgram("../data.txt");
	return 0;
}
