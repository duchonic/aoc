#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

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
	bool startChecksum = false;

	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		info.line++;
		info.nr = "";
		info.checksum = "";
		info.decoy = "";
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
				if (c != '-') {
					info.decoy += c;
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

	DEBUG_LOG("data from " << fileName);
	for (auto data : v) {
		INFO_LOG(data.command);
		INFO_LOG("decoy" << data.decoy << " nr:" << data.nr << " cksum:" << data.checksum << " line:" << data.line);
	}
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("2016/4");
	runProgram("../test.txt");
	runProgram("../data.txt");

	return 0;
}
