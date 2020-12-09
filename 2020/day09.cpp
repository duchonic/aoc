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


	const int LOOKBACK = 25;

	std::list<long> sums;
	const long GOAL = 27911108;
	for(auto number : numbers){
		//add current number to list
		sums.push_back(number);
		//check if sum of list is bigger than GOAL
		while( std::accumulate(sums.begin(), sums.end(), 0) > GOAL ){
			sums.pop_front();
		}
		//if sum is equal GOAL get smallest and biggest value of list
		if(std::accumulate(sums.begin(), sums.end(), 0) == GOAL){
			sums.sort();
			std::cout << sums.front() << " + " << sums.back() << 
				" = " << sums.front() + sums.back() << std::endl;
			break;
		}
	}
	return 0;

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

