#include "catch.hpp"

#include "help/bitwise.h"
#include <bitset>

TEST_CASE( "bitwise", "[bitwise]" ) {
    uint64_t a = 0;
    std::bitset<64> bitset;

    SECTION("setting bits") {
        //for (auto bit : {0,1,2,3,4,5,6,7}) {
	for (uint8_t bit=0; bit<64; bit++) {
            bitset.set(bit);
            REQUIRE( BIT_SET(a, bit) == bitset.to_ulong() );
        }
    }
    //for (auto bit : {0,1,2,3,4,5,6,7}) {
    for (uint8_t bit=0; bit<64; bit++) {
        bitset.reset(bit);
        REQUIRE( BIT_CLEAR(a, bit) == bitset.to_ulong() );
    }

}
