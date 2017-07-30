# What is that?
This is a C++ library for 2D geometry, shapes and collision detection. It supports circles, lines, rectangles and vectors. Additionaly it provides a 2D Quadtree implementation.

# Features
- Vector
- Rectangle
- Line
- Circle
- Quadtree
- Collision detection

# Usage
```cpp

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
```

# What is it good for?
I used this as an exercise to practice OOP C++. You can use it if it is any value for you, but me getting more familiar with C++ was the main purpose of this project.
