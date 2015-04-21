#ifndef QUADTREEAREA
#define QUADTREEAREA

#include "QuadtreeArea.h"

#include <iostream>
#include <list>

#include "../Vector.h"
#include "../Rectangle.h"
#include "QuadtreeItem.h"

int QuadtreeArea::MAX_ITEMS = 5;  

QuadtreeArea::QuadtreeArea(QuadtreeArea* parent, Rectangle rect){
    this->parent = parent;
    this->rectangle = rect;
    
    items = new std::list<QuadtreeItem*>();
    areas = new std::list<QuadtreeArea*>();
}

QuadtreeArea::~QuadtreeArea(){
    //Todo: Remove the lists etc
    delete(items);
    delete(areas);
    items = 0;
    areas = 0;
}

//Tested
void QuadtreeArea::addItem(QuadtreeItem* item){
    //If not possible to hold, add it to the parent
    if(this->canStoreItem(item) == false)
    {
        if(parent != 0)
            parent->addItem(item);
        else
        {
            //This is root and cant store item.
            //Exception. Item can't be added.
            std::cout << "!! Can not add item !!" << std::endl << std::endl;
        }
    }
    else
    {
        item->setParentArea(this);
        
        if(isLeaf())
        {
            //Add to Items
            items->push_back(item);
        }
        else
        {
            //Add to suitable child Area
            bool stored = false;
            for (std::list<QuadtreeArea*>::iterator areaIterator = areas->begin(); areaIterator != areas->end(); ++areaIterator)
            { 
                if((*areaIterator)->canStoreItem(item))
                {
                    (*areaIterator)->addItem(item);
                    stored = true;
                    break;
                }
            }
            
            //Does not fit in childs
            if(stored == false)
                items->push_back(item);
        }
        
        //Split if to full
        if(isLeaf() && items->size() == MAX_ITEMS)
           splitArea();
    }
}

bool QuadtreeArea::containsItem(QuadtreeItem* item)
{   
    for (std::list<QuadtreeItem*>::iterator iterator = items->begin(); iterator != items->end(); ++iterator)
    { 
        if(*iterator == item)
        {
            return true;
        }
    }
    return false;
}

//Tested
bool QuadtreeArea::removeItem(QuadtreeItem* item){
    
    //Try the Item List
    if(containsItem(item))
    {   
        items->remove(item);
        return true;
    }
    
    //Rederict to areas;
    for (std::list<QuadtreeArea*>::iterator iterator = areas->begin(); iterator != areas->end(); ++iterator)
    { 
        if((*iterator)->canStoreItem(item))
            return (*iterator)->removeItem(item);
    }
    
    return false;
}

std::list<QuadtreeItem*>* QuadtreeArea::getPossibleNearItems(){
    std::list<QuadtreeItem*>* otherList;
    
    if(this->parent == 0)
        otherList = new std::list<QuadtreeItem*>;
    else
       otherList = this->parent->getPossibleNearItems();   
    
    for (std::list<QuadtreeItem*>::iterator itemIterator = items->begin(); itemIterator != items->end(); itemIterator++)
        otherList->push_front(*itemIterator);
    
    return otherList;
}

//Tested
void QuadtreeArea::splitArea(){
    if(isLeaf())
    {
        Vector newSize = rectangle.getSize() / 2;
        Vector o = rectangle.getPosition();
        
        areas = new std::list<QuadtreeArea*>();
        areas->push_front(new QuadtreeArea(this, Rectangle(o + Vector(0, 0), newSize)));                    //Links Oben
        areas->push_front(new QuadtreeArea(this, Rectangle(o + Vector(newSize.x, 0), newSize)));            //Rechts Oben
        areas->push_front(new QuadtreeArea(this, Rectangle(o + Vector(0, newSize.y), newSize)));            //Links Unten
        areas->push_front(new QuadtreeArea(this, Rectangle(o + Vector(newSize.x, newSize.y), newSize)));    //Rechts Unten
        
        //Add items to childs and remove them - if possible
        for (std::list<QuadtreeItem*>::iterator itemIterator = items->begin(); itemIterator != items->end(); itemIterator++)
        {   
            for (std::list<QuadtreeArea*>::iterator areaIterator = areas->begin(); areaIterator != areas->end(); areaIterator++)
            { 
                if((*areaIterator)->canStoreItem(*itemIterator))
                {
                    (*areaIterator)->addItem(*itemIterator);
                    items->erase(itemIterator);
                    itemIterator--;
                    break;
                }
            }
        }
    }
    else
    {
        //Exception. Can't split a already splitted area.   
        std::cout << "!! Cant split a already splitted area !!" << std::endl << std::endl;
    }
}

void QuadtreeArea::mergeArea(){
    //Todo, nice to have.
}

//Tested
int QuadtreeArea::getItemsCount(){
    if(isLeaf())
        return items->size();
    else
    {
        int childItems = 0;
        for (std::list<QuadtreeArea*>::iterator areaIterator = areas->begin(); areaIterator != areas->end(); areaIterator++)
        { 
            childItems += (*areaIterator)->getItemsCount();
        }
        return childItems;
    }
}

//Tested
bool QuadtreeArea::isLeaf(){
    return areas->empty();
}

//Tested
bool QuadtreeArea::canStoreItem(QuadtreeItem* item){
    return rectangle.fitsCircle(item->getCircle());
}

//Tested
void QuadtreeArea::onItemPositionChanged(QuadtreeItem* item){
    if(this->canStoreItem(item) == false)
    {
        items->remove(item);
        parent->addItem(item);
    }
}

//Tested
void QuadtreeArea::print(std::string prefix)
{
    std::string output = prefix + "Area: " + "Items: " + std::to_string(this->getItemsCount()) + " IsLeaf: " + (this->isLeaf() ? "True" : "False") + " - " + rectangle.toString() + "\n";
            
    for (std::list<QuadtreeItem*>::iterator itemIterator = items->begin(); itemIterator != items->end(); ++itemIterator)
    { 
        output += prefix + "-Item: " + (*itemIterator)->getCircle()->toString() + "\n";
    }
    
    std::cout << output << std::endl;
    
    for (std::list<QuadtreeArea*>::iterator areaIterator = areas->begin(); areaIterator != areas->end(); ++areaIterator)
    { 
        (*areaIterator)->print(prefix + "-");
    }
}

//Tested
void QuadtreeArea::print(){
    return print("");
}

#endif