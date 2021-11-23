#include "catch.hpp"

#include "help/geometry.h"

TEST_CASE( "geometry") {
    REQUIRE( Cube(1) == 1);
    REQUIRE( Cube(2) == 8);
}