#include <iostream>
#include <fstream>
#include <string>

#include <vector>

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

std::pair<int,std::pair<int,int> > ship;

void move(int dir, int steps){
	switch (dir)
	{
		case NORTH:
			ship.second.first -= steps;
			break;
		case SOUTH:
			ship.second.first += steps;
			break;
		case EAST:
			ship.second.second += steps;
			break;
		case WEST:
			ship.second.second -= steps;
			break;
		default:
			break;
		}
}

int main(){
	std::ifstream inputFile("day12.txt");        // Input file stream object
	ship = std::make_pair(EAST, std::make_pair(0,0));
	if (inputFile.good()) {
		char letter;
		int nr;
		while(inputFile >> letter >> nr){
			std::cout << letter << ' ' << nr << std::endl;
			if(letter == 'F'){
				move(ship.first, nr);
			}
			else if(letter == 'N'){
				move(NORTH, nr);
			}
			else if(letter == 'E'){
				move(EAST, nr);
			}
			else if(letter == 'S'){
				move(SOUTH, nr);
			}
			else if(letter == 'W'){
				move(WEST, nr);
			}
			else if(letter == 'L'){
				int steps = nr/90;
				ship.first = ship.first-steps;
			}
			else if(letter == 'R'){
				int steps = nr/90;
				ship.first = ship.first+steps;
			}

			if(ship.first >= 4){
				ship.first -= 4;
			}
			else if(ship.first < 0){
				ship.first += 4;
			}

		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "part1: " << ship.second.first << '/' << ship.second.second << std::endl;

	std::cout << "part2:" << std::endl;
	return 0;
}

