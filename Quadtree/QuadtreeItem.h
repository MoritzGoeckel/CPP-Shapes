#ifndef QUADTREEITEM
#define QUADTREEITEM

#include <string>
#include <list>

#include "../Vector.h"
#include "../Circle.h"

class QuadtreeArea;

class QuadtreeItem{
    private:
        Circle* circle;
        QuadtreeArea* parentArea;
    
    public:
        QuadtreeItem(Circle circle, QuadtreeArea* parentArea);
        ~QuadtreeItem();
        Circle* getCircle();
        void setCircle(Circle circle);
        void setParentArea(QuadtreeArea* parentArea);
        void notifyParentForPositionChanged();
        std::list<QuadtreeItem*>* getPossibleNearItems();
};

#endif