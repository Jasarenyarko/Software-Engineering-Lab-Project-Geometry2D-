#include "angle.h"

#include <cmath>

#include "geo_compare.h"
#include "point.h"

Angle :: Angle(double value ) : value_(value)
{}



double Angle :: getValue() const 
{
    return value_;
}

double Angle :: getValueBetweenMinusPiAndPi()
{
     return fixAngleRange();
}

double Angle :: getValueBetweenZeroAndTwoPi()
{
    value_ = fixAngleRange();
    return value_ < 0 ? value_ + 2 * M_PI : value_;
}

bool Angle::isObtuse()
{
  return fabs(getValueBetweenMinusPiAndPi()) > M_PI_2;
}


double Angle :: abs()
{
    return fabs(getValueBetweenMinusPiAndPi());
}

double Angle :: fixAngleRange()
{
     while (value_ <= M_PI)
    {
        value_ += 2 * M_PI;
    }

    value_ -= 2 * M_PI * static_cast<unsigned int>(value_ / (2 * M_PI));

    return value_ > M_PI ? value_ - 2 * M_PI : value_;

}

Angle  Angle ::  operator + (Angle other) 
{
Angle add(getValueBetweenMinusPiAndPi() + other.getValueBetweenMinusPiAndPi());
 return {add.fixAngleRange()};
}

Angle  Angle ::  operator - (Angle other) 
{
Angle sub(getValueBetweenMinusPiAndPi() + other.getValueBetweenMinusPiAndPi());
 return {sub.fixAngleRange()};
}

Angle  Angle ::  operator * (double factor) 
{

 Angle multiply = getValueBetweenMinusPiAndPi() * factor;
 return {multiply.fixAngleRange()};
}


bool Angle :: operator == (Angle other) 
{
 return isFuzzyEqual(getValueBetweenMinusPiAndPi(), other.getValueBetweenMinusPiAndPi(), 0.00001) ||
           isFuzzyEqual(getValueBetweenZeroAndTwoPi(), other.getValueBetweenZeroAndTwoPi(), 0.0001);
}


Angle createAngle(Point start, Point end)
{
    Point positionDifference = start - end;
    Angle newAngle(atan2(positionDifference.getY(), positionDifference.getX()));
    return newAngle.fixAngleRange();
}

Angle createAngle(Point source, Point targetOne, Point targetTwo)
{
    if (!isFuzzyEqual(source.distanceTo(targetOne), 0, 0.001) &&
        !isFuzzyEqual(source.distanceTo(targetTwo), 0, 0.001))
    {
        Angle angle1 = createAngle(source, targetOne);
        Angle angle2 = createAngle(source, targetTwo);
        return (angle1-angle2).abs();
    }
    return {0};
}


Angle getHalfRotation()
{
    return {M_PI};
}

Angle  getQuarterRotation()
{
    return {M_PI_2};
}

Angle getFullRotation()
{
    return {2 * M_PI};
}

Angle getEighthRotation()
{
    return {M_PI_4};
}


Angle Angle::convertFromDegreeToRadiant() const 
{
    return {value_ / 180 * M_PI};
}
