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
#include "help/display.h"

std::vector<std::pair<int,int>> pixel;
std::string output{""};

int main() {
	std::vector<std::string> data = readstuff();
	
	int16_t part1 = 0;
	int16_t part2 = 0;
	int16_t linenumber = 1;
    
    std::replace(data.at(0).begin(), data.at(0).end(), '(', ' ');  
    std::replace(data.at(0).begin(), data.at(0).end(), ')', ' ');  
    

	for (auto line: data) {
		log( linenumber++ << ": " << line );
        std::string read; 
        std::stringstream s(line);
        while (s >> read) {
            log(read);
        }
	}
    part1 = output.size();
	
	log("part1 => " << part1);
	log("part2 => " << part2);

	return 1;
}
