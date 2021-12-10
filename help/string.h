#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <set>

void split_str( std::string const &str, const char delim, 
                std::vector<std::string> &out) {  
    // create a stream from the string  
    std::stringstream s(str);  
        
    std::string s2;  
    while (std::getline(s, s2, delim)) {  
        out.push_back(s2); // store the string in s2  
    }  
}  

bool sub_str( 
    const std::string str, 
    const char delim ,
    std::string &first, std::string &second ) {
        first.clear();
        second.clear();
        std::string::size_type n = str.find(delim);
        if (n == std::string::npos) {
            return false;
        }
        else {
            first = str.substr(0, n);
            second = str.substr(n+1);

            return true;
        }
}

std::set<std::string> checkStringToSet(std::string test) {
	std::set<std::string> set;
	for (int16_t index = 2; index < test.size(); index++) {
		if (test.at(index) == test.at(index-2) &&
			test.at(index) != test.at(index-1)) {
				set.insert( test.substr(index-2,2));
		}
	}
	return set;
}

bool checkString(std::string test) {
	for (int16_t index = 3; index < test.size(); index++) {
		if (test.at(index) == test.at(index-3) &&
			test.at(index-1) == test.at(index-2) &&
			test.at(index) != test.at(index-1)) {
				return true;
		}
	}
	return false;
}

bool find(std::string input, std::string pattern) {
	return input.find(pattern) != std::string::npos;
}

std::size_t replace_all(std::string& inout, std::string_view what, std::string_view with)
{
    std::size_t count{};
    for (std::string::size_type pos{};
         inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length(), ++count) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
    return count;
}
 
std::size_t remove_all(std::string& inout, std::string_view what) {
    return replace_all(inout, what, "");
}