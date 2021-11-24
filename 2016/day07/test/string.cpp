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

