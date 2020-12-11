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
					(void)c;
					extraLine.push_back('.');
				}
				room.push_back(extraLine);
			}
			room.push_back(newRow);

			if(!inputFile.good()){
				//add extra line on top bottom '...'
				std::vector<char> extraLine;
				for(auto c : newRow ){
					(void)c;
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
	int round = 0;
	while(poepleMoved){
		poepleMoved = false;

		std::cout << std::endl << "round:" << round++ << std::endl;
		std::vector<std::vector<char>> roomSave = room;

		for(unsigned int y=1; y < room.size()-1 ; y++){
			for (unsigned int x=1; x < room.at(0).size()-1 ; x++){
				//std::cout << room.at(y).at(x);

				if( roomSave.at(y).at(x) == 'L'){
					/* part 1
					std::array<int, 3> test{-1,0,1};
					*/
					
					bool foundFree = false;
					bool foundOccupied = false;
					
					//look up
					for(int yup=y-1; yup>0;yup--){
						char c = roomSave.at(yup).at(x) ;
						if(c == '#'){
							foundOccupied = true;
							break;
							//std::cout << "found up at:" << x << '/' << yup << std::endl;
						}
						else if(c == 'L'){
							foundFree = true;
							break;
						}
					}
					//look down
					for(int ydown=y+1; ydown < room.size(); ydown++){
						char c =roomSave.at(ydown).at(x);
						if(c == '#'){
							foundOccupied = true;
							break;
							//std::cout << "found down at:" << x << '/' << yduown << std::endl;
						}
						else if(c == 'L'){
							foundFree = true;
							break;
						}
					}
					//look left
					for(int xleft=x-1; xleft>0;xleft--){
						char c = roomSave.at(y).at(xleft) ;
						if(c == '#'){
							foundOccupied = true;
							break;
							//std::cout << "found left at:" << xleft << '/' << y << std::endl;
						}
						else if(c == 'L'){
							foundFree = true;
							break;
						}
					}
					for(int xright=x+1; xright< room.at(0).size() ; xright++){
						char c = roomSave.at(y).at(xright) ;
						if(c == '#'){
							foundOccupied = true;
							break;
							//std::cout << "found right at:" << xright << '/' << y << std::endl;
						}
						else if(c == 'L'){
							foundFree = true;
							break;
						}
					}
					
					//look up/left
					int xup = x;
					int yleft = y;
					while(true){
						try{
							yleft -= 1;
							xup -= 1;
							char c = roomSave.at(yleft).at(xup);
							if(c == '#'){
								foundOccupied = true;
								break;
								//std::cout << "found up left:" << xup << '/' << yleft << std::endl;
							}
							else if(c == 'L'){
								foundFree = true;
								break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
						
					//look up/right
					xup = x;
					int yright = y;
					while(true){
						try{
							yright += 1;
							xup -= 1;
							char c = roomSave.at(yright).at(xup);
							if(c == '#'){
								foundOccupied = true;
								break;
								//std::cout << "found up right:" << xup << '/' << yright << std::endl;
							}
							else if(c == 'L'){
								foundFree = true;
								break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
							
					//look down/left
					int xdown = x;
					yleft = y;
					while(true){
						try{
							yleft -= 1;
							xdown += 1;
							char c = roomSave.at(yleft).at(xdown);
							if(c == '#'){
								foundOccupied = true;
								//std::cout << "found down left:" << xdown << '/' << yleft << std::endl;
								break;
							}
							else if(c == 'L'){
								foundFree = true;
								break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
					
					//look down/right
					xdown = x;
					yright = y;
					while(true){
						try{
							yright += 1;
							xdown += 1;
							char c = roomSave.at(yright).at(xdown);
							if(c == '#'){
								foundOccupied = true;
								//std::cout << "found down right:" << xdown << '/' << yright << std::endl;
								break;
							}
							else if (c == 'L'){
								foundFree = true;
								break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
				
					/* PART 1
					for(int testy : test){
						for(int testx : test){
							if( !(testx==0 && testy == 0) ){
								if(roomSave.at(y+testy).at(x+testx) == 'L' ){
									foundFree = true;
								}
								if(roomSave.at(y+testy).at(x+testx) == '#' ){
									foundOccupied = true;
								}

							}
						}
					}
					*/
					//std::cout << ' ';
					if(foundFree && !foundOccupied){
						poepleMoved = true;
						room.at(y).at(x) = '#';
					}
				}
				else if(roomSave.at(y).at(x) == '#'){
					/* part1
					std::array<int, 3> test{-1,0,1};
					*/
					int foundPeople = 0;
					
					//look up
					for(int yup=y-1; yup>0;yup--){
						char c = roomSave.at(yup).at(x) ;
						if(c == '#'){
							//std::cout << __LINE__ << ':' << foundPeople << std::endl;
							foundPeople += 1;
							break;
						}
						else if(c == 'L'){
							break;
						}
					}
					//look down
					for(int ydown=y+1; ydown < room.size(); ydown++){
						char c =roomSave.at(ydown).at(x);
						if(c == '#'){
							//std::cout << __LINE__ << ':' << foundPeople << std::endl;
							foundPeople += 1;
							break;
						}
						else if(c == 'L'){
							break;
						}
					}
					//look left
					for(int xleft=x-1; xleft>0;xleft--){
						char c = roomSave.at(y).at(xleft) ;
						if(c == '#'){
							//std::cout << __LINE__ << ':' << foundPeople << std::endl;
							foundPeople += 1;
							break;
						}
						else if(c == 'L'){
							break;
						}
					}
					//right
					for(int xright=x+1; xright< room.at(0).size() ; xright++){
						char c = roomSave.at(y).at(xright) ;
						if(c == '#'){
							//std::cout << __LINE__ << ':' << foundPeople << std::endl;
							foundPeople += 1;
							break;
						}
						else if(c == 'L'){
							break;
						}
					}

					//look up/left
					int xup = x;
					int yleft = y;
					while(true){
						try{
							yleft -= 1;
							xup -= 1;
							char c = roomSave.at(yleft).at(xup);
							if(c == '#'){
								foundPeople += 1;
								break;
							}
							else if(c == 'L'){
								break;
							}
	
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
						
					//look up/right
					xup = x;
					int yright = y;
					while(true){
						try{
							yright += 1;
							xup -= 1;
							char c = roomSave.at(yright).at(xup);
							if(c == '#'){
								foundPeople += 1;
								break;
							}
							else if(c == 'L'){
									break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
							
					//look down/left
					int xdown = x;
					yleft = y;
					while(true){
						try{
							yleft -= 1;
							xdown += 1;
							char c = roomSave.at(yleft).at(xdown);
							if(c == '#'){
								foundPeople += 1;
								break;
							}
							else if(c == 'L'){
								break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
					
					//look down/right
					xdown = x;
					yright = y;
					while(true){
						try{
							yright += 1;
							xdown += 1;
							char c = roomSave.at(yright).at(xdown);
							if(c == '#'){
								foundPeople += 1;
								break;
							}
							else if(c == 'L'){
								break;
							}
						}
						catch(const std::exception& e)
						{
							break;
						}
					}
				

					/* PART 1
					for(int testy : test){
						for(int testx : test){
							if( !(testx==0 && testy == 0) ){
								if(roomSave.at(y+testy).at(x+testx) == '#' ){
					
					
									foundPeople += 1;
								}

							}
						}
					}
					*/
					//std::cout << foundPeople;
					if(foundPeople>=5){
						poepleMoved = true;
						room.at(y).at(x) = 'L';
					}

				}
				else{
					//std::cout << ' ';
				}
			}
			//std::cout << std::endl;
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

