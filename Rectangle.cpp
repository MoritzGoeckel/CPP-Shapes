#ifndef RECTANGLE
#define RECTANGLE

#include "Rectangle.h"

#include "Vector.h"
#include "Printable.h"

#include "Circle.h"

#include <iostream>

using namespace std;

Rectangle::Rectangle(Vector position, Vector size) : Printable("Rectangle")
{
    this->position = position;
    this->size = size;
}

Rectangle::Rectangle() : Printable("Rectangle")
{}

Vector Rectangle::getSize(){
    return this->size;
}

Vector Rectangle::getPosition(){
    return this->position;
}

//Tested
bool Rectangle::containsPoint(Vector vector)
{
    Vector other_corner = position + size;
    return (vector.x >= position.x && vector.y >= position.y && vector.x <= other_corner.x && vector.y <= other_corner.y);
}

string Rectangle::toString(){
    string s = "Position: ";
    s += getPosition().toString();
    s += " Size: ";
    s += getSize().toString();
    
    return s;
}

//Tested
bool Rectangle::intersectsCircle(Circle* circle)
{
    Vector cir_rec_len = (this->getCenter() - circle->getPosition()).getNormalized() * circle->getSize();
    Vector closest_point = circle->getPosition() + cir_rec_len;
    
    return this->containsPoint(closest_point);
}

//Tested
bool Rectangle::fitsCircle(Circle* circle)
{
    Vector rec_cir_len = (circle->getPosition() - this->getCenter()).getNormalized() * circle->getSize();
    Vector farest_point = circle->getPosition() + rec_cir_len;
    
    return this->containsPoint(farest_point);
}

//Tested
Vector Rectangle::getCenter(){
    return (this->getSize() / 2) + getPosition();
}

#endif