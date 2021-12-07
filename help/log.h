#pragma once

#include <iostream>
#include <bitset>
#include <iomanip>

#define logger(stuff) std::cout << stuff << std::endl;

void showData(std::vector<std::bitset<16>> data) {
	int16_t linenumber = 1;
	for (auto line: data) {
		std::cout 
            << std::setw(4) << linenumber++ << ' ' 
            << line << ' ' 
            << std::setw(4) << line.to_ulong() << std::endl;
	}
}

void logvec(std::vector<int> vec) {
	for (auto item : vec) {
		std::cout << item << ' ';
	}
	std::cout << std::endl;
}

