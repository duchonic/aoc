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
#include <cmath>
#include <chrono>
#include <thread>

#define PI 3.14159265

/**
* @brief process data in file with this struct
*
*/
struct inputType
{
	std::string line;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.line;
		return is;
	}
};

void printMap(std::multimap< int, std::pair<double, std::pair<int,int>> > masterList){
	std::vector< std::string > map;
	for(int row=0; row<5; row++){
		map.push_back( std::string(18,'.') );
	}

	for(auto asteroid: masterList){
		map.at(asteroid.second.second.second).at(asteroid.second.second.first) = 'x';
	}
	map.at(3).at(8) = '#';
	int lineNr = 100;
	for(auto line: map){
		INFO_LOG("line:" << lineNr++ << " " << line);
	}
}

using namespace std::chrono_literals;

/**
* @brief program that process some data from the file
*        mostly called twice with test.txt and data.txt
* @return manhatten distance to nearest point
*/
int runProgram(std::string fileName) {

	auto file = std::ifstream(fileName);
	assert(file.is_open());

	std::vector< std::pair<int,int> > asteroids;

	int x=0; int y=0;
	for (inputType data; file >> data;) {
		x = 0;
		for (auto c : data.line){
			if(c == '#'){
				asteroids.push_back( std::make_pair(x,y) );
			}
			x++;
		}
		y++;
	}
	int max = 0;
	std::set<double> angles;
	std::multimap< int, std::pair<double, std::pair<int,int>> > masterList;

	auto source = std::make_pair(8,3);	

	angles.clear();
	for ( auto destination: asteroids){

		if(source != destination){
			double angle = std::atan2(source.first - destination.first, source.second - destination.second);
			float diffY = source.second - destination.second;
			float diffX = source.first - destination.first;
			double distance = sqrt((diffY * diffY) + (diffX * diffX));

			angle *= -1;
			angle = int(angle * 180 / PI);

			if(angle < 0){
				angle = 360 + angle;
			}

			masterList.insert( std::make_pair( angle , 
				std::make_pair(distance, std::make_pair(destination.first, destination.second) ) ));
			angles.insert(angle);
		}

	}
	if (angles.size() > max){
		INFO_LOG("actual is: " << source.first << ":" << source.second);
		INFO_LOG("angles.size(): " << angles.size());
		max = angles.size();
	}

	int asteroidsErased = 0;
	while(true){
		for(auto it = masterList.begin(); it != masterList.end(); ) {
			
			DEBUG_NDU("element " << it->first << " " << it->second.first << " " << it->second.second.first << " " << it->second.second.second);

			if(std::next(it,1)->first != it->first){
				INFO_LOG("erase " << it->first << " " << it->second.first << " erasedAsteroid " << ++asteroidsErased << " " << it->second.second.first << " " << it->second.second.second);
				it = masterList.erase(it);
				
				//printf("\033c");
				INFO_LOG("current astro map");
				printMap(masterList);
				std::this_thread::sleep_for(2s);
				
			}
			else{
				++it;
			}
			if(asteroidsErased >= 200){
				break;
			}
		}
		if(asteroidsErased >= 200){
			break;
		}
	}
	return max;
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 10");
	int result = runProgram( "../test.txt");
	INFO_LOG("part1: " << result);
	return 0;
}
