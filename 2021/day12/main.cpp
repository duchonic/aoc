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

int main() {
	std::vector<std::string> data = readstuff();

	for (auto line : data) {
		logger(line);		
	}
	int part1 = 0x81;
	
	std::cout << "part1 : " << part1 << std::endl;

	return 0;
}
