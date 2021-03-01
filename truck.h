     #ifndef Truck_H
     #define Truck_H
     
     #include <iostream>
     #include <fstream>
     #include <string>
     #include "car.h"
     
     using namespace std;
    
    class Truck : public Car
    {
      public:
        Truck();
        Truck( string id, string name, int gears ); // throw ( invalid_argument )
        void setID( string id ); // throw ( invalid_argument )
        virtual void print( ostream &out = cout ) const;
        virtual void read( istream &in ); // throw ( invalid_argument )
    
    }; // Truck class
    
    #endif // Truck_H