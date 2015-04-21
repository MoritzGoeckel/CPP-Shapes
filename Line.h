#ifndef LINEHEADER
#define LINEHEADER

#include "Printable.h"
#include "Vector.h"

class Line : public Printable
{
    private:
        Vector direction;
        Vector position;

    public:
        Line(Vector position,Vector direction);
    
        std::string toString();
    
        static Line createLineBetweenPoints(Vector point_one, Vector point_two);
        Vector getClosestPoint(Vector point);
        double getDistance(Vector point);
        Vector getStart();
        Vector getEnd();
};

#endif