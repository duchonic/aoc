#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "log.h"


std::vector<std::string> readFile(std::string file) {
	std::vector<std::string> data;
	std::ifstream myfile; 
	myfile.open(file);

	if (myfile.is_open()) {
		while (myfile) {
			std::string line;
			std::getline(myfile, line);
			data.push_back(line);
		}
	}
	else {
		logger("file not found");
	}
	return (data);
}

std::vector < std::pair< std::pair<int,int>, std::pair<int,int>>> readLines() {
	std::vector< std::pair< std::pair<int,int>, std::pair<int,int>>> retval;
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss(line);
		std::pair<int,int> start;
		std::pair<int,int> end;
		std::string dummystring;
		char dummychar;
		ss >> start.first;
		ss >> dummychar;
		ss >> start.second;
		ss >> dummystring;
		ss >> end.first;
		ss >> dummychar;
		ss >> end.second;
		retval.push_back(std::make_pair(start, end));
	}
	return retval;
}

std::vector< std::pair< std::array<std::string, 10>, std::array<std::string, 4> >> readstuffdigits() {
	std::vector< std::pair< std::array<std::string, 10>, std::array<std::string, 4> >> retval;
	std::string line;
	while (std::getline(std::cin, line)) {
		std::stringstream ss(line);
		std::pair< std::array<std::string, 10>, std::array<std::string, 4>> entry;
		std::string nr;
		char dummy;
		for (int digits=0; digits<10; digits++) {
			ss >> nr;
			entry.first.at(digits) = nr;
		}
		ss >> nr;
		for (int digits=0; digits<4; digits++) {
			ss >> nr;
			entry.second.at(digits) = nr;
		}
		retval.push_back(entry);
	}
	return retval;
}

std::vector<std::bitset<16>> readstuffbitset() {
	std::vector<std::bitset<16>> data;
	std::string a;
	while ( std::getline(std::cin, a)) {
		std::bitset<16> b{a};
		data.push_back(b);
	}
	return data;
}

std::vector<std::string> readstuff() {
	std::vector<std::string> data;
	std::string a;
	while ( std::getline(std::cin, a)) {
		data.push_back(a);
	}
	return data;
}

std::vector<int16_t> readstuff2int() {
	std::vector<int16_t> data;
	std::string a;
	while (std::getline(std::cin, a)) {
		data.push_back(stoi(a));
	}
	return data;
}

std::vector<std::string> readstuff(std::string delimiter) {
	std::vector<std::string> data;
	std::string a;
	while ( std::getline(std::cin, a, delimiter.at(0))) {
        a += delimiter;
		data.push_back(a);
	}
	return data;
}
