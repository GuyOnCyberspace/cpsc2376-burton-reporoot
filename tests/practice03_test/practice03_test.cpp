// practice03_test.cpp - Unit tests for practice03.cpp

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function
#include "catch.hpp"
#include "cpsc2376-burton-reporoot/practice/practice03/practice03.cpp"

TEST_CASE("sumRange computes correct sum", "[sumRange]") {
    REQUIRE(MathUtils::sumRange(1, 5) == 15); // 1+2+3+4+5
    REQUIRE(MathUtils::sumRange(3, 3) == 3);  // Single number case
    REQUIRE(MathUtils::sumRange(-2, 3) == 3); // -2 + -1 + 0 + 1 + 2 + 3
}

TEST_CASE("containsNegative detects negative numbers", "[containsNegative]") {
    REQUIRE(MathUtils::containsNegative({3, -1, 5, 7}) == true);
    REQUIRE(MathUtils::containsNegative({1, 2, 3, 4}) == false);
    REQUIRE(MathUtils::containsNegative({}) == false);
}

TEST_CASE("findMax finds the maximum value", "[findMax]") {
    REQUIRE(MathUtils::findMax({3, -1, 5, 7}) == 7);
    REQUIRE(MathUtils::findMax({-5, -2, -10}) == -2);
    REQUIRE(MathUtils::findMax({}) == 0);
}
