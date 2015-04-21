#ifndef VECTOR
#define VECTOR

#include "Vector.h"

#include <math.h>

#include "Printable.h"

Vector::Vector(double x, double y) : Printable ("Vector")
{
    this->x = x;
    this->y = y;
}

Vector::Vector() : Printable ("Vector")
{
    this->x = 0;
    this->y = 0;
}

std::string Vector::toString()
{    
    std::string s = "X";
    s += std::to_string(x);
    s += " Y";
    s += std::to_string(y);
    s += " |";
    s += std::to_string(getLength());
    s += "|";
    
    return s;
}

bool Vector::operator== (const Vector other){
    if(other.x == x && other.y == y)
        return true;
    else
        return false;
}

bool Vector::operator!= (const Vector other){
    if(other.x != x || other.y != y)
        return true;
    else
        return false;
}

Vector Vector::operator+ (const Vector other)
{
    return Vector(x + other.x, y + other.y);
}

Vector Vector::operator- (const Vector other)
{
    return Vector(x - other.x, y - other.y);
}

Vector Vector::operator* (double scalar)
{
    return Vector(x * scalar, y * scalar);
}

Vector Vector::operator/ (double scalar){
    return Vector(x / scalar, y / scalar);
}

double Vector::getLength()
{
    return sqrt(pow (x, 2) + pow (y, 2));
}

Vector Vector::getNormal()
{
    return Vector(y, -x);
}

Vector Vector::getNormalized()
{
    if(getLength() == 0)
        return Vector(0, 0);
    
    return Vector(x / getLength(), y / getLength());
}

double Vector::scalarProduct(Vector other)
{
    return other.x * x + other.y * y;
}

bool Vector::isOrthogonal(Vector other)
{
    return scalarProduct(other) == 0;
}

#endif