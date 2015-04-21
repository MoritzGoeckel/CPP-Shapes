#ifndef LINE
#define LINE

#include "Line.h"

#include "Vector.h"
#include "Printable.h"

Line::Line(Vector position,Vector direction) : Printable("Line")
{
    this->direction = direction;
    this->position = position;
}

std::string Line::toString()
{    
    return getStart().toString() + " To " + getEnd().toString();
}

Line Line::createLineBetweenPoints(Vector point_one, Vector point_two)
{
    Vector direction = point_two - point_one;
    Vector position = point_one;
    
    return Line(position, direction);
}

Vector Line::getClosestPoint(Vector point)
{
    double t = (point - position).scalarProduct(direction) / direction.scalarProduct(direction);
    
    if (t < 0)
        t = 0;
    
    if (t > 1)
        t = 1;

    return position + (direction * t);
}

double Line::getDistance(Vector point)
{
    return (point - getClosestPoint(point)).getLength();
}

Vector Line::getStart()
{
    return position;
}

Vector Line::getEnd()
{
    return position + direction;
}

#endif