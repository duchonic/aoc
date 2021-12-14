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
	std::vector<std::string> data = readstuff();
	std::map<std::string, std::string> lookup;
	std::set<char> testchar;

	std::stringstream ss(data.at(0));
	std::string genesis;
	ss >> genesis;
		
	for ( auto index : range(2, (int)data.size())) {
		std::stringstream code(data.at(index));
		std::string pattern;
		std::string dummy;
		std::string insert;
		code >> pattern >> dummy >> insert;
		lookup[pattern] = insert;
		testchar.insert(insert[0]);
	}

	for (auto item : lookup) {
		logger(item.first << ' ' << item.second);
	}

	uint64_t minimum = 10000;
	uint64_t maximum = 0;
	for (auto steps : range(0,40)) {
		logger(steps);
		int position = 0;
		while (true) {
			try {
				std::string check = genesis.substr(position, 2);
				if (check.size() == 2) {
					//logger("check: " << check);
					auto search = lookup.find(check);
					if (search != lookup.end()) {
						//logger("insert: " << search->second);
						genesis.insert(position+1, search->second);
					}
					position += 2;		
				}
				else {
					break;
				}
			} 
			catch (...) {
				logger("something went wrong");
				break;
			}
		}
	}
	for (auto test : testchar) {
		uint64_t nr = std::count(genesis.begin(), genesis.end(), test);
		if (nr < minimum) {
			minimum = nr;
		}
		if (nr > maximum) {
			maximum = nr;
		}
	}

	std::cout << "part1 : " << maximum - minimum << std::endl;

	return 0;
}
