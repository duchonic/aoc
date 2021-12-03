#pragma once

#include <string>

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
