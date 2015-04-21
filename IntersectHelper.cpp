#ifndef INTERSECTHELPER
#define INTERSECTHELPER

#include "IntersectHelper.h"

#include "Vector.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"

bool IntersectHelper::doVectorLineIntersect(Vector* v, Line* l){
    return (l->getDistance(*v) == 0);
}

bool IntersectHelper::doVectorRectangleIntersect(Vector* v, Rectangle* r){
    return r->containsPoint(*v);
}

bool IntersectHelper::doVectorCircleIntersect(Vector* v, Circle* c){
    return c->containsPoint(*v);
}

bool IntersectHelper::doRectangleCircleIntersect(Rectangle* r, Circle* c){
    return r->intersectsCircle(c);
}

bool IntersectHelper::doRectangleLineIntersect(Rectangle* r, Line* l){
    return r->containsPoint(l->getClosestPoint(r->getCenter()));
}

bool IntersectHelper::doCircleLineIntersect(Circle* c, Line* l){
    return c->containsPoint(l->getClosestPoint(c->getPosition()));
}

#endif