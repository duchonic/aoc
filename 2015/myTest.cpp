#include "template.h"
#include <vector>

int main(void){

  DEBUG_LOG << "myTest" << NL;

  std::vector<std::string> file = readFile("day14.data");

  for(auto line:file){
    std::cout << line << NL;
  }

  return 0;
}
