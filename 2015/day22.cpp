#include "template.h"
#include <vector>

int main(void){
	DEBUG_LOG << "day22" << NL;
        std::vector<std::string> file = readFile("day22.data");
        for(auto line:file){
          std::cout << line << NL;
        }
	return 0;
}
