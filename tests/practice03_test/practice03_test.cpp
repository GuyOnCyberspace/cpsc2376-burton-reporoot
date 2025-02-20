// practice03_test.cpp - Unit tests for practice03.cpp

// practice03_test.cpp - Unit Tests for practice03.cpp using Catch2
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cpsc2376-burton-reporoot/practice/practice03/practice03.cpp"

TEST_CASE("sumRange computes correct sum", "[sumRange]") {
    REQUIRE(MathUtils::sumRange(1, 5) == 15);
    REQUIRE(MathUtils::sumRange(0, 0) == 0);
    REQUIRE(MathUtils::sumRange(-3, 3) == -3);
}

TEST_CASE("containsNegative correctly identifies negatives", "[containsNegative]") {
    REQUIRE(MathUtils::containsNegative({1, 2, 3}) == false);
    REQUIRE(MathUtils::containsNegative({-1, 2, 3}) == true);
    REQUIRE(MathUtils::containsNegative({}) == false);
}

TEST_CASE("findMax finds the maximum value", "[findMax]") {
    REQUIRE(MathUtils::findMax({3, -1, 5, 7}) == 7);
    REQUIRE(MathUtils::findMax({}) == INT_MIN);
    REQUIRE(MathUtils::findMax({4, 4, 4, 4}) == 4);
}

