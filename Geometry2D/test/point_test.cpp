#include "point.h"

#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

#include "geo_compare.h"

using namespace std;

#include <cassert>
#include <cstdlib>

TEST(PointTest, CreatePoint_morethanPi_Pass)
{
    double distance = 5;
    Angle angle = {M_PI * 2};
    Point expected = {5, 0};

    Point result = {createPoint(distance, angle)};

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, CreatePoint_lessthanPi_Pass)
{
    double distance = 7;
    Angle angle = {M_PI / 2};
    Point expected = {0, 7};

    Point result = {createPoint(distance, angle)};

    EXPECT_NEAR(expected.getX(), result.getX(), 0.0000001);
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, EqualPoint_True)
{
    Point point1 = {3, -4};
    Point point2 = {3, -4};
    const bool result = point1 == point2;
    EXPECT_TRUE(result);
}

TEST(PointTest, EqualPoint_False)
{
    Point point1 = {3, -4};
    Point point2 = {-3, -4};
    const bool result = point1 == point2;;
    EXPECT_FALSE(result);
}

TEST(PointTest, GetLength_posx_negy_Pass)
{
    Point point = {4, -3};
    double expected = 5;
    EXPECT_EQ(expected, point.getLength());
}

TEST(PointTest, GetLength_negx_posy_Pass)
{
    Point point = {-4, 3};
    double expected = 5;
    EXPECT_EQ(expected, point.getLength());
}

TEST(PointTest, DistanceTo_Pass)
{
    Point point1 = {6, 7};
    Point point2 = {-8, 9};
    double expected = 14.142;
    double result = point1.distanceTo(point2);

    EXPECT_NEAR(expected, result, 0.001);
}

TEST(PointTest, SubtractPoints_Pass)
{
    Point point1 = {-3, 8};
    Point point2 = {5, -2};
    Point expected = {-8, 10};
    Point result = point1 - point2;

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, AddPoints_Pass)
{
    Point point1 = {-3, 8};
    Point point2 = {5, -2};
    Point expected = {2, 6};
    Point result = point1 + point2;

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, MultiplyPoint_neg_factor_Pass)
{
    Point point = {4, -5};
    Point expected = {-12, 15};
    Point result = point * -3;

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, MultiplyPoint_pos_factor_Pass)
{
    Point point = {4, -5};
    Point expected = {16, -20};
    Point result = point * 4;

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, Rotate_morethanPi_Pass)
{
    Point point = {4, 5};
    Angle angle = {M_PI * 2};

    Point expected = {4, 5};
    Point result = point.rotate(angle);

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}

TEST(PointTest, Rotate_lessThanPi_Pass)
{
    Point point = {4, 5};
    Angle angle = {M_PI / 2};

    Point expected = {-5, 4};
    Point result = point.rotate(angle);

    EXPECT_EQ(expected.getX(), result.getX());
    EXPECT_EQ(expected.getY(), result.getY());
}
