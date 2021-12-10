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
#include <unistd.h>
#include <cstdlib>
#include <map>



int main() {

	//std::vector<std::string> data = readFile("W:/work/hack/aoc/2021/day09/data.txt");
	//std::vector<std::string> data = readFile("../data.txt");

	std::vector<std::string> data = readstuff();

	if (data.size() == 0) {
		return 1;
	}
	
	for (auto line : data) {
		logger(line);
		std::map<char, int> syntax{
			{'(', 0},
			{'{', 0},
			{'[',0},
			{'<',0},
		};
		for (auto ch : line) {
			if (ch == '(') {
				syntax['(']++;		
			}
			else if (ch == ')') {
				syntax['(']--;
			}
			else if (ch == '{') {
				syntax['{']++;
			}
			else if (ch == '}') {
				syntax['}']--;
			}
			else if (ch == '[') {
				syntax['[']++;
			}
			else if (ch == ']') {
				syntax[']']--;
			}
			else if (ch == '<') {
				syntax['<']++;
			}
			else if (ch == '>') {
				syntax['>']--;
			}
			bool error = false;
			for (auto check : syntax) {
				if (check.second < 0) {
					error = true;
					logger("error");
					logger(check.first << ' ' << check.second); 
					break;
				}
			}
			if (error) {
				break;
			}
		}
	
	}

	int part1 = 0;
	int part2 = 0;

	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 0;
}
