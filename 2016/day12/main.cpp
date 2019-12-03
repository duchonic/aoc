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
	std::string reg;
	std::string value;
	
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		if(info.command == "cpy"){
			is >> info.value;
			is >> info.reg;
		}
		else if(info.command == "inc" || info.command == "dec"){
			is >> info.reg;
		}
		else if(info.command == "jnz"){
			is >> info.reg;
			is >> info.value;
		}
		else{
			INFO_LOG("something is wrong");
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
	
	std::map<std::string, int> regComp{};
	
	auto file = std::ifstream(fileName);
	assert(file.is_open());

	for (inputType data; file >> data;) {
		v.push_back(data);
		INFO_LOG("cmd:" << data.command << " reg:" << data.reg << " value:" << data.value);
	}
	
	regComp["a"] = 0;
	regComp["b"] = 0;
	regComp["c"] = 1;
	regComp["d"] = 0;
	
	int position = 0;
	
	INFO_LOG( "max pos = " << v.size() );
	while(position < v.size()) {
		auto data = v.at(position);
		
		INFO_LOG("cmd:" << data.command << " reg:" << data.reg << " value:" << data.value);
		
		if(data.command == "cpy"){
			if (data.value == "a" ||
					data.value == "b" ||
					data.value == "c" ||
					data.value == "d"){
				regComp[data.reg] = regComp[data.value];
			}
			else{
				regComp[data.reg] = std::stoi(data.value) ;
			}
			
			position++;
		}
		else if( data.command == "inc"){
			regComp[data.reg] += 1;
			position++;
		}
		else if(data.command == "dec"){
			regComp[data.reg] -= 1;
			position++;
		}
		else if(data.command == "jnz"){
			
			if( (data.reg == "1") || (regComp[data.reg] != 0)) {
				INFO_LOG("jump from " << position << " to: " << position + std::stoi(data.value) );
				position += std::stoi(data.value);
			}
			else{
				position++;
			}
		}
		else{
			assert(0);
		}
	}
	for (auto data: regComp){
		INFO_LOG( data.first << ":" << data.second);
	}
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("2016/12");
	//runProgram("../test.txt");
	runProgram("../data.txt");
	return 0;
}
