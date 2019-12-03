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
	unsigned int botNr;
	std::pair<int, int> valueToBot;
	std::pair<std::string, int> lowOut;
	std::pair<std::string, int> highOut;
	
	std::map<char, int> map;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		
		if (info.command == ""){
			
		}
		else if (info.command == "bot"){
			is >> info.botNr;
			
			std::string dummy;
			is >> dummy;
			is >> dummy;
			//assert(dummy == "low");
			is >> dummy;
			
			std::string lowString;
			is >> lowString;
			
			int lowNr;
			is >> lowNr;
			
			if ( lowString != "bot") {
				lowNr += 1000;
			}
			
			is >> dummy;
			is >> dummy;
			//assert(dummy == "high");
			is >> dummy;
			
			std::string highString;
			is >> highString;
			
			
			int highNr;
			is >> highNr;
			
			if ( highString != "bot"){
				highNr += 1000;
			}
			
			info.lowOut = std::make_pair(lowString, lowNr);
			info.highOut = std::make_pair(highString, highNr);
			
			info.valueToBot = std::make_pair(-1, -1);
		}
		else if (info.command == "value"){
			int value;
			is >> value;
			
			std::string dummy;
			is >> dummy;
			is >> dummy;
			is >> dummy;
			
			int bot;
			is >> bot;
			info.valueToBot = std::make_pair(bot, value);
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
	
	int line = 0;
	for (inputType data; file >> data;) {
		//INFO_LOG("line:" << line++);
		v.push_back(data);
	}
	
	std::map<int, std::pair<int,int> > botConnection;
	
	for (auto data: v){
		botConnection[data.botNr] = std::make_pair(data.lowOut.second, data.highOut.second);
		
		if(data.valueToBot.first == -1){
			INFO_LOG("connection bot:" << data.botNr << " high => "
							 << data.highOut.first << ":" << data.highOut.second);
			INFO_LOG("connection bot:" << data.botNr << " low  => "
							 << data.lowOut.first << ":" << data.lowOut.second);
		}
	}

	std::map<int, std::vector<int> > botVal;
	
	for (auto data: v){
		if(data.valueToBot.first != -1){
			botVal[data.valueToBot.first].push_back(data.valueToBot.second);
			INFO_LOG("value to bot: " << data.valueToBot.first << " <-> " << data.valueToBot.second);
		}
	}
	
	std::map<int, int> processed;
	
	for ( int runs=1000; runs>0 ; runs-- ){
		int min, max, botNrMin, botNrMax;
		for (auto item: botVal){
			if (item.second.size() == 2){
				
				if(item.second.at(0) > item.second.at(1)){
					max = item.second.at(0);
					min = item.second.at(1);
				}
				else{
					max = item.second.at(1);
					min = item.second.at(0);
				}
				

				
				if( processed[item.first] != 1 ){

					//INFO_LOG("botVal:" << item.first << " min:" << min << " max:" << max);
					botNrMin = botConnection[item.first].first;
					botNrMax = botConnection[item.first].second;
					
					processed[item.first] = 1;
					break;
				}
			}
		}
		
		//INFO_LOG("push (min) " << min << " to botNr " << botNrMin);
		//INFO_LOG("push (max) " << max << " to botNr " << botNrMax);
		
		if(botVal[botNrMin].size() != 2){
			botVal[botNrMin].push_back(min);
		}
		
		if( botVal[botNrMax].size() != 2 ){
			botVal[botNrMax].push_back(max);
		}
		
		//INFO_LOG("");
		for (auto item: botVal){
			if(item.second.size() == 2){
				//INFO_LOG(item.first << " " << item.second.at(0) << " " << item.second.at(1) );
				
				//if ( (item.second.at(0) == 17) && (item.second.at(1) == 61) ){
				//	INFO_LOG(item.first << " " << item.second.at(0) << " " << item.second.at(1) );
				//	break;
				//}
				
				//if ( (item.second.at(0) == 61) && (item.second.at(1) == 17) ){
				//	INFO_LOG(item.first << " " << item.second.at(0) << " " << item.second.at(1) );
				//	break;
				//}
			}
			else{
				//INFO_LOG(item.first << " " << item.second.at(0) );
			}
		}
		//INFO_LOG("");
	}
	
	//INFO_LOG("");
	for (auto item: botVal){
		if(item.second.size() == 2){
			//INFO_LOG(item.first << " " << item.second.at(0) << " " << item.second.at(1) );
			
			//if ( (item.second.at(0) == 17) && (item.second.at(1) == 61) ){
			//	INFO_LOG(item.first << " " << item.second.at(0) << " " << item.second.at(1) );
			//	break;
			//}
			
			//if ( (item.second.at(0) == 61) && (item.second.at(1) == 17) ){
			//	INFO_LOG(item.first << " " << item.second.at(0) << " " << item.second.at(1) );
			//	break;
			//}
		}
		else{
			INFO_LOG(item.first << " " << item.second.at(0) );
		}
	}
}

/**
 * @brief the mainloop
 *
 */
int main(){
	INFO_LOG("2016/10");
	//runProgram("../test.txt");
	runProgram("../data.txt");
	return 0;
}
