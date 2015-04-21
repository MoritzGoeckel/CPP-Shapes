#ifndef QUADTREEAREAHEADER
#define QUADTREEAREAHEADER

#include <list>
#include <string>

#include "../Vector.h"
#include "../Rectangle.h"

class Rectangle;
class QuadtreeItem;

class QuadtreeArea{
    
    public:
        QuadtreeArea(QuadtreeArea* parent, Rectangle rect);    
        ~QuadtreeArea();
    
        void addItem(QuadtreeItem* item);
        bool removeItem(QuadtreeItem* item);
    
        void splitArea();
        void mergeArea();
    
        int getItemsCount();
    
        bool isLeaf();
    
        bool canStoreItem(QuadtreeItem* item);
    
        void onItemPositionChanged(QuadtreeItem* item);
    
        void print(std::string prefix);
        void print();
        
        std::list<QuadtreeItem*>* getPossibleNearItems();
    
    private:
        bool containsItem(QuadtreeItem* item);
        QuadtreeArea* parent;
    
        Rectangle rectangle;
        QuadtreeArea* parentArea = 0; 
            
        std::list<QuadtreeItem*>* items;
        std::list<QuadtreeArea*>* areas;
    
        static int MAX_ITEMS;  
};

#endif