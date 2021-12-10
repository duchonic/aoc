#include <stdio.h>
#include <curl/curl.h>
#include <iostream>

#include <vector>
#include "matplot/matplot.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"



bool isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void plotter(std::vector<double> x, std::vector<double> y) {
    using namespace matplot;
	plot(x, y);
    show();
	while(true) ;
}

/*
void split_str( std::string const &str, const char delim, 
                std::vector<std::string> &out) {  
    // create a stream from the string  
    std::stringstream s(str);  
        
    std::string s2;  
    while (std::getline(s, s2, delim)) {  
        out.push_back(s2); // store the string in s2  
    }  
}  
*/

int main(void) {
    std::vector<double> x{};
    std::vector<double> y{};

    std::vector<std::string> data = readstuff();

    for (auto line : data) {
        std::vector<std::string> input;
        split_str(line, ' ', &input); 
        if (isNumber(input.at(1))) {
            logger(input.at(1));
            x.push_back( std::stoi(input.at(1)));
            y.push_back( 1 );
        }
    }

    plotter(x,y);
  return 0;
}
