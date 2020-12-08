#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <regex>


struct description
{
	std::string detail;
	std::string color;
	int nr;
	std::set<description> children;
};

void showContainer(description);

inline bool operator<(const description& lhs, const description& rhs)
{
  return lhs.color < rhs.color;
}


int main(){
	std::ifstream inputFile("day07_test.txt");        // Input file stream object
	std::set<description> testContainer;
	if (inputFile.good()) {
		for (std::string line; std::getline(inputFile, line); ) {
			std::regex removeText("bags.|bag.|contain|contains");
			std::string test = std::regex_replace(line, removeText, "" );

			std::cout << test << std::endl;
			description info;
			std::stringstream linestream(test);
			linestream >> info.detail >> info.color;
			info.nr = 1;

			for(std::string word; linestream >> word; ){
				if(word == "no"){
					break;
				}
				else{
					description child;
					linestream >> child.detail >> child.color;
					child.nr = std::stoi(word);
					info.children.insert(child);
				}
			}

			description gotChild{"", ""};
			for (description item : testContainer){
				for(description child : item.children){
					if (child.color == info.color && child.detail == info.detail) {
						gotChild = child;
					}
				}
			}
			std::cout << gotChild.detail << ' ' << gotChild.color << std::endl;

			testContainer.insert(info);
		}
	}
	else{
		std::cout << "file not found" << std::endl;
	}

	for(description entry : testContainer){

		showContainer(entry);

	}

	std::cout << std::endl;
	std::cout << "part1:" << std::endl;

	std::cout << "part2:" << std::endl;
	return 0;
}


void showContainer(description item){
	std::cout << item.detail << ' ' << item.color << ':' << item.nr << std::endl;
	if(item.children.size()){
		for(description child: item.children){
			std::cout << " -> " ;
			showContainer(child);
		}
	}
}