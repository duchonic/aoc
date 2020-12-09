#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <list>

/**
 * how does it work
 * (magic!)
 *
 *    A
 *   / \
 *  /   \
 *  | 0 | 0 -> FF -> 00
 *  | 1 | 1 -> FB -> 01
 *  | 0 | 2 -> BF -> 10
 *  | 0 | 3 -> BB -> 11
 *  -----
 *  / . \
 *    .
 *    .
 */
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

	if (inputFile.good()) {
		int maxID = 0;
		int mySeat = 0;

		std::string seatCode;
		while(inputFile >> seatCode){
			int id = getid( getRow(seatCode.substr(0,7)) , getCol(seatCode.substr(7,3)) );
			ids.push_back(id);
			maxID = std::max(id, maxID);
		}

		ids.sort();

		for(int previous = 0; int id: ids){
			if( previous+1 != id){
				mySeat = id-1;
			}
			previous = id;
		}

		std::cout << "part1: " << maxID << std::endl;
		for(std::list<int>::iterator it=ids.begin(); it!=ids.end();it++){
			//std::cout << (*it-1) << " " << (*it) << std::endl;
			if( (*it-1)+1 != (*it) ){
				std::cout << "part2: " << *it << std::endl;
			}
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}
	return 0;
}

