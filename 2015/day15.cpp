#include <iostream>
#include <fstream>
#include <vector>

int calcTotal(std::vector<int> ratio);
int calcSum(std::vector<int> ratio, int spoons);
int main(){

  std::ifstream myfile ("day15.data");
  std::vector<int> combination{1,2,3,4};

  if (myfile.is_open()){
    std::string line;
    while (getline(myfile,line)){
      std::cout << "line: " << line << '\n';
    }
  }

  std::vector<int> sugar {3,0,0,-3,2};
  std::vector<int> sprinkler {-3,3,0,0,9};
  std::vector<int> candy {-1,0,4,0,1};
  std::vector<int> chocolate {0,0,-2,2,8};

  std::cout << "sum1 sugar 3 spoons: " << calcSum(sugar, 3) << '\n';
  std::cout << "sum2 sprin 3 spoons: " << calcSum(sprinkler, 3) << '\n';
  std::cout << "sum3 candy 3 spoons: " << calcSum(candy, 3) << '\n';
  std::cout << "sum4 choco 3 spoons: " << calcSum(chocolate, 3) << '\n';
}

int calcSum(std::vector<int> ratio, int spoons){
  int sum = 0;
  for(auto &times: ratio){
    sum += spoons * times;
  }
  return sum;
}

int calcTotal(std::vector<int> ratio){
  for (auto &x: ratio){
    std::cout << "ratio: " << x << '\n';
  }
  return 0;
}
