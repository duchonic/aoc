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

int main() {
	std::vector<std::string> data = readstuff();

	int16_t tls = 0;
	int16_t ssl = 0;
	int16_t linenumber = 0;
	for (auto line: data) {
		std::cout << line << std::endl;
		std::string testString{""};
		bool foundInside = false;
		bool foundOutside = false;

		std::string outside{""};
		std::string inside{""};

		for (auto ch : line) {
			if (ch == '[') {
				foundOutside |= checkString(testString);
				outside.append(testString);
				outside.append(" ");
				testString.clear();
			}
			else if (ch == ']') {
				foundInside |= checkString(testString);	
				inside.append(testString);
				inside.append(" ");
				testString.clear();
			}
			else {
				testString.push_back(ch);
			}
		}
		foundOutside |= checkString(testString);	
		outside.append(testString);

		bool found = false;
		for (std::string out : checkStringToSet(outside)) {
			std::cout << out << " check inside: ";
			for (std::string in : checkStringToSet(inside)) {
				std::cout << in << " ";
				if (out.at(0) == in.at(1) && out.at(1) == in.at(0)) {
					std::cout << "<= match  "; 
					found = true;
				}
			}
			
			std::cout << std::endl;
		}
		if (found) {
			ssl++;
		} 
			
		outside.clear();
		inside.clear();

		linenumber++;

		if (foundOutside && !foundInside) {
			tls++;
			std::cout << "line: " << linenumber << " TLS  found : " << tls << std::endl;
		}
		else {
			std::cout << "line: " << linenumber << std::endl;
		}
	}
	
	std::cout << "TLS found : " << tls << std::endl;
	std::cout << "ssl found : " << ssl << std::endl;

	return 1;
}
