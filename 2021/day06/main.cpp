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

#include <functional>
#include <numeric>
#include <iomanip>
#include <algorithm> // for sort
#include <execution> // for parallel execution

int main() {

	//std::vector<uint8_t> data{3,4,3,1,2};
	std::vector<int> data{3,3,5,1,1,3,4,2,3,4,3,1,1,3,3,1,5,4,4,1,4,1,1,1,3,3,2,3,3,4,2,5,1,4,1,2,2,4,2,5,1,2,2,1,1,1,1,4,5,4,3,1,4,4,4,5,1,1,4,3,4,2,1,1,1,1,5,2,1,4,2,4,2,5,5,5,3,3,5,4,5,1,1,5,5,5,2,1,3,1,1,2,2,2,2,1,1,2,1,5,1,2,1,2,5,5,2,1,1,4,2,1,4,2,1,1,1,4,2,5,1,5,1,1,3,1,4,3,1,3,2,1,3,1,4,1,2,1,5,1,2,1,4,4,1,3,1,1,1,1,1,5,2,1,5,5,5,3,3,1,2,4,3,2,2,2,2,2,4,3,4,4,4,1,2,2,3,1,1,4,1,1,1,2,1,4,2,1,2,1,1,2,1,5,1,1,3,1,4,3,2,1,1,1,5,4,1,2,5,2,2,1,1,1,1,2,3,3,2,5,1,2,1,2,3,4,3,2,1,1,2,4,3,3,1,1,2,5,1,3,3,4,2,3,1,2,1,4,3,2,2,1,1,2,1,4,2,4,1,4,1,4,4,1,4,4,5,4,1,1,1,3,1,1,1,4,3,5,1,1,1,3,4,1,1,4,3,1,4,1,1,5,1,2,2,5,5,2,1,5};
	int part1 = 0;
	int part2 = 0;

	int days = 0;
	double oldsize;
	double oldfactor;
	while (days++ < 256) {

		if (days%32 == 0) {
			double factor = double(data.size()/oldsize);
			std::cout << days << " total : " << data.size() <<  " diff: " << data.size() - oldsize << " factor:"  << factor << " diff " << factor-oldfactor << std::endl;
			oldfactor = factor;
			oldsize = data.size();
		}
		int newfish = 0;

    	std::transform(data.begin(), data.end(), data.begin(),
                   [&newfish](uint8_t i) -> uint8_t { 
					   i--;
					   if (i==255) {
						   i = 6;
						   newfish++;
					   }
					   return i; });
		//std::for_each(data.begin(), data.end(), myfunction);
		//std::cout << std::to_string( data.at(0) ) << std::endl;

		for (int n=0; n < newfish; n++) {
			data.push_back(8);
			//std::cout << 8 << ',';
		}
		//std::cout << std::endl;

	}

	std::cout << "part1 : " << data.size() << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 0;
}
