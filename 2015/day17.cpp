#include <iostream>
#include <vector>

#define CHECK_BIT_M(var,pos) (((var)>>(pos)) & 1)

std::vector<int> container{43,3,4,10,21,44,4,6,47,41,34,17,17,44,36,31,46,9,27,38};

// 2^20 = 1'048'576
int volume[1048576];
int solutions = 0;

int minimumCountBits = 200;
int countBits = 0;
int solutionsPart2 = 0;

int main(){
  for(int i = 0; i < 1048576; i++){
    volume[i] = 0;
    countBits = 0;
    for (int bit = 0; bit < 20; bit++){
      if(CHECK_BIT_M(i,bit)){
        countBits++;
        volume[i] += container[bit];
      }
    }
    if (volume[i] == 150){
      if( countBits == 4){
        solutionsPart2++;
      }
      if (countBits < minimumCountBits)
      {
        minimumCountBits = countBits;
        std::cout << "minimum: " << minimumCountBits << '\n';
      }
      solutions++;
    }
  }
  std::cout << "soluions: " << solutions << '\n';
  std::cout << "solution Part2: " << solutionsPart2 << '\n';
}
