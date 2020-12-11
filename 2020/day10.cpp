#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <math.h>

int main(){
	std::list<int> numbers;
	std::set<int> nrSet;
	std::ifstream inputFile("day10_test.txt");        // Input file stream object

	if (inputFile.good()) {
		int nr;
		while(inputFile >> nr){
			numbers.push_back(nr);
			nrSet.insert(nr);
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}
	numbers.push_back(0);
	nrSet.insert(0);
	numbers.sort();
	int maximum = numbers.back()+3;
	numbers.push_back(maximum);
	nrSet.insert(maximum);

	std::vector<int> numVector;
	std::array<int,4> jolts{0,0,0,0};

	for(int val : numbers){
		numVector.push_back(val);
	}


	int index = 0;
	for(auto val : numVector){
		std::cout << val << ' ' << index << "/" << numVector.size() << std::endl;

		for(int test : {1,2,3}){
			try{
				int distance =numVector.at(index+test)-val;
				if( distance <= 3 ){
						jolts.at(distance) += 1;
						//std::cout << "got one t: " << distance << std::endl;
						break;
				}
			}
			catch(const std::exception& e){
				std::cerr << e.what() << '\n';
			}

		}
		index += 1;

	}

	for (auto entry : jolts){
		std::cout << entry << ' ';
	}
	std::cout << "part2 1: " << jolts.at(1)* jolts.at(3) << std::endl;


	/**
	 *
	 *
	 * 	(0), 1, 4, 5, 6, 7, 10, 11, 12, 15, 16, 19, (22)
		(0), 1, 4, 5, 6, 7, 10, 12, 15, 16, 19, (22)
		(0), 1, 4, 5, 7, 10, 11, 12, 15, 16, 19, (22)
		(0), 1, 4, 5, 7, 10, 12, 15, 16, 19, (22)
		(0), 1, 4, 6, 7, 10, 11, 12, 15, 16, 19, (22)
		(0), 1, 4, 6, 7, 10, 12, 15, 16, 19, (22)
		(0), 1, 4, 7, 10, 11, 12, 15, 16, 19, (22)
		(0), 1, 4, 7, 10, 12, 15, 16, 19, (22)
	*/

	std::vector<int> secondPart;

	for ( int index = 0 ; index <= maximum; index++){
		if( nrSet.find(index) != nrSet.end() ){
			secondPart.push_back(1);
		}
		else{
			secondPart.push_back(0);
		}
	}

	std::cout << "make a special vector" << std::endl;


	int potenz = 0;
	for ( int pos=0; pos < secondPart.size() ; pos++){

		try
		{
			std::cout << secondPart.at(pos)  << ' ' ;
			if (secondPart.at(pos)==1 && secondPart.at(pos+1)==1 && secondPart.at(pos+2)==1)
			{
				potenz += 1;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}



	std::cout << "part2: " << pow(2,potenz) << std::endl;

	return 0;
}

