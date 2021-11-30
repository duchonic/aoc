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

const int screenX = 50;
const int screenY = 6; 
//const int screenX = 7;
//const int screenY = 3;

int main() {
	std::vector<std::string> data = readstuff();
	
	int16_t part1 = 0;
	int16_t part2 = 0;
	int16_t linenumber = 1;
	for (auto line: data) {
		log( linenumber++ << ": " << line );
		if (find(line, "rotate")) {
			std::stringstream s(line);
			std::string dummy;
			char dummyChar;
			s >> dummy >> dummy >> dummyChar >> dummyChar;	
			if (find(line, "column")) {
				int x;
				int count;
				s >> x;
				s >> dummy;
				s >> count;
				log("rotate x:" << x << " by:" << count);
				
				for (auto &p: pixel) {
                    if (p.first == x) {
                        p.second += count;
                        p.second %= screenY;
                    }
				}
			}
			else if (find(line, "row")) {
				int y;
				int count;
				s >> y;
				s >> dummy;
				s >> count;
				log("rotate y:" << y << " by:" << count);
                for (auto &p: pixel) {
                    if (p.second == y) {
                        p.first += count;
			            p.first %= screenX;	
                    }
                }
			}
		}
		else if (find(line, "rect")) {
			log("create");
    		std::stringstream s(line);
    		std::string dummy;
    		int x = 0;
			char dummyChar;
			int y = 0;
			s >> dummy;
			s >> x;
			s >> dummyChar;
			s >> y;
			for (int pixelY=0; pixelY<y; pixelY++) {
				for (int pixelX=0; pixelX<x; pixelX++) {
					pixel.push_back({pixelX,pixelY});
				}
			} 
		}
        show(pixel, screenX, screenY);
	}
    part1 = pixel.size();
	
	log("part1 => " << part1);
	log("part2 => " << part2);

	return 1;
}
