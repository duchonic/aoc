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
	std::vector<std::string> data = readFile("W:/work/hack/aoc/2021/day16/test.txt");

	if (data.size() == 0) {
		return 1;
	}

	for (std::string line : data) {

	}

	int part1 = 0;
	int part2 = 0;

	std::cout << "part1 : " << part1 << std::endl;
	return 0;
}
