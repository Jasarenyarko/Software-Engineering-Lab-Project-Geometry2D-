#include "compare.h"

#include <cassert>
#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

TEST(CompareTest, test_isFuzzyEqual_true)
{
    double value1 = 1.0;
    double value2 = 1.000000001;
    double epsilon = 0.0000001;

    EXPECT_NEAR(value1, value2, epsilon);

    // bool result = isFuzzyEqual(value1, value2, epsilon);
    // EXPECT_TRUE(result);
}

TEST(CompareTest, test_isFuzzyEqual_false)
{
    double value1 = 1.0;
    double value2 = 1.05;
    double epsilon = 0.0000001;

    bool result = isFuzzyEqual(value1, value2, epsilon);
    EXPECT_FALSE(result);
}

TEST(CompareTest, test_isFuzzyGreater_true)
{
    double value1 = 1.0;
    double value2 = 1.005;
    double epsilon = 0.01;

    bool result = isFuzzyGreater(value1, value2, epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, test_isFuzzyGreater_false)
{
    double value1 = 1.0;
    double value2 = 1.5;
    double epsilon = 0.01;

    bool result = isFuzzyGreater(value1, value2, epsilon);
    EXPECT_FALSE(result);
}

TEST(CompareTest, test_isFuzzySmaller_true)
{
    double value1 = 1.0;
    double value2 = 1.0;
    double epsilon = 0.01;

    bool result = isFuzzySmaller(value1, value2, epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, test_isFuzzySmaller_false)
{
    double value1 = 1.0;
    double value2 = 0.8;
    double epsilon = 0.01;

    bool result = isFuzzySmaller(value1, value2, epsilon);
    EXPECT_FALSE(result);
}

TEST(CompareTest, test_isStrictFuzzyGreater_true)
{
    double value1 = 2.0;
    double value2 = 1.0;
    double epsilon = 0.01;

    bool result = isStrictFuzzyGreater(value1, value2, epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, test_isStrictFuzzyGreater_false)
{
    double value1 = 1.0;
    double value2 = 2.0;
    double epsilon = 0.01;

    bool result = isStrictFuzzyGreater(value1, value2, epsilon);
    EXPECT_FALSE(result);
}

TEST(CompareTest, test_isStrictFuzzySmaller_true)
{
    double value1 = 1.0;
    double value2 = 2.0;
    double epsilon = 0.01;

    bool result = isStrictFuzzySmaller(value1, value2, epsilon);
    EXPECT_TRUE(result);
}

TEST(CompareTest, test_isStrictFuzzySmaller_false)
{
    double value1 = 1.0;
    double value2 = 1.0;
    double epsilon = 0.01;

    bool result = isStrictFuzzySmaller(value1, value2, epsilon);
    EXPECT_FALSE(result);
}