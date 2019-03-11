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

//Note that this solution does not skip empty tokens, so the following will find 4 items, one of which is empty:
int main(){
  std::vector<std::string> x = split("one:two:three", ':');

  std::cout << "x[0]=" << x[0] << '\n';
  std::cout << "x[1]=" << x[1] << '\n';

}
