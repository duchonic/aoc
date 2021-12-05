/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
    */

#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include <functional>
#include <numeric>
#include <iomanip>
#include <map>


int main() {
	auto data = readLines();
    std::map<std::pair<int,int>, int> map {};
	for ( auto line : data) {
		std::pair<int,int> start{0,0};
		std::pair<int,int> end{0,0};

		bool diagonal = false;
		if (line.first.first == line.second.first ) {
			if (line.first.second < line.second.second) {
				start = std::make_pair(line.first.first, line.first.second);
				end = std::make_pair(line.second.first, line.second.second);
			}
			else {
				start = std::make_pair(line.first.first, line.second.second);
				end = std::make_pair(line.second.first, line.first.second);
			}
		}
		else if (line.first.second == line.second.second) {
			if (line.first.first < line.second.first) {
				start = std::make_pair(line.first.first, line.first.second);
				end = std::make_pair(line.second.first, line.second.second);
			}
			else {
				start = std::make_pair(line.second.first, line.first.second);
				end = std::make_pair(line.first.first, line.second.second);
			}
		}
		else {
			if (line.first.first < line.second.first) {
				start = line.first;
				end = line.second;
			}
			else {
				start = line.second;
				end = line.first;
			}
			diagonal = true;
		}

		if (!diagonal) {
			for ( int y = start.second ; y <= end.second; y++) {
				for (int x = start.first; x <= end.first; x++) {
					std::pair<int,int> check{x,y};
					if(map.contains(check)) {
						map[check] += 1;
					} else {
						map[check] = 1;
					}
				}
			}
		}
		else {
			int y = start.second;
			bool goesdown = true;
			if ( start.second > end.second ) {
				goesdown = false;
			}
			for (int x = start.first; x <= end.first; x++) {
				std::pair<int,int> check{x,y};

				if (goesdown) {
					y++;
				}
				else {
					y--;
				}
				if(map.contains(check)) {
					map[check] += 1;
				} else {
					map[check] = 1;
				}
			}
		}
		
		

	}

	int part1 = 0;
	for (auto pixel : map) {
		if (pixel.second > 1) {
			part1++;
			logger(pixel.first.first << ' ' << pixel.first.second << " count:" << pixel.second);
		}
	}
	logger("part1:" << part1);

	for (int y=0; y<=100; y++) {
		for (int x=0; x<=100; x++) {
			if (map.contains(std::make_pair(x,y))) {
				std::cout << map[std::make_pair(x,y)];
			}
			else{
				std::cout << '.';
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
