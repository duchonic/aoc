#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <list>


int getRow(std::string code){
	assert(code.size()==7);
	std::bitset<7> nr(code.c_str(), code.size(), 'F', 'B');
	return nr.to_ulong();
}


int getCol(std::string code){
	assert(code.size()==3);
	std::bitset<3> nr(code.c_str(), code.size(), 'L', 'R');
	return nr.to_ulong();
}


int getid(int row, int col){
	return ((row*8)+col);
}

int main(){
	std::ifstream inputFile("day05.txt");        // Input file stream object
	std::list<int> ids;

	/* check some examples */
	assert(getRow("FBFBBFF") == 44);
	assert(getCol("RLR") == 5);

	int maxID = 0;

	if (inputFile.good()) {
		std::string seatCode;
		while(inputFile >> seatCode){
			int id = getid( getRow(seatCode.substr(0,7)) , getCol(seatCode.substr(7,3)) );
			ids.push_back(id);
			if(id > maxID){
				maxID = id;
			}
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	std::cout << "part1: " << maxID << std::endl;
	std::cout << "part2:" << std::endl;
	ids.sort();
	int previous = 0;
	for(auto id: ids){
		if( previous+1 != id){
			std::cout << "===========  empty seat:" << id-1 << std::endl ;
		}
		previous = id;
	}
	return 0;
}

