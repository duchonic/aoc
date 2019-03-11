#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define MATRIX_X 6
#define MATRIX_Y 6

std::vector< std::vector<int>> matrix;
std::vector< std::vector<int>> newMatrix;

int main(){
  std::ifstream myfile ("2015/day18.data");
  std::string line;

  newMatrix.resize(102, std::vector<int>(102, 0));

  if (myfile.is_open()){

    std::vector<int> spaces;
    spaces.resize(102, 0);
    matrix.push_back(spaces);

    while (getline(myfile,line)){
      std::vector<int> row;
      row.push_back(' ');
      for(auto &c: line){
        if(c==35){
          row.push_back(1);
        }
        else{
          row.push_back(0);
        }
      }
      row.push_back(' ');

      matrix.push_back(row);
    }

    matrix.push_back(spaces);
  }


  for (int step=0; step<=100; step++){
    int countLamps = 0;

    //newMatrix[1] = spaces;
    std::vector< std::vector<int>> newMatrix;
    newMatrix.resize(102, std::vector<int>(102, 0));

    for(int row=1; row <= 100; row++){
      for(int col=1; col <=100; col++){

        // A light which is on stays on when 2 or 3 neighbors are on, and turns off otherwise.
        // A light which is off turns on if exactly 3 neighbors are on, and stays off otherwise.

        for (int checkRow=-1; checkRow<=1; checkRow++){
          for (int checkCol=-1; checkCol<=1; checkCol++){
            if(matrix[row+checkRow][col+checkCol] == 1){
              newMatrix[row][col]++;
            }
          }
        }
        if(matrix[row][col] == 1){
          //light is on
          newMatrix[row][col]--;

          if(newMatrix[row][col] >= 2 && newMatrix[row][col] <= 3){
            countLamps++;
            newMatrix[row][col] = 1;
          }
          else{
            newMatrix[row][col] = 0;
          }
        }
        else{
          //light is off
          if(newMatrix[row][col] == 3){
            countLamps++;
            newMatrix[row][col] = 1;
          }
          else{
            newMatrix[row][col] = 0;
          }
        }
        //std::cout << matrix[row][col] << ' ';
      }
      //std::cout << '\n';
    }
    std::cout << "step: " << step << " Lamps: " << countLamps << '\n';

    matrix = newMatrix;

    //matrix.resize(MATRIX_Y+2, std::vector<int>(MATRIX_X+2, '.') );
    // std::cout << ". is 46 / # is 35 / ' ' is 32 " << '\n';

    // std::cout << "newMatrix line 1" << '\n';
    // for (int& t: newMatrix[1]){
    //   std::cout << t << ' ';
    // }
    // std::cout << '\n';
    // std::cout << "matrix line 1" << '\n';
    // for (int& t: matrix[1]){
    //   std::cout << t << ' ';
    // }
    // std::cout << '\n';

    // 770 to high
    // 768 -> right answer
    // 766 not correct
    // 765 not correct
    // 764 not correct
    // 763 to low
    // 762 to low

  }
}
