/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
*/

#include <iostream>
#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"

#include <string>

#include <vector>

static std::vector<std::string> data;

static void readstuff() {
	std::string a;
	while ( std::getline(std::cin, a)) {
		data.push_back(a);
	}
}

static bool check(std::string test) {
	for (int16_t index = 3; index < test.size(); index++) {

		if (test.at(index) == test.at(index-3) &&
			test.at(index-1) == test.at(index-2) &&
			test.at(index) != test.at(index-1)) {
				std::cout << "test: " << test << std::endl;
				return true;
		}
	}
	return false;
}

int main() {
	readstuff();

	int16_t tls = 0;
	int16_t linenumber = 0;
	for (auto line: data) {

		std::string testString{""};
		bool foundInside = false;
		bool foundOutside = false;
		//std::cout << line << std::endl;
		//std::cout << std::endl << "outside ";
		for (auto ch : line) {
			if (ch == '[') {
				foundOutside |= check(testString);
				testString.clear();
				//std::cout << std::endl << "inside ";
			}
			else if (ch == ']') {
				foundInside |= check(testString);	
				testString.clear();
				//std::cout << std::endl << "outside ";
			}
			else {
				testString.push_back(ch);
				//std::cout << ch;
			}
		}

		linenumber++;

		std::cout << line << std::endl;
		if (foundOutside && !foundInside) {
			tls++;
			std::cout << "line: " << linenumber << " TLS  found : " << tls << std::endl;
		}

	}
	
	std::cout << "TLS found : " << tls << std::endl;

	return 1;
}
