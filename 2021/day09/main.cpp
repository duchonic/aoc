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
#include "help/string.h"

int main() {

	std::vector<std::string> data = readFile("W:/work/hack/aoc/2021/day09/data.txt");

	int part1 = 0;
	int part2 = 0;

	for (std::string line : data) {
		logger(line);
	}

	int x_size = data.at(0).size();
	int y_size = data.size()-1;

	logger("x:" << x_size << " y:" << y_size);

	std::vector<std::vector<int>> cave;

	for (int height = 0; height < y_size+2; height++) {
		std::vector<int> dummy;
		cave.push_back(dummy);
		for (int width = 0; width < x_size + 2; width++) {
			try {
				cave.at(height).push_back( int(data.at(height-1).at(width-1))-0x30 );
			}
			catch (const std::exception&) {
				cave.at(height).push_back(9);
			}
		}
	}

	for (auto y : cave) {
		for (auto x : y) {
			std::cout << x;
		}
		std::cout << std::endl;
	}

	for (int y = 1; y < y_size+1; y++) {
		for (int x = 1; x < x_size+1; x++) {
			logger("check x" << x << " y" << y);

			if (	cave.at(y).at(x) < cave.at(y - 1).at(x) && 
					cave.at(y).at(x) < cave.at(y + 1).at(x) &&
					cave.at(y).at(x) < cave.at(y).at(x +1) &&
					cave.at(y).at(x) < cave.at(y).at(x-1))
			{
				logger("found one :" << cave.at(y).at(x));
				part1 += cave.at(y).at(x) + 1;
			}


		}


	}



	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 0;
}
