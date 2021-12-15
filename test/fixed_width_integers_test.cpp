#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "fixed_width_integers/fixed_width_integers.hpp"

TEST_CASE("Sizes") {
    SUBCASE("8 bits") {
        REQUIRE(sizeof(nonstd::int8_t) == 1);
        REQUIRE(sizeof(nonstd::uint8_t) == 1);
    }

    SUBCASE("16 bits") {
        REQUIRE(sizeof(nonstd::int16_t) == 2);
        REQUIRE(sizeof(nonstd::uint16_t) == 2);
    }

    SUBCASE("32 bits") {
        REQUIRE(sizeof(nonstd::int32_t) == 4);
        REQUIRE(sizeof(nonstd::uint32_t) == 4);
    }

    SUBCASE("64 bits") {
        REQUIRE(sizeof(nonstd::int64_t) == 8);
        REQUIRE(sizeof(nonstd::uint64_t) == 8);
    }

    SUBCASE("ptr_t") {
        REQUIRE(sizeof(nonstd::intptr_t) == static_cast<int>(sizeof(void*)));
        REQUIRE(sizeof(nonstd::uintptr_t) == static_cast<int>(sizeof(void*)));
    }
}