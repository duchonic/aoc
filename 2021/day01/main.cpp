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
#include "help/log.h"

int main() {
	std::vector<std::string> data = readstuff();

	int16_t part1 = 0;
	int16_t part2 = 0;
	int16_t linenumber = 0;
	int16_t oldnr = 10000;

	log("part1");	
	for (std::string line : data) {
		int16_t actualNr = stoi(line);
		if (actualNr > oldnr) {
			part1++;
		}	
		oldnr = actualNr;
	}

	log("part2");
	oldnr = 10000;
	linenumber = 0;
	for (std::string line : data) {
		log("test");
		try{
			int16_t actualNr = stoi(data.at(linenumber)) + stoi(data.at(linenumber+1)) + stoi(data.at(linenumber+2));
			if (actualNr > oldnr) {
				part2++;
			}	
			oldnr = actualNr;
		}
		catch(const std::out_of_range& e) {
			break;
		}
		linenumber++;
	}
	
	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 1;
}
