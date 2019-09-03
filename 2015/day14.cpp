#include <iostream>
#include <fstream>
#include <list>
#include <vector>

struct deer{
	std::string name;
	int velocity;
	int flytime;
	int pausetime;
};

/**
   velocity

	 flytime         pausetime
   |----------|-----------------------|

*/
int getDistance(deer myDeer, int time){

    // std::cout 	<< "velocity: " << myDeer.velocity << ' '
	// 			<< "flytime: " << myDeer.flytime << ' '
	// 			<< "pausetime: " << myDeer.pausetime << ' '
	// 			<< "totaltime: " << myDeer.flytime+myDeer.pausetime << ' '
	// 			<< "time: " << time << std::endl;

	int fullCycles = time / (myDeer.flytime + myDeer.pausetime);
	int modCycle = time % (myDeer.flytime + myDeer.pausetime);

	//std::cout << "full: " << fullCycles << " mod: " << modCycle << std::endl;

	if(modCycle > myDeer.flytime){
		modCycle = myDeer.flytime;
	}

	//std::cout << "full: " << fullCycles << " mod: " << modCycle << std::endl;

	return myDeer.velocity * ( (fullCycles*myDeer.flytime) + modCycle ) ;
}

int main(){
	std::list<deer> myDeers;
	std::ifstream myFile("day14.data");

	if(myFile.is_open()){
		std::string line;
		while(getline(myFile, line)){
			deer actDeer;

			std::cout << "line: " << line << '\n';
			std::string delimiter = " ";
			size_t pos = 0;
			int item = 0;
			std::string token;
			while ((pos = line.find(delimiter)) != std::string::npos) {

				token = line.substr(0, pos);

				if(item == 0){
					actDeer.name = token;
				}
				else if(item == 3){
					actDeer.velocity = std::stoi(token);
				}
				else if(item == 6){
					actDeer.flytime = std::stoi(token);
				}
				else if(item == 13){
					actDeer.pausetime = std::stoi(token);
				}
				item++;
			    line.erase(0, pos + delimiter.length());
			}
			myDeers.push_back(actDeer);
		}
	}

	std::vector<int> blub = {0,0,0,0,0,0,0,0,0,0};

	for(int i=1; i<=2503; i++){
	//for(int i=1;i<=10;i++){
		int max = 0;
		int maxIndex = 0;
		int index = 0;
		for (auto x: myDeers){
			//std::cout << x.name << " velocity: " << x.velocity << std::endl;
			int distance = getDistance(x, i);
			if(distance > max){
				max = distance;
				maxIndex = index;
			}
			std::cout << i << " distance: " << distance << std::endl;
			index++;
		}
		blub.at(maxIndex) += 1;
	}
	for (auto i:blub){
		std::cout << i << std::endl;
	}

	return 0;
}
