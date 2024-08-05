#include "angle.h"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>

#include "geo_compare.h"
#include "pose.h"
using namespace std;

// LMT_SEL_BEGIN

TEST(AngleTest, fixAngleRange_less_thanPi_Pass)
{

    Angle angle(3);
    double expected = 3;
    double result = angle.fixAngleRange();

    EXPECT_NEAR(result, expected, 0.0001);
}

TEST(AngleTest, ConvertfromDegree_to_Radian_morethan180_Pass)

{
    Angle degree = 270;
    Angle expected = {M_PI * 1.5};
    Angle result = {degree.convertFromDegreeToRadiant()};

    EXPECT_DOUBLE_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, ConvertfromDegree_to_Radian_lessthan180_Pass)

{
    Angle degree (270);
    Angle expected = {M_PI * 1.5};
    Angle result = {degree.convertFromDegreeToRadiant()};

    EXPECT_DOUBLE_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, getHalfRotation_Pass)

{
    Angle expected (M_PI);
    Angle result = {getHalfRotation()};

    EXPECT_DOUBLE_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, getQuarterRotation_Pass)
{
    Angle expected (M_PI / 2);
    Angle result = getQuarterRotation();

    EXPECT_DOUBLE_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, getFullRotation_Pass)
{
    Angle expected (2 * M_PI);
    Angle result = getFullRotation();

    EXPECT_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, getEighthRotation_Pass)
{
    Angle expected (M_PI / 4);
    Angle result = getEighthRotation();

    EXPECT_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, GetValueBetweenMinusandPi_morethanPi_Pass)
{
    Angle anglevalue (7.8);
    double expected = {0.48267 * M_PI};
    double result = anglevalue.getValueBetweenMinusPiAndPi();

    EXPECT_NEAR(result, expected, 0.001);
}

TEST(AngleTest, GetValueBetweenMinusandPi_lessthanPi_Pass)
{
    Angle anglevalue (2.8);
    double expected = {2.8};
    double result = anglevalue.getValueBetweenMinusPiAndPi();

    EXPECT_NEAR(expected, result, 0.001);
}

TEST(AngleTest, GetValueBetweenZeroAnd2pi_lessthanPi_Pass)
{
    Angle anglevalue (-12.4);
    double expected = 0.1663;
    double result = anglevalue.getValueBetweenZeroAndTwoPi();

    EXPECT_NEAR(result, expected, 0.001);
}

TEST(AngleTest, GetValueBetweenZeroAnd2pi_morethanPi_Pass)
{
    Angle anglevalue (12.4);
    double expected = 6.11681;
    double result = anglevalue.getValueBetweenZeroAndTwoPi();

    EXPECT_NEAR(result, expected, 0.001);
}

TEST(AngleTest, test_MultiplyAngle_positive_factor_Pass)
{
    Angle angle (2.4);
    double factor = 4;
    Angle expected = {-2.96637};
    Angle result = angle * factor;

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(AngleTest, test_MultiplyAngle_negative_factor_Pass)
{
    Angle angle (2.4);
    double factor = -4;
    Angle expected = {2.96637};
    Angle result = angle * factor;

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(AngleTest, AddAngles_Pass)
{
    Angle angle1(12.45);
    Angle angle2(5.8);
    Angle expected(-0.5995);
    Angle result = angle1 + angle2;

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(AngleTest, SubtractAngles_Pass)
{
    Angle angle1 (12.45);
    Angle angle2 (5.8);

    Angle expected (0.3668);
    Angle result = angle1 - angle2;

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(AngleTest, CreateAngleWith2Points_Pass)
{
    Point start = {-4, 5};
    Point end = {3, -8};

    Angle expected (-1.0768);
    Angle result = createAngle(start, end);

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(AngleTest, isEqualAngle_True)
{
    Angle angle1 (M_PI);
    Angle angle2 (M_PI_4 * 4);

    bool result = angle1 == angle2;
    EXPECT_TRUE(result);
}

TEST(AngleTest, isEqualAngle_False)
{
    Angle angle1 (M_PI);
    Angle angle2 (M_PI_4 * 3);

    bool result = angle1 == angle2;
    EXPECT_FALSE(result);
}

TEST(AngleTest, IsObstuse_True)
{
    Angle angle (0.75 * M_PI);
    bool result = angle.isObtuse();

    EXPECT_TRUE(result);
}

TEST(AngleTest, IsObstuse_False)
{
    Angle angle (1.5 * M_PI);
    bool result = angle.isObtuse();

    EXPECT_FALSE(result);
}

TEST(AngleTest, abs_Pass)
{
    Angle angle(-M_PI);

    Angle expected(M_PI);
    Angle result = angle.abs();

    EXPECT_DOUBLE_EQ(expected.getValue(), result.getValue());
}

TEST(AngleTest, CreatAngleWithSourceAnd2target_Pass)
{
    Point source (0, 0);
    Point target1 (3, 2);
    Point target2 (4, 7);

    Angle expected (0.4636);
    Angle result = createAngle(source, target1, target2);

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(AngleTest, CreatAngleWithSourceAndSameTargets_Pass)
{
    Point source (0, 0);
    Point target1 (0, 0);
    Point target2 (0, 0);

    Angle expected (0);
    Angle result = createAngle(source, target1, target2);

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}
