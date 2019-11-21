#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "log.h"
#include <regex>

const auto input = "some people think regex is hard";
std::smatch sm;

int main(){
    INFO_LOG("regex");
    INFO_LOG(input);

    if( std::regex_match(input, sm, std::regex("(?)")) {
        const auto capture = sm[1].str();
    }

    return 0;
}
