#include <iostream>
#include <vector>

#define DEBUG_LOG std::cout << "file:" << __FILE__ << ':' << __LINE__ << ' '
#define NL '\n'
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> readFile(std::string filename);

