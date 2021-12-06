#include "catch.hpp"

#include "help/bitwise.h"
#include <bitset>

TEST_CASE( "bitwise", "[bitwise]" ) {
    uint8_t a = 0;
    std::bitset<8> bitset;

    SECTION("setting bits") {
        //for (auto bit : {0,1,2,3,4,5,6,7}) {
	    for (uint8_t bit=0; bit<4; bit++) {
            bitset.set(bit);
            REQUIRE( BIT_SET(a, bit) == bitset.to_ulong() );
        }
    }
    SECTION("clearing bits") {
        //for (auto bit : {0,1,2,3,4,5,6,7}) {
        for (uint8_t bit=0; bit<4; bit++) {
            bitset.reset(bit);
            REQUIRE( BIT_CLEAR(a, bit) == bitset.to_ulong() );
        }
    }
}
