#ifndef VECTORHEADER
#define VECTORHEADER

#include <math.h>

#include "Printable.h"
#include "Vector.h"

class Vector : public Printable
{
    public:    
        double x;
        double y;
    
        Vector();
        Vector(double x, double y);
    
        std::string toString();
    
        bool operator== (const Vector other);
        bool operator!= (const Vector other);
        Vector operator+ (const Vector other);
        Vector operator- (const Vector other);
        Vector operator* (double scalar);
        Vector operator/ (double scalar);
        double getLength();
        Vector getNormal();
        Vector getNormalized();
        double scalarProduct(Vector other);
        bool isOrthogonal(Vector other);
};

#endif