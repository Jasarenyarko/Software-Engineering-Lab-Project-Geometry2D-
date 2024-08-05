#include "pose.h"

#include <cassert>
#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

#include "geo_compare.h"

TEST(PoseTest, test_distanceTo_expect_sqrt8)
{
    Pose one{0.0, 0.0};
    Pose two{2.0, 2.0};
    double result = distanceTo(one, two);
    double expected = sqrt(8);

    EXPECT_EQ(result, expected);
}

TEST(PoseTest, test_distanceTo_expect_5)
{
    Pose one{0.0, 0.0};
    Pose two{4.0, 3.0};
    double result = distanceTo(one, two);
    double expected = 5;

    EXPECT_EQ(result, expected);
}

TEST(PoseTest, test_getRelativeOrientationTo_expect_PI4)
{
    Pose source{0.0, 0.0};
    Point point{5.0, 5.0};
    Angle result = getRelativeOrientationTo(source, point);
    Angle expected = {M_PI_4};

    EXPECT_EQ(result.value, expected.value);
}

TEST(PoseTest, test_getRelativeOrientationTo_expect_PI2)
{
    Pose source{0.0, 0.0};
    Point point{5.0, 0.0};
    Angle result = getRelativeOrientationTo(source, point);
    Angle expected = {0};

    EXPECT_EQ(result.value, expected.value);
}

TEST(PoseTest, test_isEqual_expect_true)
{
    Pose one{0.0, 0.0};
    Pose two{0.000001, 0.000001};
    bool result = isEqual(one, two);

    EXPECT_TRUE(result);
}

TEST(PoseTest, test_isEqual_expect_false)
{
    Pose one{0.0, 0.0};
    Pose two{0.00005, 0.00005};
    bool result = isEqual(one, two);

    EXPECT_FALSE(result);
}

TEST(PoseTest, test_addPoses_expect_3_3)
{
    Pose one{Point{1.0, 1.0}, Angle{M_PI_4}};
    Pose two{Point{2.0, 2.0}, Angle{M_PI_4}};
    Pose result = addPoses(one, two);
    Pose expected = {Point{3.0, 3.0}, Angle{M_PI_2}};

    EXPECT_EQ(result.position.x, expected.position.x);
    EXPECT_EQ(result.position.y, expected.position.y);
    EXPECT_EQ(result.orientation.value, expected.orientation.value);
}

TEST(PoseTest, test_addPoses_expect_6_3_5)
{
    Pose one{Point{4.0, 1.5}, Angle{M_PI_4}};
    Pose two{Point{2.0, 2.0}, Angle{M_PI_4}};
    Pose result = addPoses(one, two);
    Pose expected = {Point{6.0, 3.5}, Angle{0.5 * M_PI}};

    EXPECT_EQ(result.position.x, expected.position.x);
    EXPECT_EQ(result.position.y, expected.position.y);
    EXPECT_EQ(result.orientation.value, expected.orientation.value);
}

TEST(PoseTest, test_subtractPoses_expect_1_1)
{
    Pose one{{3.0, 3.0}, M_PI};
    Pose two{{2.0, 2.0}, M_PI};
    Pose result = subtractPoses(one, two);
    Pose expected{Point{1.0, 1.0}, Angle{0}};

    EXPECT_EQ(result.position.x, expected.position.x);
    EXPECT_EQ(result.position.y, expected.position.y);
    EXPECT_EQ(result.orientation.value, expected.orientation.value);
}

TEST(PoseTest, test_subtractPoses_expect_minuspoint5_2)
{
    Pose one{{1.5, 4.0}, M_PI};
    Pose two{{2.0, 2.0}, M_PI};
    Pose result = subtractPoses(one, two);
    Pose expected{Point{-0.5, 2.0}, Angle{0}};

    EXPECT_EQ(result.position.x, expected.position.x);
    EXPECT_EQ(result.position.y, expected.position.y);
    EXPECT_EQ(result.orientation.value, expected.orientation.value);
}