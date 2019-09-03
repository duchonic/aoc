#include "template.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <fstream>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::vector<std::string> readFile(std::string filename){
  std::ifstream myfile(filename);
  std::vector<std::string> file;
  if(myfile.is_open()){
    std::string line;
    while(getline(myfile, line)){
      file.push_back(line);
    }
  }
  return file;
}

#ifdef TESTING
int main(){
  std::vector<std::string> file = readFile("day14.data");

  std::vector<std::string> x = split("one:two:three", ':');
  std::vector<std::string> y = split("pluto venus jupyter", ' ');

  std::vector<std::string> line4 = split(file.at(4), ' ');
  for(auto item: line4 ){
    std::cout << "item line 4: " << item << '\n';
  }

  for(auto line : file){
    std::cout << "line: " << line << std::endl;
  }

  for(auto element:x){
    std::cout << "elem: " << element << std::endl;
  }
  for(auto planet:y){
    std::cout << "planet: " << planet << std::endl;
  }
}
#endif
