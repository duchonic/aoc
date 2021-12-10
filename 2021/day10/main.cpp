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

	int part1 = 0;
	std::vector<uint64_t> part2;

	if (data.size() == 0) {
		return 1;
	}
	
	for (auto &line : data) {
		std::size_t removed = 1;
		logger(line);
		while (removed) {
			removed = replace_all(line, "()", "") ;	
			removed += replace_all(line, "{}", "") ;	
			removed += replace_all(line, "[]", "") ;	
			removed += replace_all(line, "<>", "") ;	
		}
		int index = 0;
		logger(line);
		bool incomplete = true;
		for (auto ch : line) {
			if (ch == ')' || ch == '}' || ch == ']' or ch == '>') {
				switch(ch) {
					case ')':
						part1+=3;
						break;
					case ']':
						part1+=57;
						break;
					case '}':
						part1+=1197;
						break;
					case '>':
						part1+=25137;
						break;
					default:
						logger("EEEERRRROOOORR");
						break;
				}
				incomplete = false;
				logger("expected " << line.at(index-1) << " but found " << line.at(index));
				break;
			}
			index++;
		}


		if (incomplete) {
			logger("do part2 with incomplete line: " << line);
			uint64_t sum = 0;
			for (int index = line.size()-1 ; index>=0 ; index--) {
				sum *= 5;
				switch(line.at(index)) {
					case '(':
						sum+=1;
						break;
					case '[':
						sum+=2;
						break;
					case '{':
						sum+=3;
						break;
					case '<':
						sum+=4;
						break;
					default:
						logger("EEEERRRROOOORR");
						break;
				}
			}
			logger("sum : " << sum);
			part2.push_back(sum);
		}
	}

	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << median(part2) << std::endl;

	return 0;
}
