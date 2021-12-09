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

	if (data.size() == 0) {
		return 1;
	}

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
			if (	cave.at(y).at(x) < cave.at(y - 1).at(x) && 
					cave.at(y).at(x) < cave.at(y + 1).at(x) &&
					cave.at(y).at(x) < cave.at(y).at(x +1) &&
					cave.at(y).at(x) < cave.at(y).at(x-1))
			{
				part1 += cave.at(y).at(x) + 1;
			}
		}
	}



	for (int y = 0; y < y_size + 2; y++) {
		for (int x = 0; x < x_size + 2; x++) {
			if (cave.at(y).at(x) == 9) {
				cave.at(y).at(x) = 0;
			}
			else {
				cave.at(y).at(x) = 1;
			}
		}
	}

	logger("bassing before:");

	for (auto y : cave) {
		for (auto x : y) {
			std::cout << x;
		}
		std::cout << std::endl;
	}

	// the bassin, saves the bassin # to the position
	std::map< std::pair<int, int>, int> bassin;
	int bassinNumber = 2;

	for (int y = 1; y < y_size + 1; y++) {
		for (int x = 1; x < x_size + 1; x++) {
			if (cave.at(y).at(x) == 1) {

				bassinNumber++;
				//logger("new bassin with nr: " << bassinNumber << " x: " << x << " y: " << y);
				bassin[std::make_pair(x, y)] = bassinNumber;
				cave.at(y).at(x) = bassinNumber;

				//fill current bassin
				std::vector< std::pair<int, int>> unknownList{};
				if (cave.at(y).at(x + 1) == 1) {
					// check east, fill to bassin nr if unknown(1)
					cave.at(y).at(x+1) = bassinNumber;
					unknownList.push_back(std::make_pair(x + 1, y));
				}
				if (cave.at(y +1).at(x) == 1) {
					// check south, fill to bassin nr if unknown(1)
					cave.at(y+1).at(x) = bassinNumber;
					unknownList.push_back(std::make_pair(x, y+1));
				}

				while (unknownList.size() > 0) {
					std::pair<int, int> check = unknownList.back();
					unknownList.pop_back();

					if (cave.at(check.second).at(check.first + 1) == 1) {
						cave.at(check.second).at(check.first + 1) = bassinNumber;
						unknownList.push_back(std::make_pair(check.first +1, check.second));
					}
					if (cave.at(check.second).at(check.first - 1) == 1) {
						cave.at(check.second).at(check.first - 1) = bassinNumber;
						unknownList.push_back(std::make_pair(check.first - 1, check.second));
					}
					if (cave.at(check.second + 1).at(check.first) == 1) {
						cave.at(check.second + 1).at(check.first) = bassinNumber;
						unknownList.push_back(std::make_pair(check.first, check.second + 1));
					}
					if (cave.at(check.second - 1).at(check.first) == 1) {
						cave.at(check.second - 1).at(check.first) = bassinNumber;
						unknownList.push_back(std::make_pair(check.first, check.second - 1));
					}

				}
			}
		}
	}
	logger("bassing after 1:");

	std::array<int, 250> sizes;

	for (auto &entry : sizes) {
		entry = 0;
	}

	for (auto y : cave) {
		for (auto x : y) {
			if (x > 0) {
				sizes.at(x)++;
				std::cout << std::setw(4) << x;
			}
			else {
				std::cout << "    ";
			}
		}
		std::cout << std::endl;
	}
	std::sort(sizes.begin(), sizes.end());

	for (auto cnt : sizes) {
		logger(std::to_string( cnt ) );
	}




	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << sizes.at(249) * sizes.at(248) * sizes.at(247) << std::endl;


	return 0;
}
