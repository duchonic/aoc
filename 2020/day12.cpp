#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <string>
#include <complex>
#include <vector>
#include <cmath>
#include <assert.h>

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

std::pair<int,std::pair<double, double> > ship;
std::pair<double, double> waypoint;

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

void rotate(double angle){

	int move2X0 = ship.second.first;
	int move2Y0 = ship.second.second;

	waypoint.first -= move2X0;
	waypoint.second -= move2Y0;

	std::complex<double> point(waypoint.first, waypoint.second);
	point *=  std::polar( 1.0, angle );
	waypoint.first = round(point.real());
	waypoint.second = round(point.imag());
	

	std::cout << waypoint.second << '+' << move2Y0 << std::endl;

	// go back
	waypoint.first += move2X0;
	waypoint.second += move2Y0;
}

int main(){
	std::ifstream inputFile("day12.txt");        // Input file stream object
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
				rotate(  2 * M_PI /360 * nr);
			}
			else if(letter == 'R'){
				rotate( -2 * M_PI /360 * nr );
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
	std::cout << "part2: " << abs(ship.second.first)+abs(ship.second.second) <<  std::endl;
	return 0;
}