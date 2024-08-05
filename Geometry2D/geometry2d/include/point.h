#ifndef SEL_POINT_H
#define SEL_POINT_H


#include "angle.h"

class Angle;
class Point
{
private:
double x_;
double y_;


public:
Point(double x,double y);
~Point() = default;
bool operator == (Point other) const ;
double getX () const ;
double getY () const ;
Point operator + (Point other) const ;
Point operator - (Point other)  const ;
Point operator * (double factor) const;
double getLength() const ;
double distanceTo(Point other) const  ;
Point rotate(Angle angle) const;
};

Point createPoint(double distance, Angle angle);

#endif  // SEL_POINT_H
