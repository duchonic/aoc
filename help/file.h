#pragma once

std::vector<std::string> readstuff() {
	std::vector<std::string> data;
	std::string a;
	while ( std::getline(std::cin, a)) {
		data.push_back(a);
	}
	return data;
}