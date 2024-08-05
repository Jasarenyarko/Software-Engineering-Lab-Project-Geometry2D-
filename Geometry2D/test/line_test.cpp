#include "line.h"

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;

// LMT_SEL_BEGIN

TEST(LineTest, test_CreatLine_negx_posy)
{
    Point start = {-4, 9};
    Angle angle = {M_PI};
    double distance = 6;

    Line expected (Point(-4, 9), Point(-10, 9));

    Line result = createLine(start, angle, distance);

    EXPECT_EQ(expected.getStart().getX(), result.getStart().getX());
    EXPECT_EQ(expected.getStart().getY(), result.getStart().getY());
    EXPECT_EQ(expected.getEnd().getX(), result.getEnd().getX());
    EXPECT_EQ(expected.getEnd().getY(), result.getEnd().getY());
}

TEST(LineTest, test_CreatLine_posx_negy)
{
    Point start = {4, -9};
    Angle angle = {M_PI};
    double distance = 6;

    Line expected (Point(4, -9), Point(-2, -9));

    Line result = createLine(start, angle, distance);

   EXPECT_EQ(expected.getStart().getX(), result.getStart().getX());
   EXPECT_EQ(expected.getStart().getY(), result.getStart().getY());
   EXPECT_EQ(expected.getEnd().getX(), result.getEnd().getX());
   EXPECT_EQ(expected.getEnd().getY(), result.getEnd().getY());
}


TEST(LineTest, test_GetDirection)
{
    Line line (Point(3, -3), Point(-3, 3));

    Angle result = line.getDirection();

    Angle expected (2.356);

    EXPECT_NEAR(result.getValue(), expected.getValue(), 0.001);
}

TEST(LineTest, test_GetLengthLine)
{
    Line line (Point(0, 0), Point(4, -3));
    double expected = 5;
    double result = line.getLength();

    EXPECT_EQ(expected, result);
}

TEST(LineTest, test_ShiftParallel_negx_posy)
{

    Line line (Point(2, 3), Point(5, 4));

    Point point (-8, 12);

    line.shiftParallel(point);

    EXPECT_EQ(line.getStart().getX(), -8);
    EXPECT_EQ(line.getStart().getY(), 12);
    EXPECT_EQ(line.getEnd().getX(), -5);
    EXPECT_EQ(line.getEnd().getY(), 13);
}

TEST(LineTest, test_ShiftParallel_posx_negy)
{

    Line line (Point(2, 3), Point(5, 4));

    Point point (8, -12);

    line.shiftParallel(point);

    EXPECT_EQ(line.getStart().getX(), 8);
    EXPECT_EQ(line.getStart().getY(), -12);
    EXPECT_EQ(line.getEnd().getX(), 11);
    EXPECT_EQ(line.getEnd().getY(), -11);
}

TEST(LineTest, test_getPerpendicularPoint_horizontal)
{
    Line line (Point(0.0, 0.0), Point(5.0, 0.0));
    Point point (5.0, 3.0);

    Point pPoint = line.getPerpendicularPoint(point);
    Point expect (5.0, 0.0);

    EXPECT_EQ(pPoint.getX(), expect.getX());
    EXPECT_EQ(pPoint.getY(), expect.getY());
}

TEST(LineTest, test_getPerpendicularPoint_vertical)
{
    Line line (Point(5.0, 5.0), Point(5.0, 0.0));
    Point point (0.0, 7.0);

    Point pPoint = line.getPerpendicularPoint(point);
    Point expect (5.0, 7.0);

    EXPECT_EQ(pPoint.getX(), expect.getX());
    EXPECT_EQ(pPoint.getY(), expect.getY());
}
