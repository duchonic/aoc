#pragma once

std::vector<std::string> readstuff() {
	std::vector<std::string> data;
	std::string a;
	while ( std::getline(std::cin, a)) {
		data.push_back(a);
	}
	return data;
}

std::vector<std::string> readstuff( std::string delimiter) {
	std::vector<std::string> data;
	std::string a;
	while ( std::getline(std::cin, a, delimiter.at(0))) {
        if (a.find(delimiter) != std::string::npos) {
            a.insert(0, delimiter);
        }
		data.push_back(a);
	}
	return data;
}
