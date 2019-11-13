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
	
	std::multimap<double, char> order;
	std::map<char, double> adder;

	double x = 0.9;
	for (char c='a'; c<='z'; c++){
	  	adder[c] = x;
		x-= 0.01; 
	}

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	for (inputType data; file >> data;) {
		v.push_back(data);
	}

	int sum = 0;

	DEBUG_LOG("data from " << fileName);
	for (auto data : v) {

		//INFO_LOG(data.command);
		//INFO_LOG("decoy:" << data.decoy << " nr:" << data.nr << " cksum:" << data.checksum << " line:" << data.line);

		order.clear();
		for( auto item: data.map){
			//DEBUG_LOG("INSERT:" << item.first << " " << item.second);
			
			order.insert( std::make_pair(item.second + adder[item.first] , item.first ) );
		
		}
		std::string compare{""};
		auto it = order.end();
		for (int i=0; i<5 ; i++){ 
			it--;
			compare += it->second;
			//INFO_LOG(it->first << " " << it->second);		
		}
        
        //DEBUG_LOG("compare: " << compare << " data.checksum: " << data.checksum);

		if(compare == data.checksum){
		    INFO_LOG(data.raw << data.nr);
			sum += std::stoi(data.nr);
        }

        INFO_LOG(data.raw << data.nr << " modulo: " << std::stoi(data.nr)%26);

        std::string deciphr{""};
        for (auto c: data.raw){
            if(c == '-'){
                deciphr += ' ';
            }
            else{
         
                unsigned char  newC = int(c) + std::stoi(data.nr)%26;

         
                if (newC > int('z') ){
                     newC -= 26;
                }
                
                deciphr += newC;
            }
        }
        INFO_LOG(" " << deciphr << " nr:" << data.nr);
	}
	DEBUG_LOG("THE SUM IS: " << sum);
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
