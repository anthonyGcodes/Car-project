     #ifndef CARS_H
     #define CARS_H
     
     #include <iostream>
     #include <vector>
     #include <string>
     #include <typeinfo>
     #include <cmath>
     #include "car.h"
     #include "truck.h"
     #include "delivery.h"
     #include "factory.h"
    
    using namespace std;
    
    class Cars
    {
    
      public:
       Cars();
       int getTotalGears() const;
       int getTotalCapacity() const;
       void print( ostream &out = cout ) const;
       void read( string filename ); /*throw ( logic_error, invalid_argument )*/
       unsigned size() const;
       ~Cars();
   
      private:
        vector<Car *> cars;
    
    }; // Cars class
    
    #endif // Cars_H
    