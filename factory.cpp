#include "factory.h"

/* returns a pointer to a Car*/
Car* CarFactory::make (istream &in) //throw (invalid_argument)	
{

    Car *CarPtr = nullptr;
    char type;
    in >> type;
    if(in)
 {
        in.putback(type);
    switch (type)
    {
    case 'D':
        //make a delivery Car
        CarPtr = new Delivery();
        break;
    case 'U':
        //make an urban Car
        CarPtr = new Truck();
        break;
    default:
        throw invalid_argument ("Factory:: make : not urban or delivery");
    } // END switch
        CarPtr->read(in);
 } // END if
    return CarPtr;
}//END MAKE