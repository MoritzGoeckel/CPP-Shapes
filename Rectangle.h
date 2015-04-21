#ifndef RECTANGEHEADER
#define RECTANGEHEADER

#include "Printable.h"
#include "Vector.h"

#include "Circle.h"

class Circle;

class Rectangle : public Printable
{
    private:
        Vector position;
        Vector size;
    
    public:
        Rectangle(Vector position, Vector size);
        Rectangle();
        Vector getSize();
        Vector getPosition();
        bool containsPoint(Vector vector);
        std::string toString();
        bool fitsCircle(Circle* circle);
        bool intersectsCircle(Circle* circle);
        Vector getCenter();
};

#endif