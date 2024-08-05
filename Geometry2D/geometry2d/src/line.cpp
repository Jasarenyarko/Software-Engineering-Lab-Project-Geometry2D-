#include "line.h"

Line::Line(Point start, Point end) : start_(start), end_(end)
{}



Point Line :: getStart()const
{
    return start_;
}

Point Line :: getEnd()const
{
    return end_;
}


Angle Line :: getDirection()const
{
    return createAngle(start_,end_);
}


double Line :: getLength()const
{
    return start_.distanceTo(end_);
}

void Line ::shiftParallel(Point point)
{
    Point direction = end_ - start_;
    start_ = point;
    end_ = start_ + direction;
}


Point Line :: getPerpendicularPoint(Point point) const
{
    double dx = end_.getX() - start_.getX();
    double dy = end_.getY() - start_.getY();

    double lineLengthSq = dx * dx + dy * dy;
    double skalarproduct = ((point.getX() - start_.getX()) * dx + (point.getY() - start_.getY()) * dy) / lineLengthSq;

    double perpendicularPointX = start_.getX() + skalarproduct * dx;
    double perpendicularPointY = start_.getY() + skalarproduct * dy;

    return {perpendicularPointX, perpendicularPointY};
}


Line createLine(Point start, Angle angle, double distance)
{
    return Line{start, start + createPoint(distance, angle)};
}






