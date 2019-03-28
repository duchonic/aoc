#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::cout << "split function" << '\n';
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
        std::cout << "item:" << item << '\n';
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::cout << "split with vector return" << '\n';
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main(){
  std::vector<std::string> x = split("one:two:three", ':');

  std::chrono::milliseconds test = 12;

  int time_ms = 30;
  int time_sec = 33;

  std::cout << "x[0]=" << x[0] << '\n';
  std::cout << "x[1]=" << x[1] << '\n';
  std::cout << "time_ms: " <<  time_ms << " time_sec: " << time_sec << '\n';
}
