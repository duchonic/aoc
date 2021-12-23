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
	std::vector<std::string> data = readFile("../test.txt");
	
	int part1 = 0;
	int part2 = 0;

	if (data.size() == 0) {
		return 1;
	}


	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;
	return 0;
}
