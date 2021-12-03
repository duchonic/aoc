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

#include <functional>
#include <numeric>
#include <iomanip>

bool checkEqual(std::vector<std::bitset<16>> input, uint8_t checkbit){
	if (input.size()%2) {
		return 0;
	}
	int count = 0;
	for (auto nr : input) {
		if (nr.test(checkbit)){
			count++;
		}
	}
	return (count == input.size()/2);
}
bool checkEpsilon(std::vector<std::bitset<16>> input, uint8_t checkbit){
	int count = 0;
	for (auto nr : input) {
		if (nr.test(checkbit)){
			count++;
		}
	}
	return (count <= input.size()/2);
}
bool checkGamma(std::vector<std::bitset<16>> input, uint8_t checkbit){
	int count = 0;
	for (auto nr : input) {
		if (nr.test(checkbit)){
			count++;
		}
	}
	return (count > input.size()/2);
}

void showData(std::vector<std::bitset<16>> data) {
	int16_t linenumber = 1;
	for (auto line: data) {
		std::cout << std::setw(4) << linenumber++ << ' ' << line << ' ' << line.to_ulong() << std::endl;
	}
}


int main() {
	std::vector<std::bitset<16>> data = readstuffbitset();
	std::vector<std::bitset<16>> secondpart{data};

	int16_t part1 = 0;
	int16_t part2 = 0;

	std::bitset<16> gamma = 0;
	std::bitset<16> epsilon = 0;
	std::bitset<16> equal = 0;

	for (int bit = 0; bit <= 11; bit++) {
		gamma.set(bit, checkGamma(data, bit));
		epsilon.set(bit, checkEpsilon(data, bit));
		equal.set(bit, checkEqual(data, bit));
	}
	std::cout << gamma << " " << gamma.to_ulong() << std::endl;
	std::cout << epsilon << " " << epsilon.to_ulong() << std::endl;
	std::cout << equal << " " << equal.to_ulong() << std::endl;
	std::cout << "part1 : " << gamma.to_ulong() *  epsilon.to_ulong() << std::endl;

	//part 2	
	for (int bit = 11; bit >= 0; bit--){
		std::cout << "checkbit:" << bit << std::endl;
		if (!checkEqual(data,bit)) { 
			if (checkGamma(data, bit)) {
				auto iterator = std::remove_if(data.begin(), data.end(), [bit](std::bitset<16> i){return !i.test(bit);} );
				data.erase(iterator, data.end());
			}
			else {
				auto iterator = std::remove_if(data.begin(), data.end(), [bit](std::bitset<16> i){return i.test(bit);} );
				data.erase(iterator, data.end());
			}
		}
		if (data.size() == 2) {
			showData(data);
			break;
		}
	}

	//part 2	
	for (int bit = 11; bit >= 0; bit--){
		std::cout << "checkbit:" << bit << std::endl;
		if (!checkEqual(secondpart,bit)) { 
			if (checkGamma(secondpart, bit)) {
				auto iterator = std::remove_if(secondpart.begin(), secondpart.end(), [bit](std::bitset<16> i){return i.test(bit);} );
				secondpart.erase(iterator, secondpart.end());
			}
			else {
				auto iterator = std::remove_if(secondpart.begin(), secondpart.end(), [bit](std::bitset<16> i){return !i.test(bit);} );
				secondpart.erase(iterator, secondpart.end());
			}
		}
		if (secondpart.size() == 2) {
			showData(secondpart);
			break;
		}
	}

	std::cout << "part2 : " << data.at(1).to_ulong() * secondpart.at(1).to_ulong() << std::endl;

	return 0;
}
