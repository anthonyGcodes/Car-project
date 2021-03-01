#ifndef FACTORY_H
     #define FACTORY_H
     
     #include <iostream>
     #include <stdexcept>
     #include "car.h"
     #include "truck.h"
     #include "delivery.h"
     #include "cars.h"
    
    using namespace std;
    
    class CarFactory
    {
      friend class Cars;
    
      private:
        static Car* make( istream& in ) ; //throw ( invalid_argument );
    
    }; // CarFactory class
    
    #endif // FACTORY_H
    
