#include "catch.hpp"

#include "help/bitwise.h"
#include <bitset>

TEST_CASE( "bitwise", "[bitwise]" ) {
    uint8_t a = 0;
    std::bitset<8> bitset;
    for (auto bit : {0,1,2,3,4,5,6,7}) {
        bitset.set(bit);
        REQUIRE( BIT_SET(a, bit) == bitset.to_ulong() );
    }
    for (auto bit : {0,1,2,3,4,5,6,7}) {
        bitset.reset(bit);
        REQUIRE( BIT_CLEAR(a, bit) == bitset.to_ulong() );
    }

}