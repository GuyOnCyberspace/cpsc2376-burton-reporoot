// practice03_test.cpp - Unit tests for practice03.cpp

// practice03_test.cpp - Unit Tests for practice03.cpp using Catch2
#include "pch.h"
#include "CppUnitTest.h"
#include "cpsc2376-burton-reporoot/practice/practice03/practice03.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Practice03Tests
{
    TEST_CLASS(MathUtilsTests)
    {
    public:
        // Tests for sumRange
        TEST_METHOD(SumRange_StandardCase)
        {
            Assert::AreEqual(15, MathUtils::sumRange(1, 5)); // 1+2+3+4+5
        }

        TEST_METHOD(SumRange_ZeroRange)
        {
            Assert::AreEqual(0, MathUtils::sumRange(5, 5));
        }

        TEST_METHOD(SumRange_NegativeValues)
        {
            Assert::AreEqual(-10, MathUtils::sumRange(-4, -2)); // -4 + -3 + -2
        }

        // Tests for containsNegative
        TEST_METHOD(ContainsNegative_HasNegative)
        {
            std::vector<int> numbers = { 1, -2, 3 };
            Assert::IsTrue(MathUtils::containsNegative(numbers));
        }

        TEST_METHOD(ContainsNegative_AllPositive)
        {
            std::vector<int> numbers = { 1, 2, 3 };
            Assert::IsFalse(MathUtils::containsNegative(numbers));
        }

        TEST_METHOD(ContainsNegative_EmptyVector)
        {
            std::vector<int> numbers = {};
            Assert::IsFalse(MathUtils::containsNegative(numbers));
        }

        // Tests for findMax
        TEST_METHOD(FindMax_StandardCase)
        {
            std::vector<int> numbers = { 1, 5, 3 };
            Assert::AreEqual(5, MathUtils::findMax(numbers));
        }

        TEST_METHOD(FindMax_AllEqual)
        {
            std::vector<int> numbers = { 4, 4, 4 };
            Assert::AreEqual(4, MathUtils::findMax(numbers));
        }

        TEST_METHOD(FindMax_EmptyVector)
        {
            std::vector<int> numbers = {};
            try {
                MathUtils::findMax(numbers);
                Assert::Fail(L"Expected exception");
            }
            catch (const std::invalid_argument&) {
                Assert::IsTrue(true);
            }
        }
    };
}


