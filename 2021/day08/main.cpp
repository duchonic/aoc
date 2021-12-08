/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'




 0:      1:      2:      3:      4:
 aaaa    ....    aaaa    aaaa    ....
b    c  .    1  .    c  .    c  4    1
b    c  .    c  .    c  .    c  b    c
 ....    ....    dddd    dddd    5ddd
e    f  .    2  e    .  .    f  .    2
e    f  .    f  e    .  .    f  .    f
 gggg    ....    gggg    gggg    ....

  5:      6:      7:      8:      9:
 aaaa    aaaa    3aaa    3aaa    aaaa
b    .  b    .  .    1  4    1  b    c
b    .  b    .  .    c  b    c  b    c
 dddd    dddd    ....    5ddd    dddd
.    f  e    f  .    2  7    2  .    f
.    f  e    f  .    f  e    f  .    f
 gggg    gggg    ....    6ggg    gggg

0 abc efg 6 digits
1   c  f  2 digits
2 a cde g 5 digits
3 a cd fg 5 digits
4  bcd f  4 digits
5 ab d fg 5 digits
6 ab defg 6 digits
7 a c  f  3 digits
8 abcdefg 7 digits
9 abcd fg 6 digits
                    common with 
                    1       7       4
1   c  f  2 digits
7 a c  f  3 digits  
4  bcd f  4 digits  
3 a cd fg 5 digits  cf      acf     df
2 a cde g 5 digits  c       ac      cd 
5 ab d fg 5 digits  f       af      bdf
6 ab defg 6 digits  f       af      bdf
0 abc efg 6 digits  cf      acf     bcf
9 abcd fg 6 digits  cf      acf     bcdf
8 abcdefg 7 digits  cf      acf     bcdf

*/

#include "help/help.h"
#include "help/math.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"
#include "help/file.h"
#include "help/log.h"
#include "help/string.h"

void match1(){

}

int main() {
    std::vector<std::pair< std::array<std::string,10>,std::array<std::string,4> >> data 
            = readstuffdigits();

	int16_t part1 = 0;
	int16_t part2 = 0;

    for (auto &entry : data) {
        auto checksize = [](std::string a, std::string b){return a.size()<b.size();};
        std::sort(entry.first.begin(), entry.first.end(), checksize);
        std::sort(entry.second.begin(), entry.second.end(), checksize);
        
        for (auto &nr : entry.first) {
            std::sort(nr.begin(), nr.end());
            std::cout << nr << ' ';
        }       
        std::cout << "| ";
        for (auto &nr : entry.second) {
            std::sort(nr.begin(), nr.end());
            std::cout << nr << ' ';
        }

        for (std::string check : entry.first ){
            for (std::string test : entry.second) {
                //logger(check << " . " << test);
                if (check.compare(test) == 0) {
                    std::cout << " 1";
                    part1++;
                }
            }            
        }

        std::cout << std::endl;
    }



	std::cout << "part1 : " << part1 << std::endl;
	std::cout << "part2 : " << part2 << std::endl;

	return 0;
}
