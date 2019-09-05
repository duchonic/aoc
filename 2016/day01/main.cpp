#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <cmath>

// read file
struct inputType{
	std::string command;
	friend std::istream& operator>>(std::istream& is, inputType& info){
		is >> info.command;
		return is;
	}
};

// point x,y
typedef std::pair<int, int> Point;

// directions for moving
enum DIRECTION{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
};

struct Coord{
	int x;
	int y;
	int direction;
	int distance(void){
		return abs(x)+abs(y);
	}
};

int main(){

	// R -> clockwise += 1
	// L -> CClockwise -= 1
	Coord myCordinate{0,0, NORTH};
	std::set<Point> visitedCordinate;
	std::vector<inputType> v;

	std::cout << "aoc 2016 day01" << std::endl;
	
	auto file = std::ifstream("../data.txt");
	assert(file.is_open());
	
	for(inputType info; file >> info;){
		v.push_back(info);
	}

	for(auto info: v){
		if (info.command.at(0) == 'L'){
			info.command.erase(0,1);
			myCordinate.direction -= 1;
			if(myCordinate.direction<0) {
				myCordinate.direction = 3;
			}
		}
		else if(info.command.at(0) == 'R'){
			info.command.erase(0,1);
			myCordinate.direction += 1;
			myCordinate.direction %= 4;
		}
		else{
			assert(0);
		}
		
		Point oldPoint{myCordinate.x, myCordinate.y};

		if(myCordinate.direction == EAST){
			myCordinate.x += stoi(info.command);

			for(int x = oldPoint.first; x < myCordinate.x; x++){

				if(visitedCordinate.count({x, oldPoint.second}) == 1){
					std::cout << "visited twice! distance (part2): " << abs(x)+abs(oldPoint.second) << std::endl;
					break;
				}
				visitedCordinate.insert({x, oldPoint.second});
			}

		}
		else if(myCordinate.direction == WEST){
			myCordinate.x -= stoi(info.command);
			for(int x = oldPoint.first; x > myCordinate.x; x--){

				if(visitedCordinate.count({x, oldPoint.second}) == 1){
					std::cout << "visited twice! distance (part2): " << abs(x)+abs(oldPoint.second) << std::endl;
					break;
				}
				visitedCordinate.insert({x, oldPoint.second});
			}
		}
		else if(myCordinate.direction == NORTH){
			myCordinate.y += stoi(info.command);
			for(int y = oldPoint.second; y < myCordinate.y; y++){

				if(visitedCordinate.count({oldPoint.first, y}) == 1){
					std::cout << "visited twice! distance (part2): " << abs(oldPoint.first)+abs(y) << std::endl;
					break;
				}
				visitedCordinate.insert({oldPoint.first, y});
			}
		}
		else if(myCordinate.direction == SOUTH){
			myCordinate.y -= stoi(info.command);
			for(int y = oldPoint.second; y > myCordinate.y; y--){

				if(visitedCordinate.count({oldPoint.first, y}) == 1){
					std::cout << "visited twice! distance (part2): " << abs(oldPoint.first)+abs(y) << std::endl;
					break;
				}
				visitedCordinate.insert({oldPoint.first, y});
			}
		}
		else{
			assert(0);
		}
	}
	std::cout << "total distance (part 1):" << myCordinate.distance() << std::endl;
	return 0;
}
