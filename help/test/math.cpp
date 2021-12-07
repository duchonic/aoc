#include "catch.hpp"

#include "help/log.h"
#include "help/math.h"

TEST_CASE( "math", "[math]" ) {
	REQUIRE( add(3,5,44) == 8 );
	REQUIRE( add(3,5,4) == 4 );
}

TEST_CASE("median", "") {
	std::vector<int> test{1,2,3};
	logvec(test);
	REQUIRE( median(test) == 2 );
	test.push_back(1);
	REQUIRE( median(test) == 2 );
	test.push_back(1);
	REQUIRE( median(test) == 1 );

	
}
