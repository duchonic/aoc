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
	//std::multimap< std::pair<double,double>, std::pair<int,int> > masterList; 
	std::multimap< double, double> masterList;
	std::vector< std::pair<double,double> > angleLength;
	
	//for ( auto source : asteroids){
	// part 2

	auto source = std::make_pair(8,16);	

	angles.clear();
	for ( auto destination: asteroids){

		if(source != destination){
			double angle = std::atan2(source.first - destination.first, source.second - destination.second);
			//int distancex = (destination.first - source.first) * (destination.first - source.first);
			//int distancey = (destination.second - source.second) * (destination.second - source.second);
			
			float diffY = source.second - destination.second;
			float diffX = source.first - destination.first;
			double distance = sqrt((diffY * diffY) + (diffX * diffX));
			//double distance = sqrt(distancex - distancey); 
			//masterList[angle] = distance;
			masterList.insert( std::make_pair(angle, distance) );
			//angleLength.push_back( std::make_pair(angle, distance)  );
			angles.insert(angle);
			//INFO_LOG( std::atan2(source.first - destination.first, source.second - destination.second) );
		}

	}
	if (angles.size() > max){
		INFO_LOG("actual is: " << source.first << ":" << source.second);
		INFO_LOG("angles.size(): " << angles.size());
		max = angles.size();
	}

	for (auto x : masterList){

		DEBUG_LOG("angle:" << x.first << " len:" << x.second);
	}
	//}

	return max;
}

/**
* @brief the mainloop
* 
*/
int main(){
	INFO_LOG("aoc 2019 day 10");
	//int result = runProgram("../test.txt");
	//assert ( result == 210);
	int result = runProgram( "../data.txt");
	INFO_LOG("part1: " << result);
	return 0;
}
