/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
    */

#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include <cmath>


//std::vector<int> ones{0,0,0,0,0,0,0,0,0,0,0,0};
std::vector<int> ones{0,0,0,0,0};

int main() {
	std::vector<std::string> data = readstuff();

	int16_t part1 = 0;
	int16_t part2 = 0;
	int16_t linenumber = 0;
	for (auto line: data) {
		std::cout << linenumber++ << ' ' << line << std::endl;

		uint8_t index = 0;
		for (char ch : line) {
			if (ch == '1') {
				ones.at(index)++;
			}
			index++;
		}	
	}
	
	std::cout << "part2 : " << part2 << std::endl;

	std::bitset<5> gamma = 0;
	std::bitset<5> epsilon = 0;
	std::bitset<5> equal = 0;
	for (int index = 0; index < ones.size() ; index++) {
		std::cout << ones.at(index) << std::endl;
		if (ones.at(index) > 5) {
			gamma.set(ones.size()-index-1);
		}
		else {
			epsilon.set(ones.size()-index-1);
		}

		if (ones.at(index) == 5) {
			std::cout << "equal" << std::endl;
			equal.set(ones.size()-index-1);
		}	
	}
	std::cout << gamma << " " << gamma.to_ulong() << std::endl;
	std::cout << epsilon << " " << epsilon.to_ulong() << std::endl;
	std::cout << equal << " " << equal.to_ulong() << std::endl;
	std::cout << "part1 : " << gamma.to_ulong() *  epsilon.to_ulong() << std::endl;

	return 1;
}
