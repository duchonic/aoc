#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

int main(){
	std::vector<int> numbers;
	std::ifstream inputFile("day09.txt");        // Input file stream object

	if (inputFile.good()) {
		int nr;
		while(inputFile >> nr ){
			numbers.push_back(nr);
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	std::list<long> sums;

	const int LOOKBACK = 25;
	const long GOAL = 27911108;

	for(int p = 0; p < numbers.size(); p++){
		sums.push_back(numbers[p]);

		while( std::accumulate(sums.begin(), sums.end(), 0) > GOAL ){
			sums.pop_front();
		}

		if(std::accumulate(sums.begin(), sums.end(), 0) == GOAL){
			sums.sort();
			for(long i:sums){
				std::cout << i << std::endl;
			}
		}

	}

	for(int pos = LOOKBACK; pos < numbers.size(); pos++){
		std::cout << numbers[pos] << std::endl;

		bool test = false;
		sums.push_back(numbers[pos]);
		for(int check=pos-LOOKBACK; check < pos; check++){
			for(int sum=check+1;sum < pos; sum++){
				if( numbers[pos]==numbers[check]+numbers[sum] ){
					test = true;
				}
			}
		}
		if(!test){
			std::cout << "line is not fine: " << pos << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "part1:" << std::endl;
	std::cout << "part2:" << std::endl;
	return 0;
}

