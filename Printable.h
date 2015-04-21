#ifndef PRINTABLEHEADER
#define PRINTABLEHEADER

#include <string>

class Printable
{
    protected:
        std::string Name;
    
    public:
        Printable(std::string Name);
        Printable();
        virtual void print();
        virtual std::string toString() = 0;
    
    //Pure virtual (= 0) function -> Must be implemented by child
                                        
    //Virtual -> function CAN be overwritten
    
    //A function without body -> abstract. Can be instantiated,
    //but will throw a exception when called

    //Destructor of the child is only called, when it is marked virtual
};

#endif