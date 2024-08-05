#include "point.h"

#include <cmath>

#include "geo_compare.h"

Point :: Point(double x , double y) :x_(x),y_(y)
{}

double Point :: getX() const 
{
    return x_;
}

double Point :: getY() const 
{
    return y_;
}

bool Point :: operator==(Point other) const
{
    return isFuzzyEqual(x_, other.getX(), 0.00001) && isFuzzyEqual(y_, other.getY(), 00001);
}

Point Point :: operator+ (Point other) const
{
    return {x_ + other.getX(), y_ + other.getY()};
}

Point Point :: operator - (Point other) const 
{
    return {x_ - other.getX(), y_ - other.getY()};
}

Point Point ::operator * (double factor) const
{
    return {x_ * factor,y_* factor};
}

double Point :: getLength() const 
{
    return sqrt(x_ * x_ + y_ * y_);
}

double Point :: distanceTo(Point other) const
{
    Point difference (x_- other.getX(),y_ - other.getY());
    return difference.getLength();
}

Point Point :: rotate(Angle angle) const 
{
 double angleValue = angle.getValueBetweenMinusPiAndPi();
 return {x_ * cos(angleValue) - y_ * sin(angleValue),
                 x_ * sin(angleValue) + y_ * cos(angleValue)};
}


Point createPoint(double distance, Angle angle)
{
    return {distance * cos(angle.getValueBetweenMinusPiAndPi()),
                 distance * sin(angle.getValueBetweenMinusPiAndPi())};
}
