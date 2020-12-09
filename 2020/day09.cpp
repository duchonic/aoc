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
	long solutionPart1 = 0;
	long solutionPart2 = 0;

	for(size_t pos = LOOKBACK; pos < numbers.size(); pos++){
		bool test = false;
		for(size_t check=pos-LOOKBACK; check < pos; check++){
			for(size_t sum=check+1;sum < pos; sum++){
				if( numbers[pos]==numbers[check]+numbers[sum] ){
					test = true;
				}
			}
		}
		if(!test){
			solutionPart1 = numbers[pos];
		}
	}

	std::list<long> sums;
	for(auto number : numbers){
		//add current number to list
		sums.push_back(number);
		//check if sum of list is bigger than GOAL
		while( std::accumulate(sums.begin(), sums.end(), 0) > solutionPart1 ){
			sums.pop_front();
		}
		//if sum is equal GOAL get smallest and biggest value of list
		if(std::accumulate(sums.begin(), sums.end(), 0) == solutionPart1){
			sums.sort();
			solutionPart2 = sums.front() + sums.back();	
			break;
		}
	}

	std::cout << std::endl;
	std::cout << "part1:" << solutionPart1 << std::endl;
	std::cout << "part2:" << solutionPart2 << std::endl;

	return 0;
}

