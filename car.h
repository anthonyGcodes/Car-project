     #ifndef Car_H
     #define Car_H
     
     #include <iostream>
     #include <fstream>
     #include <string>
     #include <stdexcept>
     #include <cctype>

     using namespace std;
    
    class Car
    {
      public:
        Car();
        Car( string id, string name, int gears ); //throw ( invalid_argument );
        void setID( string id ); //throw ( invalid_argument );
        void setName( string name );
        void setGears( int gears ); //throw ( invalid_argument );
        string getID() const;
        string getName() const;
        int getGears() const;
        virtual void print( ostream& out = cout ) const;
        virtual void read( istream& in ); //throw ( invalid_argument );
        virtual ~Car();
    
      protected:
        string id;
        string name;
        int gears;
    
    }; // Car class
    
    #endif // Car_H
    