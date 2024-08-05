#ifndef SEL_LINE_H
#define SEL_LINE_H

#include "angle.h"
#include "point.h"

class Point;
class Angle;

class Line
{
  private:
  Point start_;
  Point end_;


  public:
  Line (Point start, Point end);
  ~Line() = default;
  Point getStart()const;
  Point getEnd()const;
  Angle getDirection()const;
  double getLength()const;
  void shiftParallel(Point point);
  Point getPerpendicularPoint(Point point)const;

};
Line createLine(Point start, Angle angle, double distance);

#endif  // SEL_LINE_H

