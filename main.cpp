#include <iostream>

#include "Vector.h"
#include "Line.h"
#include "Printable.h"
#include "Rectangle.h"
#include "Circle.h"

#include "Quadtree/QuadtreeArea.h"
#include "Quadtree/QuadtreeItem.h"

using namespace std;

int main()
{
    cout << "Starting..." << endl;
    
    QuadtreeArea* root = new QuadtreeArea(0, Rectangle(Vector(0,0), Vector(100, 100)));
    
    root->addItem(new QuadtreeItem(Circle(Vector(10, 40), 5), root));
    root->addItem(new QuadtreeItem(Circle(Vector(10, 80), 5), root));
    root->addItem(new QuadtreeItem(Circle(Vector(10, 30), 5), root));
    
    root->addItem(new QuadtreeItem(Circle(Vector(40, 40), 30), root));
    
    root->addItem(new QuadtreeItem(Circle(Vector(10, 10), 5), root));
    root->addItem(new QuadtreeItem(Circle(Vector(10, 10), 5), root));
    
    QuadtreeItem* item = new QuadtreeItem(Circle(Vector(10, 10), 5), root);
    root->addItem(item);
    
    root->print();
    
    std::list<QuadtreeItem*>* list = item->getPossibleNearItems();
    cout << list->size() << endl;
    delete(list);
    
    return 0;
}
