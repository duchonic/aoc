#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"
#include <cstdlib>
#include <map>

class Cave
{
private:
	std::vector<Cave> neighbours;
	int size;
public:
	std::string name;
	Cave(int s, std::string name);
	~Cave();
	void show() {
		std::cout << size << std::endl;
	}
	void add(Cave c);
	int count(void) {
		return (neighbours.size());
	}
};

Cave::Cave(int s, std::string n): size(s), name(n) {
	std::cout << "constructor" << std::endl;
}

Cave::~Cave() {
}

void Cave::add(Cave c) {
	neighbours.push_back(c);
}




static std::vector<std::pair<int,int>> map;

int main() {
	std::vector<std::string> data = readstuff();

	std::vector<Cave> map;

	for (auto line : data) {
		std::vector<std::string> caves;
		split_str(line, '-', caves);
		logger("from " << caves.at(0) << " to " << caves.at(1));		
		std::string name = caves.at(0);
		std::string destination = caves.at(1);
		
		Cave n(1, name);
		map.push_back(n);
		
		//if (std::find(map.begin(), map.end(), [](Cave c){ return c.count() == 1; }) == map.end()  ) {
		//		logger("not found");
		//}	
	}
	int part1 = 0x81;
	
	std::cout << "part1 : " << part1 << std::endl;

	return 0;
}
