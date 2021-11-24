/**       _             _       _                                          _
   ___   | |_   __ _   | |_    (_)    ___   _ _            __     ___   __| |   ___    ___
  (_-<   |  _| / _` |  |  _|   | |   / _ \ | ' \     _    / _|   / _ \ / _` |  / -_)  (_-<
  /__/_  _\__| \__,_|  _\__|  _|_|_  \___/ |_||_|  _(_)_  \__|_  \___/ \__,_|  \___|  /__/_
_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""_|"""""|
"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-"`-0-0-'
*/

#include <iostream>
#include "help/help.h"
#include "help/math.h"
#include "help/bitwise.h"
#include "help/prime.h"
#include "help/geometry.h"
#include "help/string.h"

#include <string>

int main() {
  std::string a;
  while ( std::getline(std::cin, a)) {
    std::cout << a << std::endl;

    const char delim = '['; /* define the delimiter like space (' '), comma (,), hyphen (-), etc. */  

    std::vector <std::string> out; // store the string in vector  
    split_str (a, delim, out); // call function to split the string  
 
    // use range based for loop  
    for (const auto s: out) {  
        std::cout << " " << s;  
    } 
    std::cout << std::endl;
  }

  return 1;
}
