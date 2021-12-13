#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"
#include <cstdlib>
#include <map>

static std::vector<std::pair<int,int>> map;

void foldX(int x) {
	logger("fold x:" << x);
	for (auto &position : map) {
		if (position.first > x) {
			position.first = x - ( position.first - x);	
		}		
	}
}
void foldY(int y) {
	logger("fold y:" << y);
	for (auto &position : map) {
		if (position.second > y) {
			position.second = y - ( position.second - y);	
		}		
	}
}

void show() {
	for (int y=0; y<100; y++) {
		for (int x=0; x<100; x++) {
			if ( std::find(map.begin(), map.end(), std::make_pair(x,y)) != map.end() ) {
				std::cout << 'X';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	for (auto pos : map) {
		std::cout << pos.first << '/' << pos.second << ' ';
	}
	std::cout << std::endl;
}

int main() {
	std::vector<std::string> data = readstuff();
	
	std::vector< std::pair<char, int>> folds;

	for (int entry = 12; entry > 0; entry--) {
		std::string dummyString;
		char direction;
		char dummyChar;
		int pos;
		std::stringstream line(data.at( data.size() - entry));
		line >> dummyString ; 
		line >> dummyString ; 
		line >> direction ; 
		line >> dummyChar ;
		line >> pos ;
		folds.push_back(std::make_pair(direction, pos));
	}

	for ( auto line : range(0, (int)data.size()-13)) {
		//logger(data.at(line));
		char dummyChar;
		std::stringstream text(data.at(line));
		std::pair<int, int> position{1,2};
		text >> position.first;
		text >> dummyChar;	
		text >> position.second;
		map.push_back(position);
	}

	for ( auto fold : folds ) {
		show();
		if (fold.first == 'y') {
			foldY(fold.second);	
		}
		else {
			foldX(fold.second);
		}
	}	
	show();

	std::set<std::pair<int, int>> result;
	for (auto pos : map) {
		result.insert(pos);
	}
	int part1 = result.size();
	std::cout << "part1 : " << part1 << std::endl;

	return 0;
}
