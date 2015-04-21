#ifndef QUADTREEITEMIMPLEMENTED
#define QUADTREEITEMIMPLEMENTED

#include "QuadtreeItem.h"

#include <list>
#include "QuadtreeArea.h"
#include "../Circle.h"
#include "../Vector.h"

Circle* QuadtreeItem::getCircle()
{
    return this->circle;
}

QuadtreeItem::QuadtreeItem(Circle circle, QuadtreeArea* parentArea)
{
    this->circle = new Circle(circle.getPosition(), circle.getSize());
    this->parentArea = parentArea;
}

void QuadtreeItem::setParentArea(QuadtreeArea* parentArea)
{
    this->parentArea = parentArea;
}

QuadtreeItem::~QuadtreeItem(){
    delete(this->circle);
    this->circle = 0;
}

void QuadtreeItem::setCircle(Circle circle){
    delete(this->circle);
    this->circle = new Circle(circle.getPosition(), circle.getSize());
}

void QuadtreeItem::notifyParentForPositionChanged()
{
    parentArea->onItemPositionChanged(this);
}

std::list<QuadtreeItem*>* QuadtreeItem::getPossibleNearItems(){
    return this->parentArea->getPossibleNearItems();
}

#endif