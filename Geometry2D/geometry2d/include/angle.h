#ifndef SEL_ANGLE_H
#define SEL_ANGLE_H

#include "point.h"

class Point;

class Angle
{
  private:
  double value_;

  public:
  Angle(double value);
  ~Angle() = default;
  double getValue() const;
  double getValueBetweenMinusPiAndPi();
  double getValueBetweenZeroAndTwoPi();
  bool isObtuse();
  double abs();
  double fixAngleRange( );
  Angle operator + (Angle other) ;
  Angle operator - (Angle other);
  Angle operator * (double factor);
  bool operator == (Angle other);
  Angle convertFromDegreeToRadiant() const;
};

Angle createAngle(Point start, Point end);
Angle createAngle(Point source, Point targetOne, Point targetTwo);
Angle getHalfRotation();
Angle getFullRotation();
Angle getEighthRotation();
Angle getQuarterRotation();

#endif  // SEL_ANGLE_H
