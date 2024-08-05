#include "geo_compare.h"

#include <cassert>
#include <cmath>
#include <iostream>

#include <gtest/gtest.h>

#include "angle.h"
#include "point.h"
#include "pose.h"

TEST(GeoComapreTest, isFuzzyEqual_point_expect_true)
{
    double epsilon = 0.00001;
    Point one{1.0, 3.0};
    Point two{1.000001, 3.000001};

    bool result = isFuzzyEqual(one, two, epsilon);

    EXPECT_TRUE(result);
}

TEST(GeoComapreTest, test_isFuzzyEqual_point_expect_false)
{
    double epsilon = 0.00001;
    Point one{1.00000, 1.00000};
    Point two{3.00000, 3.00000};

    bool result = isFuzzyEqual(one, two, epsilon);

    EXPECT_FALSE(result);
}

TEST(GeoComapreTest, test_isFuzzyEqual_angle_expect_true)
{
    double epsilon = 0.00001;
    Angle one{0.0};
    Angle two{2 * M_PI};

    bool result = isFuzzyEqual(one, two, epsilon);

    EXPECT_TRUE(result);
}

TEST(GeoComapreTest, test_isFuzzyEqual_angle_expect_false)
{
    double epsilon = 0.00001;
    Angle one{0.0};
    Angle two{M_PI};

    bool result = isFuzzyEqual(one, two, epsilon);

    EXPECT_FALSE(result);
}

TEST(GeoComapreTest, test_isFuzzyEqual_pose_expect_true)
{
    double epsilon = 0.00001;
    Pose one{1.0, 2.0, epsilon};
    Pose two{1.000001, 2.000001, epsilon};

    bool result = isFuzzyEqual(one, two, epsilon);

    EXPECT_TRUE(result);
}

TEST(GeoComapreTest, test_isFuzzyEqual_pose_expect_false)
{
    double epsilon = 0.00001;
    Pose one{1.0, 1.0, epsilon};
    Pose two{1.00005, 1.0005, epsilon};

    bool result = isFuzzyEqual(one, two, epsilon);

    EXPECT_FALSE(result);
}