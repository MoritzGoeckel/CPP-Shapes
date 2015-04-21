#ifndef CIRCLEHEADER
#define CIRCLEHEADER

#include "Printable.h"
#include "Vector.h"

class Circle : public Printable
{
    private:
        Vector position;
        double size;
    
    public:
        Circle(Vector position, double size);
        Circle();
        double getSize();
        Vector getPosition();
        bool containsPoint(Vector vector);
        bool intersectsCircle(Circle circle);
        std::string toString();
};

#endif