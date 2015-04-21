#ifndef PRINTABLE
#define PRINTABLE

#include "Printable.h"

#include <iostream>
#include <string>

using namespace std;
    
Printable::Printable(string Name)
{
    this->Name = Name;
}

Printable::Printable()
{
    Name = "Unknown";   
}

void Printable::print()
{
    cout << Name << " " << toString() << endl;
}

#endif