#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <list>

int main(){
	std::vector<std::vector<char>> room;

	std::ifstream inputFile("day11.txt");        // Input file stream object
	std::cout << "day11" << std::endl;

	if (inputFile.good()) {
		char nr;
		std::string row;

		while(inputFile >> row){
			std::vector<char> newRow;
			newRow.push_back('.');
			for(char c : row){
				newRow.push_back(c);
			}
			newRow.push_back('.');

			if(room.size()==0){
				//add extra line on top bottom '...'
				std::vector<char> extraLine;
				for(auto c : newRow ){
					extraLine.push_back('.');
				}
				room.push_back(extraLine);
			}
			room.push_back(newRow);

			if(!inputFile.good()){
				//add extra line on top bottom '...'
				std::vector<char> extraLine;
				for(auto c : newRow ){
					extraLine.push_back('.');
				}
				room.push_back(extraLine);
			}

		}


	}
	else{
		std::cout << "file not found" << std::endl;
	}

	bool poepleMoved = true;
	int counter = 0;
	while(poepleMoved){
		std::cout << std::endl << "round # " << counter++ << std::endl;
		poepleMoved = false;
		std::vector<std::vector<char>> roomSave = room;

		for(unsigned int y=1; y < room.size()-1 ; y++){
			for (unsigned int x=1; x < room.at(0).size()-1 ; x++){
				std::cout << room.at(y).at(x);

				if( roomSave.at(y).at(x) == 'L'){
					std::array<int, 3> test{-1,0,1};
					bool foundFree = false;
					bool foundOccupied = false;
					for(int testy : test){
						for(int testx : test){
							if( !(testx==0 && testy == 0) ){
								//std::cout << '(' << x+testx << '/' << y+testy << ':' << room.at(y+testy).at(x+testx)<< ')';
								if(roomSave.at(y+testy).at(x+testx) == 'L' ){
									foundFree = true;
								}
								if(roomSave.at(y+testy).at(x+testx) == '#' ){
									foundOccupied = true;
								}

							}
						}
					}
					if(foundFree && !foundOccupied){
						poepleMoved = true;
						room.at(y).at(x) = '#';
					}
				}
				else if(roomSave.at(y).at(x) == '#'){
					std::array<int, 3> test{-1,0,1};
					int foundPeople = 0;
					for(int testy : test){
						for(int testx : test){
							if( !(testx==0 && testy == 0) ){
								//std::cout << '(' << x+testx << '/' << y+testy << ':' << room.at(y+testy).at(x+testx)<< ')';
								if(roomSave.at(y+testy).at(x+testx) == '#' ){
									foundPeople += 1;
								}

							}
						}
					}
					if(foundPeople>=4){
						poepleMoved = true;
						room.at(y).at(x) = 'L';
					}

				}
				else{
					//std::cout << ',';
				}
			}
			std::cout << std::endl;
		}
	}

	int seats=0;
	for(auto y : room){
		for(auto x : y){
			if( x == '#'){
				seats += 1;
			}
		}
	}

	std::cout << "part1:" << seats << std::endl;
	std::cout << "part2:" << std::endl;
	return 0;
}

