#include "catch.hpp"

#include "help/string.h"

TEST_CASE( "substring" ) {
    std::string test{"first,second"};
    std::string first, second;
	REQUIRE( sub_str(test, ',', first, second) == true );
	REQUIRE( first.compare("first") == 0 );
	REQUIRE_FALSE( first.compare("fist") == 0);
    REQUIRE( second.compare("second") == 0 );
    REQUIRE_FALSE( second.compare("secondo") == 0 );
	REQUIRE( sub_str(test, ',', first, second) == true );
	REQUIRE( first.compare("first") == 0 );
	REQUIRE_FALSE( first.compare("fist") == 0);
    REQUIRE( second.compare("second") == 0 );
    REQUIRE_FALSE( second.compare("secondo") == 0 );
	REQUIRE( sub_str(test, ':', first, second) == false );
	REQUIRE_FALSE( first.compare("first") == 0 );
    REQUIRE_FALSE( second.compare("second") == 0 );
}

TEST_CASE( "splitstring" ) {
    std::vector<std::string> out;
    std::string test{"first,second,third"};
    split_str(test, ',', out);

    REQUIRE(out.at(0).compare("first") == 0);
    REQUIRE(out.at(1).compare("second") == 0);
    REQUIRE(out.at(2).compare("third") == 0);
    REQUIRE_FALSE(out.at(2).compare("first") == 0);

}

TEST_CASE("check string") {
    std::string input{"kdkd llll"};
    REQUIRE( checkString(input) == false);
    input.append(" abba");
    REQUIRE( checkString(input) == true);
}

TEST_CASE("check string to set") {
    std::string input{"aaa bbb lll"};
    REQUIRE( checkStringToSet(input).size() == 0);
    input.append(" cac");
    REQUIRE( checkStringToSet(input).size() == 1);
    std::set<std::string> test = checkStringToSet(input);
    auto search = test.find("ab");
    REQUIRE (search == test.end() ); 
    input.append(" bab");
    REQUIRE( checkStringToSet(input).size() == 2);
    test = checkStringToSet(input);
    search = test.find("ba");
    REQUIRE (search != test.end() ); 

}

