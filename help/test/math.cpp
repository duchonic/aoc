#include "catch.hpp"

#include "help/log.h"
#include "help/math.h"

TEST_CASE( "math", "[math]" ) {
	REQUIRE( add(3,5,44) == 8 );
	REQUIRE( add(3,5,4) == 4 );
}

TEST_CASE("median", "") {
    std::vector<int> v{1, 0, 5, 4, 3, 2, 6, 7, 9, 8};

    SECTION("median") {
        logvec(v);
        REQUIRE( median(v,0) == 0 );
        REQUIRE( median(v,1) == 1 );
        REQUIRE( median(v,2) == 2 );
        REQUIRE( median(v,3) == 3 ); 
        REQUIRE( median(v,4) == 4 );
        REQUIRE( median(v,5) == 5 );
        REQUIRE( median(v,6) == 6 );
        REQUIRE( median(v,7) == 7 );
        REQUIRE( median(v,8) == 8 );
        REQUIRE( median(v,9) == 9 );

        REQUIRE( median(v) == 5 );
    }


    // Note: comp function changed
    logvec(v);
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater{});
    std::cout << "The largest element is " << v[0] 
            << " The second largest element is " << v[1] << '\n';
    logvec(v);
}
