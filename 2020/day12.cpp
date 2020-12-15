#include <iostream>
#include <fstream>
#include <string>
#include <complex>
#include <vector>
#include <math.h>

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

std::pair<int,std::pair<int,int> > ship;
std::pair<int,int> waypoint;

void move(int dir, int steps){
	switch (dir)
	{
		case NORTH:
			waypoint.second += steps;
			break;
		case SOUTH:
			waypoint.second -= steps;
			break;
		case EAST:
			waypoint.first += steps;
			break;
		case WEST:
			waypoint.first -= steps;
			break;
		default:
			assert(0);
			break;
		}
}

void foreward(int steps){
	int xdiff = waypoint.first - ship.second.first;
	int ydiff = waypoint.second - ship.second.second;
	ship.second.first += xdiff * steps;
	waypoint.first += xdiff * steps;
	ship.second.second += ydiff * steps;
	waypoint.second += ydiff * steps;
}

void rotate(float angle){

	int move2X0 = waypoint.first;
	int move2Y0 = waypoint.second;

	ship.second.first -= move2X0;
	ship.second.second -= move2Y0;

	// rotate
	const std::complex<double> test(ship.second.first, ship.second.second);

	std::cout << "abs:" << std::abs(test) << std::endl;
	std::cout << "angle:" << angle << std::endl;
	std::cout << "arg:" << std::arg(test)+angle << std::endl;




	// go back
	ship.second.first += move2X0;
	ship.second.second += move2Y0;

}

int main(){
	std::ifstream inputFile("day12_test.txt");        // Input file stream object
	ship = std::make_pair(EAST, std::make_pair(0,0));
	waypoint = std::make_pair(10,1);
	if (inputFile.good()) {
		char letter;
		int nr;
		while(inputFile >> letter >> nr){
			std::cout << letter << ' ' << nr << std::endl;
			if(letter == 'F'){
				foreward(nr);
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
				rotate(  2 * M_PI/360 * nr);
			}
			else if(letter == 'R'){
				rotate( -2 * M_PI/360 * nr );
			}

			std::cout << "ship:" << ship.second.first << '/' << ship.second.second << std::endl;
			std::cout << "wayp:" << waypoint.first << '/' << waypoint.second << std::endl;

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

