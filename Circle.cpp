#ifndef CIRCLE
#define CIRCLE

#include "Circle.h"

#include "Vector.h"
#include "Printable.h"

using namespace std;

Circle::Circle(Vector position, double size) : Printable("Circle")
{
    this->position = position;
    this->size = size;
}

Circle::Circle() : Printable("Circle")
{
    this->position = Vector(0,0);
    this->size = 0;
}

double Circle::getSize(){
    return this->size;
}

Vector Circle::getPosition(){
    return this->position;
}

bool Circle::containsPoint(Vector vector)
{
    return ((position - vector).getLength() <= size);
}

bool Circle::intersectsCircle(Circle circle)
{
    double abstand = (circle.getPosition() - this->getPosition()).getLength();
    return abstand > (this->getSize() + circle.getSize());
}

string Circle::toString(){
    string s = "Position: ";
    s += getPosition().toString();
    s += " Size: ";
    s += std::to_string(getSize());
    
    return s;
}

#endif