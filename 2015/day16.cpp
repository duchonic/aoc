#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    // std::cout << "split function" << '\n';
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

int main(){

  std::cout << "start" << std::endl;

  std::string line;
  std::ifstream myfile ("2015/day16.data");
  std::map<std::string, int> data;

  data[std::string("children")] = 3;
  data[std::string("cats")] = 7;
  data[std::string("samoyeds")] = 2;
  data[std::string("pomeranians")] = 3;
  data[std::string("akitas")] = 0;
  data[std::string("vizslas")] = 0;
  data[std::string("goldfish")] = 5;
  data[std::string("trees")] = 3;
  data[std::string("cars")] = 2;
  data[std::string("perfumes")] = 1;

  for(auto& x : data){
    std::cout << x.first << ":" << x.second << std::endl;
  }

  if (myfile.is_open()){

    int auntNr = 0;

    while (getline(myfile,line)){
      auntNr++;
      std::vector<std::string> splitLine = split(line, ',');
      int foundInLine = 0;
      for(auto& x: splitLine){
        std::vector<std::string> splitValue = split(x, ':');

        for(auto& check : data){

          if(check.first.compare(splitValue[0]) == 0){

            if( (check.first.compare("cats") == 0) ||
                (check.first.compare("trees") == 0) ){

              if(check.second < std::stoi(splitValue[1]) ){
                foundInLine++;
                std::cout << auntNr << " cat and tree:" << foundInLine << " ";
                std::cout << check.first << ":" << check.second << " ";
                std::cout << splitValue[0] << ":" << splitValue[1] << std::endl;
              }
            }
            else if( (check.first.compare("pomeranians") == 0) ||
                (check.first.compare("goldfish") == 0) ){

              if(check.second > std::stoi(splitValue[1]) ){
                foundInLine++;
                std::cout << auntNr << " cat and tree:" << foundInLine << " ";
                std::cout << check.first << ":" << check.second << " ";
                std::cout << splitValue[0] << ":" << splitValue[1] << std::endl;
              }
            }
            else{
              if(check.second == std::stoi(splitValue[1]) ){
                foundInLine++;
                std::cout << auntNr << " found line:" << foundInLine << " ";
                std::cout << check.first << ":" << check.second << " ";
                std::cout << splitValue[0] << ":" << splitValue[1] << std::endl;
              }
            }
          }
          if(foundInLine==3){
            std::cout << "found line" << std::endl;
          }
        }
        //std::cout << foundInLine << std::endl;
      }
    }
    myfile.close();
  }
  else{
    std::cout << "unable to open file" << std::endl;
  }
  return 0;
}
