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


int main() {
	std::vector<std::string> data = readFile("W:/work/hack/aoc/2021/day15/test.txt");

	//std::bitset<1500> packet;

	if (data.size() == 0) {
		return 1;
	}

	for (std::string line : data) {
		std::bitset<100> packet(0);
		for (char ch : line) {
			int number{ ch };
			if (number >= 'A' && number <= 'F') {
				number -= 'A';
				number += 10;
			}
			else if (number >= '0' && number <= '9') {
				number -= '0';
			}
			else {
				break;
			}
			std::bitset<4> bits(number);
			//packet += bits;
			for (auto bit : range(0,4))
				bits.test(bit) ? packet.set(bit) : packet.reset(bit);
			packet <<= 4;
			std::cout << ch << ":" << number << ' ' << bits << std::endl;
		}
		std::cout << packet << std::endl;
	}

	int part1 = 0;
	int part2 = 0;

	std::cout << "part1 : " << part1 << std::endl;
	return 0;
}
