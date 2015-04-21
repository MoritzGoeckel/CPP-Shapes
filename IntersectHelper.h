#ifndef INTERSECTHELPERHEADER
#define INTERSECTHELPERHEADER

class Vector;
class Circle;
class Rectangle;
class Line;

class IntersectHelper{
 
    public:
        static bool doVectorLineIntersect(Vector* v, Line* l);
        static bool doVectorRectangleIntersect(Vector* v, Rectangle* r);
        static bool doVectorCircleIntersect(Vector* v, Circle* c);
        
        static bool doRectangleCircleIntersect(Rectangle* r, Circle* c);
        static bool doRectangleLineIntersect(Rectangle* r, Line* l);
        
        static bool doCircleLineIntersect(Circle* c, Line* l);
};

#endif