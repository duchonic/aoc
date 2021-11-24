#include "catch.hpp"

#include "help/math.h"

TEST_CASE( "math", "[math]" ) {
	REQUIRE( add(3,5,44) == 8 );
	REQUIRE( add(3,5,4) == 4 );
}
